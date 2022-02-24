#ifndef GAMELOOP_H_INCLUDED
#define GAMELOOP_H_INCLUDED


void gameloop(unsigned char grid[2*n+1][4*n+1],int L[2*n*(n+1)],int B[n*n],int newgame,turns trn[2*n*(n+1)] /*array of turns info*/ ) {
    clock_t s,e,t=0;    //to calculate time in game
    if(newgame)     //initializing elements of grid, lines and boxes by initial conditions when it is new game
    {
        for(i=0;i<2*n*(n+1);i++)    //initializing all lines by zero
        {
            L[i]=0;
        }
        for(i=0;i<n*n;i++)    //initializing all boxes by zero
        {
            B[i]=0;
        }
        for(i=0;i<2*n+1;i++)     //initializing grid by null character
        {
            for(j=0;j<4*n+1;j++)
            {
                grid[i][j]=255;
            }
        }
        for(i=0;i<n+1;i++)    //initializng dots places in the grid
        {
            for(j=0;j<n+1;j++)
            {
                grid[2*i][4*j]=254;
            }
        }
        for(i=0;i<2*n+1;i++)     //saving info of grid in the array of turns info
        {
            for(j=0;j<4*n+1;j++)
            {
                trn[turn].g[i][j]=grid[i][j];
            }
        }
        for(i=0;i<2*n*(n+1);i++) trn[turn].Lines[i]=L[i];     //saving info of lines in the array of turns info
        for(i=0;i<n*n;i++) trn[turn].Boxes[i]=B[i];      //saving info of boxes in the array of turns info
        trn[turn].p=player;      //saving whose player turn is in the array of turns info
        trn[turn].m1=moves1;      //saving info of moves and scores of each player in the array of turns info
        trn[turn].m2=moves2;
        trn[turn].s1=score1;
        trn[turn].s2=score2;
    }
    s=clock();     //the time before game starts

    start4:    //start from here after each turn until game ends
    for(i=0;i<2*n+1;i++)    //getting info of grid from array of turns info which points to the current turn
    {
        for(j=0;j<4*n+1;j++)
        {
            grid[i][j]=trn[turn].g[i][j];
        }
    }
    for(i=0;i<2*n*(n+1);i++) L[i]=trn[turn].Lines[i];    //getting info of lines from array of turns info which points to the current turn
    for(i=0;i<n*n;i++) B[i]=trn[turn].Boxes[i];     //getting info of boxes from array of turns info which points to the current turn
    player=trn[turn].p;     //getting info of whose player turn is from array of turns info which points to the current turn
    moves1=trn[turn].m1;    //getting info of moves and scores of each player from array of turns info which points to the current turn
    moves2=trn[turn].m2;
    score1=trn[turn].s1;
    score2=trn[turn].s2;
    if(error) printf(RED"WRONG SELECTION! choose again\n"reset);     //prints error message if input of dots is wrong
    else printf("\n");
    error=0;    //setting error to 0 at the beginning of each turn
    again=0;    //setting that player plays again to 0 at the beginning of each turn
    printf(RED"\nplayer one name: %s\n"reset,name1);
    if(bot) printf(BLU"player two name: computer\n"reset);
    else printf(BLU"player two name: %s\n"reset,name2);
    printgrid(grid,L,B);     //function to print grid with lines and boxes drawn
    int a,b,c,d;    //variables of coordinates of dots to be taken from user
    printf("\n");
    check=1;     //variable to check if all boxes are completed
    for(i=0;i<n*n;i++) check=check&&B[i];    //loop that returns check to 1 if all boxes are completed and returns check to 0 instead
    printdata(t);    //function to print data of each turn
    if(check) goto endgame;     //exit game loop and print results
    if(bot && player==2 && a==8)     //to undo the bot's move
    {
        system("cls");
        if(turn==0) error=1;    //prevent undo when it is at the beginning of the game
        else{turn--;undo++;}    //to increment the previous turn and increase the undos done
        goto start4;
    }
    else if(bot && player==2 && a==9)    //to redo the bot's move
    {
        system("cls");
        if(undo==0) error=1;    //prevent redo when there are no previous undos done
        else{turn++;undo--;}    //to increment the next turn and decrease undos done
        goto start4;
    }
    if(bot && player==2)    //to check if it is the bot's turn
    {
        botturn(L,grid);    //function of bot's move which chooses a random line
        goto skip1;     //to skip user's input in the bot's turn
    }
    printf(YEL"\nenter 7 to save");
    printf("\nenter 8 to undo");
    printf("\nenter 9 to redo");
    printf("\nenter 10 to exit game");
    printf("\nenter two rows numbers:"reset);
    scanf("%d",&a);    //reading row number of first dot or check if user wants to save, undo, redo or exit
    if(a==7)    //if input is 7 save game
    {
        save(trn);    //save function which saves the array of turns info
        goto start4;   //return to the start of the turn after saving
    }
    if(a==8)    //if input is 8 make undo
    {
        system("cls");
        if(turn==0) error=1;   //prevent undo when it is at the beginning of the game
        else{turn--;undo++;}   //to increment the previous turn and increase the undos done
        goto start4;
    }
    if(a==9)    //if input is 9 make redo
    {
        system("cls");
        if(undo==0) error=1;   //prevent redo when there are no previous undos done
        else{turn++;undo--;}   //to increment the next turn and decrease undos done
        goto start4;
    }
    if(a==10)      //if input is 10 exit
    {
        system("cls");
        return;
    }
    scanf("%d",&b);     //reading row number of second dot
    printf(YEL"enter two cols numbers:"reset);
    scanf("%d%d",&c,&d);     //reading columns numbers of first and second dot
    getchar();
    selectline(a,b,c,d,grid,L);     //function which draws line at the desired place in grid according to user's inputs and returns error to 1 if inputs are wrong
    skip1:    //start from here when it is the bot's turn
    checkbox(grid,L,B);    //function which check if there are completed boxes or not and makes player play again if he completed one
    system("cls");
    if(!error){turn++;undo=0;}    //switching to the next turn and prevent making redo if there are no errors
    if(!error && !again) player=player%2+1;     //switching turns between players if there are no errors and player will not play again
    for(i=0;i<2*n+1;i++)      //saving info of grid in the array of turns info
    {
        for(j=0;j<4*n+1;j++)
        {
            trn[turn].g[i][j]=grid[i][j];
        }
    }
    for(i=0;i<2*n*(n+1);i++) trn[turn].Lines[i]=L[i];      //saving info of lines in the array of turns info
    for(i=0;i<n*n;i++) trn[turn].Boxes[i]=B[i];       //saving info of boxes in the array of turns info
    trn[turn].p=player;       //saving whose player turn is in the array of turns info
    trn[turn].m1=moves1;       //saving info of moves and scores of each player in the array of turns info
    trn[turn].m2=moves2;
    trn[turn].s1=score1;
    trn[turn].s2=score2;
    e=clock();     //time at end of each turn
    t=(e-s)/CLOCKS_PER_SEC;      //the time difference in seconds between end of each turn and start of the game
    goto start4;     //return to the beginning of the game loop
    endgame:     //start from here when all boxes are completed
    results();    //function which prints the results and top ten
}


#endif // GAMELOOP_H_INCLUDED

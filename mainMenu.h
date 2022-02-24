#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED

//initializing global variables to be used among different functions
int n;    //variable that stores number of boxes
int i,j,k;    //used as index in for loops
int error;    //to check if the user's input wrong
int again;    //to check if the player will play again when completing a box
int player;    //variable that stores whose player turn is
int moves1, moves2, score1, score2;    //variables to store the moves and the scores for each player
int check;    //variable that checks if all boxes are completed to end the game
int turn;    //variable to store the number of the current turn and is used to undo and redo
int undo;    //variable to check how many undos are done so that redo can be the reverse of it to prevent errors in redo
int bot;    //to check if the game is two players or one player vs bot
char name1[20],name2[20];   //array of characters to store names of players
top_ten top_players[10];   //array of struct that stores names and scores of top ten players


void mainMenu() {
    system("");
    int e1,e2;     //variables to store inputs of the user
    start1:     //start from here when first input is wrong
    error=0; again=0; player=1; moves1=0; moves2=0; score1=0; score2=0; turn=0; undo=0;    //assign the variables with their initial values
    printf(YEL"\nenter 1 to start game\n");
    printf("enter 2 to load game\n");
    printf("enter 3 to show top 10 players\n");
    printf("enter 4 to exit\n"reset);
    scanf("%d",&e1);
    system("cls");
    if(e1==1)
    {
        system("cls");
        start2:     //start from here when second input is wrong
        printf(YEL"\nenter 1 for one player\n");
        printf("enter 2 for two players\n"reset);
        scanf("%d",&e2);
        if(e2==1)     //vs computer mode
        {
            bot=1;    //give bot value 1 to indicate that the second player is computer
            printf(CYN"\nenter your name: "reset);    //asking user to enter his name
            scanf("%s",name1);
        }
        else if(e2==2)   //2 players mode
        {
            bot=0;    //give bot value 0 to indicate that the second player is not computer
            printf(CYN"\nenter player one's name: "reset);     //asking users to enter their names
            scanf("%s",name1);
            printf(CYN"\nenter player two's name: "reset);
            scanf("%s",name2);
        }
        else    //when second input is wrong
        {
            getchar();
            system("cls");
            printf(RED"WRONG SELECTION! choose again"reset);
            goto start2;
        }
        system("cls");
        start3:     //start from here when third input is wrong
        printf(YEL"\nenter 1 for easy\n");
        printf("enter 2 for medium\n");
        printf("enter 3 for hard\n");
        printf("enter 4 for expert\n"reset);
        scanf("%d",&n);
        getchar();
        if(!(n==1 || n==2 || n==3 || n==4))    //when third input is wrong
        {
            system("cls");
            printf(RED"WRONG SELECTION! choose again"reset);
            goto start3;
        }
        n++;   //to validate number of boxes
        turns trn[2*n*(n+1)];    //initializing array of struct -with size of number of turns- that stores all info about each turn to be used in undo and redo
        unsigned char grid[2*n+1][4*n+1];    //two dimensional array of grid
        int L[2*n*(n+1)];    //array of lines
        int B[n*n];    //array of boxes
        system("cls");
        gameloop(grid,L,B,1,trn);     //function which loops the game until end
    }
    else if(e1==2)     //go to loaded game
    {
        load();    //function that loads previous saved game
    }
    else if(e1==3)    //see top ranks
    {
        system("cls");
        loadtopten();    //function that loads top ten from saved file
        sortrank();     //function that sorts top ten
        for(i=0;i<10;i++) printf(CYN"Rank %d: %s score: %d\n\n"reset,i+1,top_players[i].N,top_players[i].S);     //loop to print top ten players
        printf(YEL"\n\npress enter to return to main menu\n"reset);
        getch();
        system("cls");
    }
    else if(e1==4)     //exits program
    {
        return;
    }
    else    //when first input is wrong
    {
        getchar();
        system("cls");
        printf(RED"WRONG SELECTION! choose again"reset);
        goto start1;
    }
    goto start1;     //to return to main menu after the game end
}

#endif // MAINMENU_H_INCLUDED

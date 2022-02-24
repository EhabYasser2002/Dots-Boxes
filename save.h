#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED

void save(turns trn[2*n*(n+1)]) {
    start5:  //start from here when input of file number is wrong
    printf(YEL"\nenter file number 1 or 2 or 3:\n"reset);
    int f;     //variable to store the number of file in which the game should be saved
    scanf("%d",&f);
    FILE *save;
    if(f==1) save=fopen("game1.bin","wb");    //save in first file
    else if(f==2) save=fopen("game2.bin","wb");    //save in second file
    else if(f==3) save=fopen("game3.bin","wb");    //save in third file
    else    //when user's input is wrong
    {
        system("cls");
        printf(RED"WRONG SELECTION! choose again"reset);
        goto start5;
    }
    fprintf(save,"%d %d %d",n,bot,turn);    //saving number of boxes, bot value and number of turns played until save
    for(i=0;i<=turn;i++)    //loop to access each turn in array of structures of turns info
    {
        for(j=0;j<2*n+1;j++)   //nested loop to save info of grid of each turn in the file
        {
            for(k=0;k<4*n+1;k++)
            {
                fprintf(save,"%c",trn[i].g[j][k]);
            }
        }
        for(j=0;j<2*n*(n+1);j++) fprintf(save,"%d",trn[i].Lines[j]);   //loop to save info of lines of each turn in the file
        for(j=0;j<n*n;j++) fprintf(save,"%d",trn[i].Boxes[j]);     //loop to save info of boxes of each turn in the file
        fprintf(save,"%d %d %d %d %d",trn[i].p,trn[i].m1,trn[i].m2,trn[i].s1,trn[i].s2);     //saving info of each turn (whose player turn is, moves and scores of each player)
    }
    fprintf(save," %s",name1);   //saving name of first player
    if(!bot) fprintf(save," %s",name2);    //saving name of second player if he is not a bot
    fclose(save);
    system("cls");
    if(f==1) printf(CYN"saved successfully to game1"reset);
    else if(f==2) printf(CYN"saved successfully to game2"reset);
    else if(f==3) printf(CYN"saved successfully to game3"reset);
}

#endif // SAVE_H_INCLUDED

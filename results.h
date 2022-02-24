#ifndef RESULTS_H_INCLUDED
#define RESULTS_H_INCLUDED

void results() {
    loadtopten();    //function to load names and scores of top ten players in the array of structers (top_players)
    if(score1>score2)    //if player one wins
    {
        printf(RED"%s wins\n\n\n"reset,name1);   //printing the name of the winner
        for(i=0;i<10;i++)    //loop to access all names of top ten players to check if this player is recorded before
        {
            if(strcmp(name1,top_players[i].N)==0)    //compare the name of the winner with all names of top ten players
            {
                if(score1>top_players[i].S)    //if his name is found then checking if current score is bigger than previous score to save it
                {
                    top_players[i].S=score1;
                    strcpy(top_players[i].N,name1);
                }
                goto skip2;    //skip to printing the top ten directly
            }
        }
        for(i=0;i<10;i++)    //loop to check if the players saved are less than ten so the winner takes first empty place without conditions
        {
            if(top_players[i].S==0)
            {
                top_players[i].S=score1;
                strcpy(top_players[i].N,name1);
                goto skip2;   //skip to printing the top ten directly
            }
        }
        if(score1>top_players[9].S)   //check if the score of the winner is bigger than the final player of the top ten players to take his place
        {
            top_players[9].S=score1;
            strcpy(top_players[9].N,name1);
            goto skip2;    //skip to printing the top ten directly
        }
    }
    else if(score1<score2)    //if player two wins
    {
        if(bot)   //if player two was bot skip to printing top ten directly without taking his rank into consideration
        {
            printf(BLU"the bot wins\n\n\n"reset);    //printing the name of the winner
            goto skip2;
        }
        printf(BLU"%s wins\n\n\n"reset,name2);     //printing the name of the winner
        for(i=0;i<10;i++)   //loop to access all names of top ten players to check if this player is recorded before
        {
            if(strcmp(name2,top_players[i].N)==0)    //compare the name of the winner with all names of top ten players
            {
                if(score2>top_players[i].S)    //if his name is found then checking if current score is bigger than previous score to save it
                {
                    top_players[i].S=score2;
                    strcpy(top_players[i].N,name2);
                }
                goto skip2;    //skip to printing the top ten directly
            }
        }
        for(i=0;i<10;i++)   //loop to check if the players saved are less than ten so the winner takes first empty place without conditions
        {
            if(top_players[i].S==0)
            {
                top_players[i].S=score2;
                strcpy(top_players[i].N,name2);
                goto skip2;    //skip to printing the top ten directly
            }
        }
        if(score2>top_players[9].S)    //check if the score of the winner is bigger than the final player of the top ten players to take his place
        {
            top_players[9].S=score2;
            strcpy(top_players[9].N,name2);
            goto skip2;    //skip to printing the top ten directly
        }
    }
    else printf(YEL"DRAW!\n\n\n"reset);    //when two scores are equal
    skip2:   //start from here to print top ten directly
    sortrank();    //function used to sort the top ten players before printing and saving the new one
    for(i=0;i<10;i++) printf(CYN"Rank %d: %s score: %d\n\n"reset,i+1,top_players[i].N,top_players[i].S);    //loop to print top ten players
    savetopten();    //function to save sorted top ten players
    printf(YEL"\n\npress enter to return to main menu\n"reset);
    getch();
    system("cls");
}

#endif // RESULTS_H_INCLUDED

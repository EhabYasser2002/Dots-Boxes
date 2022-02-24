#ifndef SORTRANK_H_INCLUDED
#define SORTRANK_H_INCLUDED


void sortrank() {     //sorting top ten players in descending order
    for(i=9;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(top_players[j].S<top_players[j+1].S)
            {
                int tmp;   //used to store temporary score while switching
                char temp[20];    //used to store temporary name while switching
                tmp=top_players[j].S;      //switching scores
                top_players[j].S=top_players[j+1].S;
                top_players[j+1].S=tmp;
                strcpy(temp,top_players[j].N);     //switching names
                strcpy(top_players[j].N,top_players[j+1].N);
                strcpy(top_players[j+1].N,temp);
            }
        }
    }
}

#endif // SORTRANK_H_INCLUDED

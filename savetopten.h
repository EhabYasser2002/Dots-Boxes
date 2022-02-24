#ifndef SAVETOPTEN_H_INCLUDED
#define SAVETOPTEN_H_INCLUDED

void savetopten() {      //saving name and score of each player of the top ten players
    FILE *top;
    top=fopen("topten.bin","wb");
    for(i=0;i<10;i++)
    {
        if(top_players[i].S==0) break;
        fprintf(top,"%s %d\n",top_players[i].N,top_players[i].S);
    }
    fclose(top);
}

#endif // SAVETOPTEN_H_INCLUDED

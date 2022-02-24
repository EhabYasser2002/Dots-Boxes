#ifndef LOADTOPTEN_H_INCLUDED
#define LOADTOPTEN_H_INCLUDED

void loadtopten() {       //loading name and score of each player of the top ten players
    FILE *top;
    top=fopen("topten.bin","r");
    for(i=0;i<10;i++) fscanf(top,"%s%d",top_players[i].N,&top_players[i].S);
    fclose(top);
}

#endif // LOADTOPTEN_H_INCLUDED

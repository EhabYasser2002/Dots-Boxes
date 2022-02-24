#ifndef PRINTDATA_H_INCLUDED
#define PRINTDATA_H_INCLUDED

void printdata(int t) {
    if(player==1 && !check) printf(RED"Player one's turn:"reset);    //this line will not be printed when game is finished
    else if(player==2 && !check) printf(BLU"player two's turn: "reset);
    else printf("                   ");
    printf(RED"\t\t\tmoves of player one: %d"reset,moves1);    //these lines will be printed during game and when game is finished
    printf(BLU"\t\tmoves of player two: %d\n"reset,moves2);
    printf(RED"  \t\t\t\t\tscore of player one: %d"reset,score1);
    printf(BLU"\t\tscore of player two: %d\n"reset,score2);
    printf(RED"  \t\t\t\t\tremaining lines: %d"reset,2*n*(n+1)-moves1-moves2);
    printf(BLU"\t\ttime: %d:%d\n"reset,t/60,t%60);
}

#endif // PRINTDATA_H_INCLUDED

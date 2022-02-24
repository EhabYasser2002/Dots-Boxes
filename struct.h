#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct turns{     //data type of structure which stores grid, lines, boxes, player turn, moves and scores of each player
    unsigned char g[11][21];     //two dimensional array used to store grid elements in each turn
    int Lines[60];     //array used to store values of all lines in each turn
    int Boxes[25];     //array used to store values of all boxes in each turn
    int p;      //variable used to store whose player turn in each turn
    int m1;      //variables used to store moves and scores of each player in each turn
    int m2;
    int s1;
    int s2;
}turns;

typedef struct top_ten{    //data type of structure which stores name and score of each one of top ten players
    char N[20];     //used to store name of each player of top ten players
    int S;        //used to store score of each player of top ten players
}top_ten;

#endif // STRUCT_H_INCLUDED

#ifndef PRINTGRID_H_INCLUDED
#define PRINTGRID_H_INCLUDED

void printgrid(unsigned char grid[2*n+1][4*n+1],int L[2*n*(n+1)],int B[n*n]) {
    int counter=1;    //variable used to print number of rows beside each row
    printf("\t\t\t\t\t\t  ");
    for(i=1;i<=n+1;i++) printf(BCYN"%d   "reset,i);    //to print number of columns above each column
    printf("\n\t\t\t\t\t\t");

    //nested loop to access all elements in grid
    for(i=0;i<2*n+1;i++)     //indexing all row in grid
    {   if(i%2==0){printf(BCYN"%d "reset,counter); counter++;}    //print number of rows beside each row
        else printf("  ");
        for(j=0;j<4*n+1;j++)     //indexing all columns in grid
        {
            if(grid[i][j]==196)    //check if this element is horizontal line or not
            {    //check if line is drawn by player one or two to print its colour
                if(L[n*(i/2)+j/4]==1) printf(RED"%c"reset,grid[i][j]);
                else if(L[n*(i/2)+j/4]==2) printf(BLU"%c"reset,grid[i][j]);
            }
            else if(grid[i][j]==179)      //check if this element is vertical line or not
            {    //check if line is drawn by player one or two to print its colour
                if(L[n*(n+1+j/4)+i/2]==1) printf(RED"%c"reset,grid[i][j]);
                else if(L[n*(n+1+j/4)+i/2]==2) printf(BLU"%c"reset,grid[i][j]);
            }
            else if(grid[i][j]==219 && B[n*(i/2)+j/4]==1)    //check if this element is box and drawn by player one
            {
                printf(REDB" "reset);     //printing space with background colour of player to give the shape of coloured box
            }
            else if(grid[i][j]==1 && B[n*(i/2)+j/4]==1)
            {
                printf(REDB"%d"reset,grid[i][j]);     //printing player's number in the middle of the box
            }
            else if(grid[i][j]==219 && B[n*(i/2)+j/4]==2)    //check if this element is box and drawn by player one
            {
                printf(BLUB" "reset);    //printing space with background colour of player to give the shape of coloured box
            }
            else if(grid[i][j]==2 && B[n*(i/2)+j/4]==2)
            {
                printf(BLUB"%d"reset,grid[i][j]);     //printing player's number in the middle of the box
            }
            else printf(YEL"%c"reset,grid[i][j]);     //print the main element in grid without colour if it is not a line or a box
        }
        printf("\n");     //printing new line at end of each row
        printf("\t\t\t\t\t\t");
    }
}

#endif // PRINTGRID_H_INCLUDED

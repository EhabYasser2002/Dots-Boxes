#ifndef SELECTLINE_H_INCLUDED
#define SELECTLINE_H_INCLUDED

void selectline(int a,int b,int c,int d,unsigned char grid[2*n+1][4*n+1],int L[2*n*(n+1)]) {
    if(a==b && a<=n+1)    //if the line is horizontal (when first two inputs are equal)
    {
        if(abs(c-d)==1 && c<=n+1 && d<=n+1)   //to check if the difference between two columns' numbers is 1 and in range of grid
        {
            if(c>d) c=d;    //make c is the smaller column number always to reach desired line easily according to its value
            if(L[n*(a-1)+c-1]==0)   //relation to reach corresponding horizontal line according to user's inputs
            {
                grid[2*(a-1)][4*c-3]=196;    //relations to reach desired three places of the horizontal line in grid to give them the character (-)
                grid[2*(a-1)][4*c-2]=196;
                grid[2*(a-1)][4*c-1]=196;
                L[n*(a-1)+c-1]=player;    //give the choosen line the value of the player drawn it to be printed by its colour while printing grid
                if(player==1) moves1++;   //increase moves of this player by one
                else moves2++;
            }
            else error=1;    //error if the line is already drawn
        }
        else error=1;    //error if difference between two columns' numbers is not 1 or columns number are out of range of grid
    }
    else if(c==d && c<=n+1)   //if the line is vertical (when last two inputs are equal)
    {
        if(abs(a-b)==1 && a<=n+1 && b<=n+1)    //to check if the difference between two rows' numbers is 1 and in range of grid
            {
            if(a>b) a=b;     //make a is the smaller row number always to reach desired line easily according to its value
            if(L[n*(c+n)+a-1]==0)   //relation to reach corresponding vertical line according to user's inputs
            {
                grid[2*a-1][4*(c-1)]=179;   //relation to reach desired place of the vertical line in grid to give it the character (|)
                L[n*(c+n)+a-1]=player;    //give the choosen line the value of the player drawn it to be printed by its colour while printing grid
                if(player==1) moves1++;   //increase moves of this player by one
                else moves2++;
            }
            else error=1;    //error if the line is already drawn
        }
        else error=1;    //error if difference between two rows' numbers is not 1 or rows number are out of range of grid
    }
    else error=1;    //error if the first two inputs are not equal and the last two inputs are not equal
}

#endif // SELECTLINE_H_INCLUDED

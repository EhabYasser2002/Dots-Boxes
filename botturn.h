#ifndef BOTTURN_H_INCLUDED
#define BOTTURN_H_INCLUDED


void botturn(int L[2*n*(n+1)],unsigned char grid[2*n+1][4*n+1]) {
    for(i=0;i<2*n*(n+1);i++)
    {
        if(L[i]==0)    //loop checks the first empty line in the array and choose it
        {
            L[i]=2;    //giving line that line value 2 to point that player two has drawn it
            moves2++;    //increasing moves of player 2
            if(i<n*(n+1))    //if the line is horizontal
            {
                grid[2*(i/n)][4*(i-n*(i/n))+1]=196;   //switching values of three spaces to (-) to give the shape of horizontal line
                grid[2*(i/n)][4*(i-n*(i/n))+2]=196;
                grid[2*(i/n)][4*(i-n*(i/n))+3]=196;
                break;
            }
            else if(i>=n*(n+1))   //if the line is vertical
            {
                grid[2*(i%n)+1][4*((i-n*(n+1))/n)]=179;   //switching value of the space to (|) to give the shape of vertical line
                break;
            }
        }
    }
}
#endif // BOTTURN_H_INCLUDED

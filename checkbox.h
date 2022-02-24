#ifndef CHECKBOX_H_INCLUDED
#define CHECKBOX_H_INCLUDED

void checkbox(unsigned char grid[2*n+1][4*n+1],int L[2*n*(n+1)],int B[n*n]) {
    for(i=0;i<n*n;i++)   //loop to reach all boxes
    {
        if(L[i] && L[i+n] && L[n*(n+1+i-n*(i/n))+i/n] && L[n*(n+2+i-n*(i/n))+i/n] && B[i]==0)      //relations that connects each box with the 4 lines around it to check if box is completed or not and also checks if box is not completed before
        {
            grid[2*(i/n)+1][4*(i-n*(i/n))+1]=219;      //relations that reach to the three elements of the completed box in the grid to change it's value
            grid[2*(i/n)+1][4*(i-n*(i/n))+2]=player;     //assigning the middle element in the box with the player number to give it a better appearance in printing
            grid[2*(i/n)+1][4*(i-n*(i/n))+3]=219;
            B[i]=player;     //give the completed box the number of the player to be printed by his colour
            if(player==1) score1++;    //increase the score of the player that completed the box
            else if(player==2) score2++;
            again=1;    //variable to make the player completed the box play another turn
        }
    }
}

#endif // CHECKBOX_H_INCLUDED

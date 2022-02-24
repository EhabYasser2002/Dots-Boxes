#ifndef LOAD_H_INCLUDED
#define LOAD_H_INCLUDED

void load() {
    start6:    //start from here when input of file number is wrong
    printf(YEL"\nenter the file number 1 or 2 or 3:\n");
    printf("enter 4 to return to main menu:\n"reset);
    int l;    //variable to store number of file to load from
    scanf("%d",&l);
    if(l==1)    //load from first file
    {
        FILE *save;
        save=fopen("game1.bin","rb");
        if(save==NULL)     //if the file is not yet exist
        {
            system("cls");
            printf(RED"FILE SELEECTED IS NOT FOUND! choose again"reset);
            goto start6;
        }
        fscanf(save,"%d%d%d",&n,&bot,&turn);     //reading saved info with the same sequence
        turns trn[2*n*(n+1)];
        unsigned char grid[2*n+1][4*n+1];     //initializing the grid, lines and boxes arrays depending on the value (n) which is restored from saved file
        int L[2*n*(n+1)];
        int B[n*n];
        for(i=0;i<=turn;i++)
        {
            for(j=0;j<2*n+1;j++)
            {
                for(k=0;k<4*n+1;k++)
                {
                    fscanf(save,"%c",&trn[i].g[j][k]);
                }
            }
            for(j=0;j<2*n*(n+1);j++) fscanf(save,"%1d",&trn[i].Lines[j]);
            for(j=0;j<n*n;j++) fscanf(save,"%1d",&trn[i].Boxes[j]);
            fscanf(save,"%d%d%d%d%d",&trn[i].p,&trn[i].m1,&trn[i].m2,&trn[i].s1,&trn[i].s2);
        }
        fscanf(save,"%s",name1);
        if(!bot) fscanf(save,"%s",name2);
        fclose(save);
        system("cls");
        gameloop(grid,L,B,0,trn);    //go to game loop after loading needed data
    }
    else if(l==2)     //load from second file
    {
        FILE *save;
        save=fopen("game2.bin","rb");
        if(save==NULL)
        {
            system("cls");
            printf(RED"FILE SELEECTED IS NOT FOUND! choose again"reset);
            goto start6;
        }
        fscanf(save,"%d%d%d",&n,&bot,&turn);
        turns trn[2*n*(n+1)];
        unsigned char grid[2*n+1][4*n+1];
        int L[2*n*(n+1)];
        int B[n*n];
        for(i=0;i<=turn;i++)
        {
            for(j=0;j<2*n+1;j++)
            {
                for(k=0;k<4*n+1;k++)
                {
                    fscanf(save,"%c",&trn[i].g[j][k]);
                }
            }
            for(j=0;j<2*n*(n+1);j++) fscanf(save,"%1d",&trn[i].Lines[j]);
            for(j=0;j<n*n;j++) fscanf(save,"%1d",&trn[i].Boxes[j]);
            fscanf(save,"%d%d%d%d%d",&trn[i].p,&trn[i].m1,&trn[i].m2,&trn[i].s1,&trn[i].s2);
        }
        fscanf(save,"%s",name1);
        if(!bot) fscanf(save,"%s",name2);
        fclose(save);
        system("cls");
        gameloop(grid,L,B,0,trn);
    }
    else if(l==3)    //load from third file
    {
        FILE *save;
        save=fopen("game3.bin","rb");
        if(save==NULL)
        {
            system("cls");
            printf(RED"FILE SELEECTED IS NOT FOUND! choose again"reset);
            goto start6;
        }
        fscanf(save,"%d%d%d",&n,&bot,&turn);
        turns trn[2*n*(n+1)];
        unsigned char grid[2*n+1][4*n+1];
        int L[2*n*(n+1)];
        int B[n*n];
        for(i=0;i<=turn;i++)
        {
            for(j=0;j<2*n+1;j++)
            {
                for(k=0;k<4*n+1;k++)
                {
                    fscanf(save,"%c",&trn[i].g[j][k]);
                }
            }
            for(j=0;j<2*n*(n+1);j++) fscanf(save,"%1d",&trn[i].Lines[j]);
            for(j=0;j<n*n;j++) fscanf(save,"%1d",&trn[i].Boxes[j]);
            fscanf(save,"%d%d%d%d%d",&trn[i].p,&trn[i].m1,&trn[i].m2,&trn[i].s1,&trn[i].s2);
        }
        fscanf(save,"%s",name1);
        if(!bot) fscanf(save,"%s",name2);
        fclose(save);
        system("cls");
        gameloop(grid,L,B,0,trn);
    }
    else if(l==4)     //to return to main menu
    {
        system("cls");
        return;
    }
    else      //when user's input is wrong
    {
        system("cls");
        printf(RED"WRONG SELECTION! choose agian"reset);
        goto start6;
    }
}

#endif // LOAD_H_INCLUDED

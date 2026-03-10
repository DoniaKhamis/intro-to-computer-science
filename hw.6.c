/******************************************** *
Student One (Donia Khamis + 212794630)
Student Two (Mohammad Diab + 212720841)
Assignment number:6
********************************************/
#include <stdio.h>
#include <stdlib.h>

/* helper functions' declarations */
void printUniverse(char**,int);
void nextGeneration(char**,char***,int);
void applyChanges(char**,int,int);
void freeUniverse(char**,int);
int uniMalloc(char***,int);

int main()
{
    int generations,i,j,dim;
    char **universe,checkChar;
    /*receive & check the number of generations*/
    printf("Enter number of generations: ");
    if(scanf("%d", &generations)<1)
        {
            printf("Input error");
            return 1;
        }
    if(generations<0)
        {
            printf("Input error");
            return 1;
        }
    /*receive &check the dimension*/
    printf("Enter world dimension: ");
    if(scanf("%d", &dim)<1)
        {
            printf("Input error");
            return 1;
        }
    if(dim<1)
        {
            printf("Input error");
            return 1;
        }
    getchar();/*for the Enter*/
    /*make and fill the universe*/
    if(uniMalloc(&universe,dim)==1)
        return 1;
    printf("Enter first generation: ");
    for(i=0; i<dim; i++)
       {
         for(j=0; j<dim; j++)
         {
            if(scanf("%c", &checkChar)<1)
                {
                    printf("Input error");
                    return 1;
                }
             /*check the char received*/
             if(checkChar=='D' || checkChar=='B' || checkChar=='N')
                universe[i][j]=checkChar;
             else
                {
                    printf("Input error");
                    return 1;
                }
         }
       }
    /*printing the first generation universe*/
    printUniverse(universe,dim);
    /*send the first generation universe to the next generation*/
    applyChanges(universe,dim,generations);
    /*freeing the matrix's memory  we used*/
    freeUniverse(universe,dim);
    return 0;
}


/*HELPER FUNCTION : moves the universe to the next generation and prints*/
void applyChanges(char **Uni, int d, int rounds)
{
    char **change;
    int i;
    /*make the helper matrix*/
    if(uniMalloc(&change, d)==1)
        return;
    /*move generations for rounds time - using two matrices*/
    for(i=0; i<(rounds-1); i++)
    {
        if(i%2 == 0)/*Uni is this generation's universe*/
        {
            nextGeneration(Uni,&change,d);
            printUniverse(change,d);
        }
        else/*change is this generation's universe*/
        {
            nextGeneration(change,&Uni,d);
            printUniverse(Uni,d);
        }
    }
    /*freeing the helper matrix's memory we used*/
    freeUniverse(change,d);
}

/*HELPER FUNCTION : does the changes on a universe*/
void nextGeneration (char **Uni, char ***change, int d)
{
    int i, j, m,n ,counter;
    for (i=0; i<d; i++)
    {
        for(j=0; j<d; j++)
        {
            switch(Uni[i][j])
            {
            case 'D':
                {
                    (*change)[i][j]='N';/*apply proper change into the change matrix*/
                    break;
                }
            case 'N':
                {
                    counter=0;
                    /*count the times a B shows up beside the current N*/
                    for(n=-1; n<2; n+=2)
                    {
                        if(n+i<d && n+i>=0)
                        {
                            if(Uni[n+i][j]=='B')
                            {counter++;}
                        }
                        if(n+j<d && n+j>=0)
                        {
                            if(Uni[i][j+n]=='B')
                            {counter++;}
                        }
                    }
                    /*check the condition*/
                    if(counter>0)
                    {
                        /*apply proper change into the change matrix*/
                        (*change)[i][j]='B';
                        break;
                    }
                    else
                    {
                        /*place the char into the change matrix*/
                        (*change)[i][j]='N';
                        break;
                    }
                }
            case 'B':
                {
                counter=0;
                /*counting the times a B shows up around the current B*/
                for(n=-1; n<2 ; n++)
                    {
                        for(m=-1; m<2; m++)
                        {
                            if(i+n>=0 && j+m>=0 && i+n<d && j+m<d)
                                {
                                    if(n!=0 || m!=0)/*don't count the current B itself*/
                                    {
                                        if(Uni[i+n][j+m]=='B')counter++;
                                    }
                                }
                        }
                    }
                /*check the condition*/
                if(counter<3)
                    {
                    /*apply proper change into the change matrix*/
                    (*change)[i][j]='D';
                    break;
                    }
                else
                    {
                    /*place the char into the change matrix*/
                    (*change)[i][j]='B';
                    break;
                    }
                }
            }
        }
    }
}

/*HELPER FUNCTION : prints an array to the screen while considering the dimensions of the array*/
void printUniverse (char **Matt, int dim)
{
    int i,j;
    for(i=0; i<dim; i++)
    {
        printf("\n");
        for(j=0; j<dim; j++)
        {
            printf("%c", Matt[i][j]);
        }
    }
    printf("\n");
}

/*HELPER FUNCTION : frees a matrix*/
void freeUniverse(char **Matt, int d)
{
    int i=0;
    while(i<d)
        free(Matt[i++]);
    free(Matt);
}

/*HELPER FUNCTION : creates a universe with the received dimensions*/
int uniMalloc(char ***universe, int dim)
{
    int i;
    if(((*universe)=(char**)malloc(dim * sizeof(char*))) == NULL)
        {
            printf("Memory error!");
            return 1;
        }
    for(i=0; i<dim; i++)
    {
        if(((*universe)[i]=(char*)malloc(dim * sizeof(char))) == NULL)
            {
                printf("Memory error!");
                freeUniverse(*universe,dim);/*freeing the memory allocated until now*/
                return 1;
            }
    }
    return 0;
}

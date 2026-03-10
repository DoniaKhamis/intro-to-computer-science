/******************************************** *
Student One (Donia Khamis + 212794630)
Student Two (Mohammad Diab + 212720841)
Assignment number:5
********************************************/
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 30

/* Declerations */
void get_remove(int*);
void play_game(int, char**);
int numOfPlayers (char**);

int main()
{
    char* players [LENGTH]= {"a","b", "c", "d", "e", "f"
                            };
    int remove, i;
    get_remove(&remove);
    play_game(remove-1,players);
    printf("The players order after playing the game is: \n");
    for(i=0; i<LENGTH-1; i++)
    {
        printf("%s, ",players[i]);
    }
    printf("%s.\n",players[LENGTH-1]);
    return 0;
}

void get_remove(int* remove)
{
    printf("Enter the remove number: ");
    if (scanf("%d", remove)<1 || (*remove)<=0)
    {
        printf("Input error\n");
        exit(1);
    }
}
/*this function performs the game*/
void play_game(int remove, char ** players)
{
    int len = numOfPlayers(players), firstPlayer=0;
    char **loser, **lastPlace, *tmp;
    lastPlace = players+(len-1);

    while(1 < len)/*there are still more than one player in the round*/
    {
        firstPlayer = (remove+firstPlayer)%len;/*calculate the index of the loser*/
        loser = (players+firstPlayer);/*place the loser in a pinter*/
        /*swap until the end of the current circle line - in order to put the loser at the last place*/
        while(loser != lastPlace)
        {
            tmp = *loser;
            *loser = *(loser+1);
            *(loser+1) = tmp;
            /*updating the loser's pointer*/
            loser = (loser+1);
        }
        /*update pointer and number of players for the next round*/
        lastPlace = (lastPlace-1);
        len--;
    }
}
/*this function counts how many players are in the first round of the game*/
int numOfPlayers (char** player)
{
    int i, counter=0;
    char** pointer;
    pointer = player;
    for(i=0; i<LENGTH; i++)/*counting the times a sting shows up in the array*/
    {
        if(*pointer!=NULL)
            counter++;
        pointer++;
    }
    return counter;
}

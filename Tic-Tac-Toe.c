
#include <stdio.h>
/*
y x   1   2  3
1
2
3
1,2
1,3
1,2
2,1
3,4
4,3
0,3
*/
int x, y, num;
int currentplayer = 1;
int a[3][3] = {0};
int gameState();
int currentRowState(int x,int y,int z);
void pad();
void readPosition();
int main()
{
    int status;
    printf("\n\n");
    printf("*********************************************\n\n");
    printf("       WELCOME TO THE MOST PLAYED GAME      ");
    printf("\n\n");
    printf("*********************************************");
    printf("\n\n");
    printf("                 TIC-TAC-TOE     ");
    printf("\n");
    printf("      =================================");
    printf("\n\n");
    pad();
    while (1)
    {
        readPosition();
        a[y - 1][x - 1] = currentplayer;
        pad();
        currentplayer = 3 - currentplayer;
        status =  gameState();
        if (status == 1) // if status =1 then it will print Player1 wins the game  ..
        {
            printf("Player1 wins ");
            return 0;
        }
        if (status == 2) // if status =2 then it will print Player2 wins the game  ..
        {
            printf("Player2 wins ");
            return 0;
        }
         if (status == 3) // if status =3 Game will be draw  ..
        {
            printf("Game Drawn");
            return 0;
        }
    }
}

int gameState()
{
    /*
    0,0  0,1    0,2
    1,0  1,1    1,2
    2,0  2,1    2,2

    0-Continue
    1-Player 1 wins
    2-Player 2 wins
    3-Game Blocked

    */
    int linesblocked = 0;
    int result;

    result = currentRowState(a[0][0], a[0][1], a[0][2]);
    if (result == 1)
        return 1;
    if (result == 2)
        return 2;
    if (result == 3)
        linesblocked++;

    result = currentRowState(a[1][0], a[1][1], a[1][2]);
    if (result == 1)
        return 1;
    if (result == 2)
        return 2;
    if (result == 3)
        linesblocked++;

    result = currentRowState(a[2][0], a[2][1], a[2][2]);

    if (result == 1)
        return 1;
    if (result == 2)
        return 2;
    if (result == 3)
        linesblocked++;

    result = currentRowState(a[0][0], a[1][0], a[2][0]);
    if (result == 1)
        return 1;
    if (result == 2)
        return 2;
    if (result == 3)
        linesblocked++;

    result = currentRowState(a[0][1], a[1][1], a[2][1]);
    if (result == 1)
        return 1;
    if (result == 2)
        return 2;
    if (result == 3)
        linesblocked++;

    result = currentRowState(a[0][2], a[1][2], a[2][2]);
    if (result == 1)
        return 1;
    if (result == 2)
        return 2;
    if (result == 3)
        linesblocked++;

        result = currentRowState(a[0][0], a[1][1], a[2][2]);
    if (result == 1)
        return 1;
    if (result == 2)
        return 2;
    if (result == 3)
        linesblocked++;

        result = currentRowState(a[2][0], a[1][1], a[0][2]);
    if (result == 1)
        return 1;
    if (result == 2)
        return 2;
    if (result == 3)
        linesblocked++;

        if(linesblocked==8)
        return 3;

        return 0;
}

int currentRowState(int x,int y,int z)
{
/*
0-Continue
1-Player 1 wins
2-Player 2 wins
3-Game Blocked
*/

    int p1count = 0, p2count = 0;
    if (x == 1)
        p1count++;
    if (y == 1)
        p1count++;
    if (z == 1)
        p1count++;

    if (x == 2)
        p2count++;
    if (y == 2)
        p2count++;
    if (z == 2)
        p2count++;

    if (p1count == 3)
        return 1;
    if (p2count == 3)
        return 2;
    if (p1count > 0 && p2count > 0)
        return 3;
    return 0;
}
void readPosition()
{
    while (1)
    {
        printf("\n\n");
        printf("  ENTER YOUR DESIRED POSITION :");
        scanf("%d%d", &y, &x);
        if (x < 1 || x > 3 || y < 1 || y > 3)
        { 
            printf("\n");
            printf("  PLEASE ENTER NUMBER BETWEEN 1 TO 3  ");
            printf("\n");
            printf("           ENTER AGAIN !     ");
            printf("\n");
            continue;
        }
        num = a[y - 1][x - 1];
        if (num != 0)
        {
            printf("Already taken ");
            y = -9;
            continue;
        }
        break;
    }
}
void pad()
{
    int i, j;
    for (i = 0; i <= 2; i++)
    {
        printf("\n");
        for (j = 0; j <= 2; j++)
        {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

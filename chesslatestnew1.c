#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int count = 0;
int illb = 0; illw = 0;
int pwstatus[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };
int pbstatus[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };
int kmoves = 0;
char board[8][8] = {
                    { 'R' , 'H' , 'C' , 'Q' , 'K' , 'C' , 'H' , 'R' },
                    { 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' },
                    { 'r' , 'h' , 'c' , 'q' , 'k' , 'c' , 'h' , 'r' }
};

void display();
void change(int, int, int, int);
void pawnw(int, int);
void che_pawnb(int, int, int, int);
void che_pawnw(int, int, int, int);
void checkrookw(int, int, int, int);
void checkrookb(int, int, int, int);
void che_horseb(int, int, int, int);
void che_horsew(int, int, int, int);
void checkcamelb(int, int, int, int);
void checkcamelw(int, int, int, int);
void rookb(int, int);
void rookw(int, int);
void horseb(int, int);
void horsew(int, int);
void camelb(int, int);
void camelw(int, int);
void kingw(int, int);
void kingb(int, int);
void queenb(int, int);
void queenw(int, int);
void pawnb(int, int);
void player1();
void player2();
void kmovw();
void kmovb();
int check(int, int);
int check2(int, int);

main()
{
    int  x = 0;
    char ch;

    printf("\n\tWELCOME TO CHESS GAME");
    printf("\n\n\t By Vishal KR");

    //_getch();
    system("cls");

    do
    {
        x++;
        system("cls");
        display();

        if ((x % 2) == 0)
        {

            player2();
            if (illb > 2) {
                printf("\n\n\t----****----WINNER IS PLAYER 1 (CAPITAL/WHITE)----****----\n\n");
                exit(0);
            }
        }
        else
        {

            player1();
            if (illw > 2) {
                printf("\n\n\t----****----WINNER IS PLAYER 2 (SMALL/BLACK)----****----\n\n");
                exit(0);
            }
        }

        printf(" \n\nPress Enter To Continue ! \n\n ");

        ch = _getch();
    } while (ch == 13);

}

void display()
{
    int i, j, k;

    printf(" ");
    for (i = 0; i < 8; i++) printf("    %d", i); printf("\n");

    for (k = 0; k < 8; k++)
    {
        printf("  ");
        for (i = 0; i < 42; i++) { printf("-"); } printf("\n"); printf("%d ", k);

        for (j = 0; j < 8; j++) { printf("|| %c ", board[k][j]); }
        printf("|| \n");
    }

    printf("  ");
    for (i = 0; i < 42; i++) { printf("-"); } printf("\n");

}

void change(int r1, int c1, int r2, int c2)
{
    if (board[r2][c2] == ' ') {


        char temp;

        temp = board[r1][c1];
        board[r1][c1] = board[r2][c2];
        board[r2][c2] = temp;
    }
    else {
        char temp;

        temp = board[r1][c1];
        //  board[r1][c1] = board[r2][c2];
        board[r1][c1] = ' ';
        board[r2][c2] = temp;
    }

}

void pawnw(int r1, int c1)
{
    pwstatus[c1]++;

    printf("Available are: \n");

    if (pwstatus[c1] == 1)
    {
        if (board[r1 + 1][c1] == ' ')
            printf("%d%d , ", r1 + 1, c1);

        if (board[r1 + 2][c1] == ' ')
            printf("%d%d , ", r1 + 2, c1);

    }
    else
    {
        if (board[r1 + 1][c1] == ' ')
            printf("%d%d , ", r1 + 1, c1);

        if (check(r1 + 1, c1 + 1) == 1)
            printf("%d%d* , ", r1 + 1, c1 + 1);

        if (check(r1 + 1, c1 - 1) == 1)
            printf("%d%d* , ", r1 + 1, c1 - 1);
    }

}

void rookb(int r1, int c1)
{
    int i, j, n;

    printf("Available are: \n");

    n = c1;

    printf("Horizontally: \n");

    while (board[r1][n - 1] == ' ' || board[r1][n - 1] == 'K' || board[r1][n - 1] == 'Q' || board[r1][n - 1] == 'H' || board[r1][n - 1] == 'C' || board[r1][n - 1] == 'R' || board[r1][n - 1] == 'P')
    {
        if (n == 0) { break; }
        if (board[r1][n - 1] == 'p' || board[r1][n - 1] == 'h' || board[r1][n - 1] == 'k' || board[r1][n - 1] == 'q' || board[r1][n - 1] == 'c' || board[r1][n - 1] == 'r') { break; }
        printf("%d%d , ", r1, n - 1);
        if (board[r1][n - 1] == 'K' || board[r1][n - 1] == 'Q' || board[r1][n - 1] == 'H' || board[r1][n - 1] == 'C' || board[r1][n - 1] == 'R' || board[r1][n - 1] == 'P') { break; }
        n--;
    }

    n = c1;

    while ((board[r1][n + 1] == ' ' || board[r1][n + 1] == 'K' || board[r1][n + 1] == 'Q' || board[r1][n + 1] == 'H' || board[r1][n + 1] == 'C' || board[r1][n + 1] == 'R' || board[r1][n + 1] == 'P') && (n + 1) <= 7)
    {
        if (board[r1][n + 1] == 'p' || board[r1][n + 1] == 'h' || board[r1][n + 1] == 'k' || board[r1][n + 1] == 'q' || board[r1][n + 1] == 'c' || board[r1][n + 1] == 'r') { break; }

        printf("%d%d , ", r1, n + 1);
        if (board[r1][n + 1] == 'K' || board[r1][n + 1] == 'Q' || board[r1][n + 1] == 'H' || board[r1][n + 1] == 'C' || board[r1][n + 1] == 'R' || board[r1][n + 1] == 'P') { break; }

        n++;
    }

    printf("\nVertically:\n");

    n = r1;

    while ((board[n - 1][c1] == ' ' || board[n - 1][c1] == 'K' || board[n - 1][c1] == 'Q' || board[n - 1][c1] == 'H' || board[n - 1][c1] == 'C' || board[n - 1][c1] == 'R' || board[n - 1][c1] == 'P') && n > -1)
    {
        if (board[n - 1][c1] == 'k' || board[n - 1][c1] == 'q' || board[n - 1][c1] == 'h' || board[n - 1][c1] == 'c' || board[n - 1][c1] == 'r' || board[n - 1][c1] == 'p') { break; }

        printf("%d%d , ", n - 1, c1);
        if (board[n - 1][c1] == 'K' || board[n - 1][c1] == 'Q' || board[n - 1][c1] == 'H' || board[n - 1][c1] == 'C' || board[n - 1][c1] == 'R' || board[n - 1][c1] == 'P') { break; }

        n--;
    }

    n = r1;

    while ((board[n + 1][c1] == ' ' || board[n + 1][c1] == 'K' || board[n + 1][c1] == 'Q' || board[n + 1][c1] == 'H' || board[n + 1][c1] == 'C' || board[n + 1][c1] == 'R' || board[n + 1][c1] == 'P') && ((n) <= 7))
    {
        if (board[n + 1][c1] == 'k' || board[n + 1][c1] == 'q' || board[n + 1][c1] == 'h' || board[n + 1][c1] == 'c' || board[n + 1][c1] == 'r' || board[n + 1][c1] == 'p') { break; }

        printf("%d%d , ", n + 1, c1);
        if (board[n + 1][c1] == 'K' || board[n + 1][c1] == 'Q' || board[n + 1][c1] == 'H' || board[n + 1][c1] == 'C' || board[n + 1][c1] == 'R' || board[n + 1][c1] == 'P') { break; }

        n++;
    }

}
void rookw(int r1, int c1)
{

    int i, j, n;

    printf("Available are: \n");

    n = c1;

    printf("Horizontally: \n");

    while (board[r1][n - 1] == ' ' || board[r1][n - 1] == 'k' || board[r1][n - 1] == 'q' || board[r1][n - 1] == 'h' || board[r1][n - 1] == 'c' || board[r1][n - 1] == 'r' || board[r1][n - 1] == 'p')
    {
        if (n == 0) { break; }
        if (board[r1][n - 1] == 'K' || board[r1][n - 1] == 'Q' || board[r1][n - 1] == 'H' || board[r1][n - 1] == 'C' || board[r1][n - 1] == 'R' || board[r1][n - 1] == 'P') { break; }
        printf("%d%d , ", r1, n - 1);
        if (board[r1][n - 1] == 'p' || board[r1][n - 1] == 'h' || board[r1][n - 1] == 'k' || board[r1][n - 1] == 'q' || board[r1][n - 1] == 'c' || board[r1][n - 1] == 'r') { break; }
        n--;
    }

    n = c1;

    while ((board[r1][n + 1] == ' ' || board[r1][n + 1] == 'k' || board[r1][n + 1] == 'q' || board[r1][n + 1] == 'h' || board[r1][n + 1] == 'c' || board[r1][n + 1] == 'r' || board[r1][n + 1] == 'p') && (n + 1) <= 7)
    {


        if (board[r1][n + 1] == 'K' || board[r1][n + 1] == 'Q' || board[r1][n + 1] == 'H' || board[r1][n + 1] == 'C' || board[r1][n + 1] == 'R' || board[r1][n + 1] == 'P') { break; }

        printf("%d%d , ", r1, n + 1);
        if (board[r1][n + 1] == 'p' || board[r1][n + 1] == 'h' || board[r1][n + 1] == 'k' || board[r1][n + 1] == 'q' || board[r1][n + 1] == 'c' || board[r1][n + 1] == 'r') { break; }

        n++;
    }

    printf("\nVertically:\n");

    n = r1;

    while ((board[n - 1][c1] == ' ' || board[n - 1][c1] == 'k' || board[n - 1][c1] == 'q' || board[n - 1][c1] == 'h' || board[n - 1][c1] == 'c' || board[n - 1][c1] == 'r' || board[n - 1][c1] == 'p') && n > -1)
    {

        if (board[n - 1][c1] == 'K' || board[n - 1][c1] == 'Q' || board[n - 1][c1] == 'H' || board[n - 1][c1] == 'C' || board[n - 1][c1] == 'R' || board[n - 1][c1] == 'P') { break; }
        printf("%d%d , ", n - 1, c1);
        if (board[n - 1][c1] == 'k' || board[n - 1][c1] == 'q' || board[n - 1][c1] == 'h' || board[n - 1][c1] == 'c' || board[n - 1][c1] == 'r' || board[n - 1][c1] == 'p') { break; }

        n--;
    }

    n = r1;

    while ((board[n + 1][c1] == ' ' || board[n + 1][c1] == 'k' || board[n + 1][c1] == 'q' || board[n + 1][c1] == 'h' || board[n + 1][c1] == 'c' || board[n + 1][c1] == 'r' || board[n + 1][c1] == 'p') && ((n) <= 7))
    {

        if (board[n + 1][c1] == 'K' || board[n + 1][c1] == 'Q' || board[n + 1][c1] == 'H' || board[n + 1][c1] == 'C' || board[n + 1][c1] == 'R' || board[n + 1][c1] == 'P') { break; }
        printf("%d%d , ", n + 1, c1);
        if (board[n + 1][c1] == 'k' || board[n + 1][c1] == 'q' || board[n + 1][c1] == 'h' || board[n + 1][c1] == 'c' || board[n + 1][c1] == 'r' || board[n + 1][c1] == 'p') { break; }

        n++;
    }


}

void horseb(int r1, int c1)
{
    printf("Available are: ");


    if (board[r1 + 2][c1 + 1] == ' ' || board[r1 + 2][c1 + 1] == 'K' || board[r1 + 2][c1 + 1] == 'Q' || board[r1 + 2][c1 + 1] == 'R' || board[r1 + 2][c1 + 1] == 'C' || board[r1 + 2][c1 + 1] == 'P' || board[r1 + 2][c1 + 1] == 'H') printf("%d%d, ", r1 + 2, c1 + 1);
    if (board[r1 + 2][c1 - 1] == ' ' || board[r1 + 2][c1 - 1] == 'K' || board[r1 + 2][c1 - 1] == 'Q' || board[r1 + 2][c1 - 1] == 'R' || board[r1 + 2][c1 - 1] == 'C' || board[r1 + 2][c1 - 1] == 'P' || board[r1 + 2][c1 - 1] == 'H') { if ((c1 - 1) > -1) printf("%d%d, ", r1 + 2, c1 - 1); }

    if (board[r1 + 1][c1 + 2] == ' ' || board[r1 + 1][c1 + 2] == 'K' || board[r1 + 1][c1 + 2] == 'Q' || board[r1 + 1][c1 + 2] == 'R' || board[r1 + 1][c1 + 2] == 'C' || board[r1 + 1][c1 + 2] == 'P' || board[r1 + 1][c1 + 2] == 'H') { if ((c1 + 2) != 8) printf("%d%d, ", r1 + 1, c1 + 2); }
    if (board[r1 - 1][c1 + 2] == ' ' || board[r1 - 1][c1 + 2] == 'K' || board[r1 - 1][c1 + 2] == 'Q' || board[r1 - 1][c1 + 2] == 'R' || board[r1 - 1][c1 + 2] == 'C' || board[r1 - 1][c1 + 2] == 'P' || board[r1 - 1][c1 + 2] == 'H') { printf("%d%d, ", r1 - 1, c1 + 2); }

    if (board[r1 - 2][c1 - 1] == ' ' || board[r1 - 2][c1 - 1] == 'K' || board[r1 - 2][c1 - 1] == 'Q' || board[r1 - 2][c1 - 1] == 'R' || board[r1 - 2][c1 - 1] == 'C' || board[r1 - 2][c1 - 1] == 'P' || board[r1 - 2][c1 - 1] == 'H')
    {
        if ((c1 - 1) != -1)
            printf("%d%d, ", r1 - 2, c1 - 1);
    }

    if (board[r1 - 2][c1 + 1] == ' ' || board[r1 - 2][c1 + 1] == 'K' || board[r1 - 2][c1 + 1] == 'Q' || board[r1 - 2][c1 + 1] == 'R' || board[r1 - 2][c1 + 1] == 'C' || board[r1 - 2][c1 + 1] == 'P' || board[r1 - 2][c1 + 1] == 'H') printf("%d%d, ", r1 - 2, c1 + 1);

    if (board[r1 + 1][c1 - 2] == ' ' || board[r1 + 1][c1 - 2] == 'K' || board[r1 + 1][c1 - 2] == 'Q' || board[r1 + 1][c1 - 2] == 'R' || board[r1 + 1][c1 - 2] == 'C' || board[r1 + 1][c1 - 2] == 'P' || board[r1 + 1][c1 - 2] == 'H') printf("%d%d, ", r1 + 1, c1 - 2);

    if (board[r1 - 1][c1 - 2] == ' ' || board[r1 - 1][c1 - 2] == 'K' || board[r1 - 1][c1 - 2] == 'Q' || board[r1 - 1][c1 - 2] == 'R' || board[r1 - 1][c1 - 2] == 'C' || board[r1 - 1][c1 - 2] == 'P' || board[r1 - 1][c1 - 2] == 'H')
    {
        if ((c1 - 2) != -1)
            printf("%d%d, ", r1 - 1, c1 - 2);
    }
}
void horsew(int r1, int c1)
{
    printf("Available are: ");


    if (board[r1 + 2][c1 + 1] == ' ' || board[r1 + 2][c1 + 1] == 'k' || board[r1 + 2][c1 + 1] == 'q' || board[r1 + 2][c1 + 1] == 'r' || board[r1 + 2][c1 + 1] == 'c' || board[r1 + 2][c1 + 1] == 'p' || board[r1 + 2][c1 + 1] == 'h') printf("%d%d, ", r1 + 2, c1 + 1);
    if (board[r1 + 2][c1 - 1] == ' ' || board[r1 + 2][c1 - 1] == 'k' || board[r1 + 2][c1 - 1] == 'q' || board[r1 + 2][c1 - 1] == 'r' || board[r1 + 2][c1 - 1] == 'c' || board[r1 + 2][c1 - 1] == 'p' || board[r1 + 2][c1 - 1] == 'h') { if ((c1 - 1) > -1) printf("%d%d, ", r1 + 2, c1 - 1); }

    if (board[r1 + 1][c1 + 2] == ' ' || board[r1 + 1][c1 + 2] == 'k' || board[r1 + 1][c1 + 2] == 'q' || board[r1 + 1][c1 + 2] == 'r' || board[r1 + 1][c1 + 2] == 'c' || board[r1 + 1][c1 + 2] == 'p' || board[r1 + 1][c1 + 2] == 'h') { if ((c1 + 2) != 8) printf("%d%d, ", r1 + 1, c1 + 2); }
    if (board[r1 - 1][c1 + 2] == ' ' || board[r1 - 1][c1 + 2] == 'k' || board[r1 - 1][c1 + 2] == 'q' || board[r1 - 1][c1 + 2] == 'r' || board[r1 - 1][c1 + 2] == 'c' || board[r1 - 1][c1 + 2] == 'p' || board[r1 - 1][c1 + 2] == 'h') { printf("%d%d, ", r1 - 1, c1 + 2); }

    if (board[r1 - 2][c1 - 1] == ' ' || board[r1 - 2][c1 - 1] == 'k' || board[r1 - 2][c1 - 1] == 'q' || board[r1 - 2][c1 - 1] == 'r' || board[r1 - 2][c1 - 1] == 'c' || board[r1 - 2][c1 - 1] == 'p' || board[r1 - 2][c1 - 1] == 'h')
    {
        if ((c1 - 1) != -1)
            printf("%d%d, ", r1 - 2, c1 - 1);
    }

    if (board[r1 - 2][c1 + 1] == ' ' || board[r1 - 2][c1 + 1] == 'k' || board[r1 - 2][c1 + 1] == 'q' || board[r1 - 2][c1 + 1] == 'r' || board[r1 - 2][c1 + 1] == 'c' || board[r1 - 2][c1 + 1] == 'p' || board[r1 - 2][c1 + 1] == 'h') printf("%d%d, ", r1 - 2, c1 + 1);

    if (board[r1 + 1][c1 - 2] == ' ' || board[r1 + 1][c1 - 2] == 'k' || board[r1 + 1][c1 - 2] == 'q' || board[r1 + 1][c1 - 2] == 'r' || board[r1 + 1][c1 - 2] == 'c' || board[r1 + 1][c1 - 2] == 'p' || board[r1 + 1][c1 - 2] == 'h') printf("%d%d, ", r1 + 1, c1 - 2);

    if (board[r1 - 1][c1 - 2] == ' ' || board[r1 - 1][c1 - 2] == 'k' || board[r1 - 1][c1 - 2] == 'q' || board[r1 - 1][c1 - 2] == 'r' || board[r1 - 1][c1 - 2] == 'c' || board[r1 - 1][c1 - 2] == 'p' || board[r1 - 1][c1 - 2] == 'h')
    {
        if ((c1 - 2) != -1)
            printf("%d%d, ", r1 - 1, c1 - 2);
    }
}


void camelb(int r1, int c1)
{
    int a, b;
    printf("Available are: \n");


    a = 1, b = 1;

    while (board[r1 - a][c1 + b] == ' ' || board[r1 - a][c1 + b] == 'K' || board[r1 - a][c1 + b] == 'Q' | board[r1 - a][c1 + b] == 'R' || board[r1 - a][c1 + b] == 'C' | board[r1 - a][c1 + b] == 'P' || board[r1 - a][c1 + b] == 'H')
    {
        if ((r1 - a) == -1 || (c1 + b) == 8) break;

        if (board[r1 - a][c1 + b] == 'k' || board[r1 - a][c1 + b] == 'q' | board[r1 - a][c1 + b] == 'r' || board[r1 - a][c1 + b] == 'c' | board[r1 - a][c1 + b] == 'p' || board[r1 - a][c1 + b] == 'h') { break; }

        printf("%d%d , ", r1 - a, c1 + b);
        if (board[r1 - a][c1 + b] == 'K' || board[r1 - a][c1 + b] == 'Q' | board[r1 - a][c1 + b] == 'R' || board[r1 - a][c1 + b] == 'C' | board[r1 - a][c1 + b] == 'P' || board[r1 - a][c1 + b] == 'H') { break; }

        a++;
        b++;
    }


    a = 1, b = 1;

    while (board[r1 + a][c1 - b] == ' ' || board[r1 + a][c1 - b] == 'K' || board[r1 + a][c1 - b] == 'Q' || board[r1 + a][c1 - b] == 'R' || board[r1 + a][c1 - b] == 'C' || board[r1 + a][c1 - b] == 'P' || board[r1 + a][c1 - b] == 'H')
    {
        if ((r1 + a) == 8 || (c1 - b) == -1) break;

        if (board[r1 + a][c1 - b] == 'k' || board[r1 + a][c1 - b] == 'q' || board[r1 + a][c1 - b] == 'r' || board[r1 + a][c1 - b] == 'c' || board[r1 + a][c1 - b] == 'p' || board[r1 + a][c1 - b] == 'h') {
            break;
        }
        printf("%d%d , ", r1 + a, c1 - b);
        if (board[r1 + a][c1 - b] == 'K' || board[r1 + a][c1 - b] == 'Q' || board[r1 + a][c1 - b] == 'R' || board[r1 + a][c1 - b] == 'C' || board[r1 + a][c1 - b] == 'P' || board[r1 + a][c1 - b] == 'H') {
            break;
        }


        a++;
        b++;
    }

    a = 1, b = 1;


    while (board[r1 + a][c1 + b] == ' ' || board[r1 + a][c1 + b] == 'K' || board[r1 + a][c1 + b] == 'Q' || board[r1 + a][c1 + b] == 'R' || board[r1 + a][c1 + b] == 'C' || board[r1 + a][c1 + b] == 'P' || board[r1 + a][c1 + b] == 'H')
    {
        if ((r1 + a) == 8 || (c1 + b) == 8) break;
        if (board[r1 + a][c1 + b] == 'k' || board[r1 + a][c1 + b] == 'q' || board[r1 + a][c1 + b] == 'r' || board[r1 + a][c1 + b] == 'c' || board[r1 + a][c1 + b] == 'p' || board[r1 + a][c1 + b] == 'h') {
            break;
        }
        printf("%d%d , ", r1 + a, c1 + b);


        if (board[r1 + a][c1 + b] == 'K' || board[r1 + a][c1 + b] == 'Q' || board[r1 + a][c1 + b] == 'R' || board[r1 + a][c1 + b] == 'C' || board[r1 + a][c1 + b] == 'P' || board[r1 + a][c1 + b] == 'H') {
            break;
        }

        a++;
        b++;
    }

    a = 1;
    b = 1;

    while (board[r1 - a][c1 - b] == ' ' || board[r1 - a][c1 - b] == 'K' || board[r1 - a][c1 - b] == 'Q' || board[r1 - a][c1 - b] == 'R' || board[r1 - a][c1 - b] == 'C' || board[r1 - a][c1 - b] == 'P' || board[r1 - a][c1 - b] == 'H')
    {
        if ((r1 - a) == -1 || (c1 - b) == -1) break;

        if (board[r1 - a][c1 - b] == 'k' || board[r1 - a][c1 - b] == 'q' || board[r1 - a][c1 - b] == 'r' || board[r1 - a][c1 - b] == 'c' || board[r1 - a][c1 - b] == 'p' || board[r1 - a][c1 - b] == 'h') {
            break;
        }
        printf("%d%d , ", r1 - a, c1 - b);

        if (board[r1 - a][c1 - b] == 'K' || board[r1 - a][c1 - b] == 'Q' || board[r1 - a][c1 - b] == 'R' || board[r1 - a][c1 - b] == 'C' || board[r1 - a][c1 - b] == 'P' || board[r1 - a][c1 - b] == 'H') { break; }


        a++;
        b++;
    }

}
void camelw(int r1, int c1)
{
    int a, b;
    printf("Available are: \n");


    a = 1, b = 1;

    while (board[r1 - a][c1 + b] == 'k' || board[r1 - a][c1 + b] == ' ' || board[r1 - a][c1 + b] == 'q' | board[r1 - a][c1 + b] == 'r' || board[r1 - a][c1 + b] == 'c' | board[r1 - a][c1 + b] == 'p' || board[r1 - a][c1 + b] == 'h')
    {
        if ((r1 - a) == -1 || (c1 + b) == 8) break;
        if (board[r1 - a][c1 + b] == 'K' || board[r1 - a][c1 + b] == 'Q' | board[r1 - a][c1 + b] == 'R' || board[r1 - a][c1 + b] == 'C' | board[r1 - a][c1 + b] == 'P' || board[r1 - a][c1 + b] == 'H') { break; }
        printf("%d%d , ", r1 - a, c1 + b);
        if (board[r1 - a][c1 + b] == 'k' || board[r1 - a][c1 + b] == 'q' | board[r1 - a][c1 + b] == 'r' || board[r1 - a][c1 + b] == 'c' | board[r1 - a][c1 + b] == 'p' || board[r1 - a][c1 + b] == 'h') { break; }
        a++;
        b++;
    }


    a = 1, b = 1;

    while (board[r1 + a][c1 - b] == 'k' || board[r1 + a][c1 - b] == ' ' || board[r1 + a][c1 - b] == 'q' || board[r1 + a][c1 - b] == 'r' || board[r1 + a][c1 - b] == 'c' || board[r1 + a][c1 - b] == 'p' || board[r1 + a][c1 - b] == 'h')
    {
        if ((r1 + a) == 8 || (c1 - b) == -1) break;
        if (board[r1 + a][c1 - b] == 'K' || board[r1 + a][c1 - b] == 'Q' || board[r1 + a][c1 - b] == 'R' || board[r1 + a][c1 - b] == 'C' || board[r1 + a][c1 - b] == 'P' || board[r1 + a][c1 - b] == 'H') {
            break;
        }
        printf("%d%d , ", r1 + a, c1 - b);
        if (board[r1 + a][c1 - b] == 'k' || board[r1 + a][c1 - b] == 'q' || board[r1 + a][c1 - b] == 'r' || board[r1 + a][c1 - b] == 'c' || board[r1 + a][c1 - b] == 'p' || board[r1 + a][c1 - b] == 'h') {
            break;
        }
        a++;
        b++;
    }

    a = 1, b = 1;


    while (board[r1 + a][c1 + b] == 'k' || board[r1 + a][c1 + b] == ' ' || board[r1 + a][c1 + b] == 'q' || board[r1 + a][c1 + b] == 'r' || board[r1 + a][c1 + b] == 'c' || board[r1 + a][c1 + b] == 'p' || board[r1 + a][c1 + b] == 'h')
    {
        if ((r1 + a) == 8 || (c1 + b) == 8) break;
        if (board[r1 + a][c1 + b] == 'K' || board[r1 + a][c1 + b] == 'Q' || board[r1 + a][c1 + b] == 'R' || board[r1 + a][c1 + b] == 'C' || board[r1 + a][c1 + b] == 'P' || board[r1 + a][c1 + b] == 'H') {
            break;
        }
        printf("%d%d , ", r1 + a, c1 + b);
        if (board[r1 + a][c1 + b] == 'k' || board[r1 + a][c1 + b] == 'q' || board[r1 + a][c1 + b] == 'r' || board[r1 + a][c1 + b] == 'c' || board[r1 + a][c1 + b] == 'p' || board[r1 + a][c1 + b] == 'h') {
            break;
        }
        a++;
        b++;
    }

    a = 1;
    b = 1;

    while (board[r1 - a][c1 - b] == 'k' || board[r1 - a][c1 - b] == ' ' || board[r1 - a][c1 - b] == 'q' || board[r1 - a][c1 - b] == 'r' || board[r1 - a][c1 - b] == 'c' || board[r1 - a][c1 - b] == 'p' || board[r1 - a][c1 - b] == 'h')
    {
        if ((r1 - a) == -1 || (c1 - b) == -1) break;
        if (board[r1 - a][c1 - b] == 'K' || board[r1 - a][c1 - b] == 'Q' || board[r1 - a][c1 - b] == 'R' || board[r1 - a][c1 - b] == 'C' || board[r1 - a][c1 - b] == 'P' || board[r1 - a][c1 - b] == 'H') { break; }
        printf("%d%d , ", r1 - a, c1 - b);
        if (board[r1 - a][c1 - b] == 'k' || board[r1 - a][c1 - b] == 'q' || board[r1 - a][c1 - b] == 'r' || board[r1 - a][c1 - b] == 'c' || board[r1 - a][c1 - b] == 'p' || board[r1 - a][c1 - b] == 'h') {
            break;
        }
        a++;
        b++;
    }

}

void kingb(int r1, int c1)
{
    
    printf("Available are: ");
    if (board[r1][c1 + 1] == ' ' || board[r1][c1 + 1] == 'Q' || board[r1][c1 + 1] == 'H' || board[r1][c1 + 1] == 'C' || board[r1][c1 + 1] == 'R' || board[r1][c1 + 1] == 'P') {
        printf("%d%d , ", r1, c1 + 1);
        
    }

    if (board[r1][c1 - 1] == ' ' || board[r1][c1 - 1] == 'Q' || board[r1][c1 - 1] == 'H' || board[r1][c1 - 1] == 'C' || board[r1][c1 - 1] == 'R' || board[r1][c1 - 1] == 'P') { printf("%d%d , ", r1, c1 - 1);
    
    }

    if (board[r1 + 1][c1] == ' ' || board[r1 + 1][c1] == 'Q' || board[r1 + 1][c1] == 'H' || board[r1 + 1][c1] == 'C' || board[r1 + 1][c1] == 'R' || board[r1 + 1][c1] == 'P') { printf("%d%d , ", r1 + 1, c1); 
    
    }

    if (board[r1 - 1][c1] == ' ' || board[r1 - 1][c1] == 'Q' || board[r1 - 1][c1] == 'H' || board[r1 - 1][c1] == 'C' || board[r1 - 1][c1] == 'R' || board[r1 - 1][c1] == 'P') { printf("%d%d , ", r1 - 1, c1); 
    
    }

    if (board[r1 + 1][c1 + 1] == ' ' || board[r1 + 1][c1 + 1] == 'Q' || board[r1 + 1][c1 + 1] == 'H' || board[r1 + 1][c1 + 1] == 'C' || board[r1 + 1][c1 + 1] == 'R' || board[r1 + 1][c1 + 1] == 'P') { printf("%d%d , ", r1 + 1, c1 + 1);
    
    
    }

    if (board[r1 - 1][c1 - 1] == ' ' || board[r1 - 1][c1 - 1] == 'Q' || board[r1 - 1][c1 - 1] == 'H' || board[r1 - 1][c1 - 1] == 'C' || board[r1 - 1][c1 - 1] == 'R' || board[r1 - 1][c1 - 1] == 'P') { printf("%d%d , ", r1 - 1, c1 - 1);
   
    }

    if (board[r1 - 1][c1 + 1] == ' ' || board[r1 - 1][c1 + 1] == 'Q' || board[r1 - 1][c1 + 1] == 'H' || board[r1 - 1][c1 + 1] == 'C' || board[r1 - 1][c1 + 1] == 'R' || board[r1 - 1][c1 + 1] == 'P') { printf("%d%d , ", r1 - 1, c1 + 1);
   
    }

    if (board[r1 + 1][c1 - 1] == ' ' || board[r1 + 1][c1 - 1] == 'Q' || board[r1 + 1][c1 - 1] == 'H' || board[r1 + 1][c1 - 1] == 'C' || board[r1 + 1][c1 - 1] == 'R' || board[r1 + 1][c1 - 1] == 'P') { printf("%d%d , ", r1 + 1, c1 - 1);
    
    }
}
void kingw(int r1, int c1)
{
    
    printf("Available are: ");
    if (board[r1][c1 + 1] == ' ' || board[r1][c1 + 1] == 'q' || board[r1][c1 + 1] == 'h' || board[r1][c1 + 1] == 'c' || board[r1][c1 + 1] == 'r' || board[r1][c1 + 1] == 'p') { printf("%d%d , ", r1, c1 + 1);
   
    }

    if (board[r1][c1 - 1] == ' ' || board[r1][c1 - 1] == 'q' || board[r1][c1 - 1] == 'h' || board[r1][c1 - 1] == 'c' || board[r1][c1 - 1] == 'r' || board[r1][c1 - 1] == 'p') { printf("%d%d , ", r1, c1 - 1); 
    
    }

    if (board[r1 + 1][c1] == ' ' || board[r1 + 1][c1] == 'q' || board[r1 + 1][c1] == 'h' || board[r1 + 1][c1] == 'c' || board[r1 + 1][c1] == 'r' || board[r1 + 1][c1] == 'p') { printf("%d%d , ", r1 + 1, c1);
   
    }

    if (board[r1 - 1][c1] == ' ' || board[r1 - 1][c1] == 'q' || board[r1 - 1][c1] == 'h' || board[r1 - 1][c1] == 'c' || board[r1 - 1][c1] == 'r' || board[r1 - 1][c1] == 'p') { printf("%d%d , ", r1 - 1, c1);
    
    }

    if (board[r1 + 1][c1 + 1] == ' ' || board[r1 + 1][c1 + 1] == 'q' || board[r1 + 1][c1 + 1] == 'h' || board[r1 + 1][c1 + 1] == 'c' || board[r1 + 1][c1 + 1] == 'r' || board[r1 + 1][c1 + 1] == 'p') { printf("%d%d , ", r1 + 1, c1 + 1);
    
    }

    if (board[r1 - 1][c1 - 1] == ' ' || board[r1 - 1][c1 - 1] == 'q' || board[r1 - 1][c1 - 1] == 'h' || board[r1 - 1][c1 - 1] == 'c' || board[r1 - 1][c1 - 1] == 'r' || board[r1 - 1][c1 - 1] == 'p') { printf("%d%d , ", r1 - 1, c1 - 1); 
    
    }

    if (board[r1 - 1][c1 + 1] == ' ' || board[r1 - 1][c1 + 1] == 'q' || board[r1 - 1][c1 + 1] == 'h' || board[r1 - 1][c1 + 1] == 'c' || board[r1 - 1][c1 + 1] == 'r' || board[r1 - 1][c1 + 1] == 'p') { printf("%d%d , ", r1 - 1, c1 + 1);
    
    }

    if (board[r1 + 1][c1 - 1] == ' ' || board[r1 + 1][c1 - 1] == 'q' || board[r1 + 1][c1 - 1] == 'h' || board[r1 + 1][c1 - 1] == 'c' || board[r1 + 1][c1 - 1] == 'r' || board[r1 + 1][c1 - 1] == 'p') { printf("%d%d , ", r1 + 1, c1 - 1);
    
    }

}

void queenb(int r1, int c1)
{
    int a, b;
    a = r1;
    b = c1;
    printf("Diagonals:");
    camelb(r1, c1);
    printf("\n");

    rookb(r1, c1);

}
void queenw(int r1, int c1)
{
    int a, b;
    a = r1;
    b = c1;
    printf("Diagonals:");
    camelw(r1, c1);
    printf("\n");
    rookw(r1, c1);
}

void pawnb(int r1, int c1)
{
    pbstatus[c1]++;

    printf("Available are: \n");


    if (pbstatus[c1] == 1)
    {
        if (board[r1 - 1][c1] == ' ')
            printf("%d%d , ", r1 - 1, c1);

        if (board[r1 - 2][c1] == ' ')
            printf("%d%d , ", r1 - 2, c1);
    }
    else
    {
        if (board[r1 - 1][c1] == ' ')
            printf("%d%d , ", r1 - 1, c1);

        if (check2(r1 - 1, c1 - 1) == 1)
            printf("%d%d* , ", r1 - 1, c1 - 1);

        if (check2(r1 - 1, c1 + 1) == 1)
            printf("%d%d* , ", r1 - 1, c1 + 1);
    }

}

void player1()
{
    int p1, p2, c1, r1, c2, r2, ch = 0,d=0;
    checkkingw();
    if (count != 0) {
        ch = 1;
        printf("\n----****----ITS A CHECK FOR YOU----****----\n");
        kmovw();
       // if (kmoves == 0){
          //  d = 2;
       // }
    }
    printf("\nPLAYER 1 - Big Case\n");

again1:


    printf("\nEnter Position of Element to change ( RC ): ");
    scanf_s("%d", &p1);

    c1 = p1 % 10;
    r1 = p1 / 10;

    switch (board[r1][c1])
    {
    case 'P': pawnw(r1, c1);
        break;
    case 'R': rookw(r1, c1);
        break;
    case 'H': horsew(r1, c1);
        break;
    case 'C': camelw(r1, c1);
        break;
    case 'K': kingw(r1, c1);
        break;
    case 'Q': queenw(r1, c1);
        break;
    default: printf("Invalid Position ! "); goto again1;
    }

    printf("\nEnter Position of Place to Send ( RC ): ");
    scanf_s("%d", &p2);

    c2 = p2 % 10;
    r2 = p2 / 10;


    change(r1, c1, r2, c2);
    if (ch == 1) {
        count = 0;
       // printf("\n%d\n", 1);
        checkkingw();
        if (count != 0) {
            illw++;
            if (illw > 2) {
                printf("\n\n\t----****----CHECKMATE----****----\n\n");
                printf("\n\n\t----****----WINNER IS PLAYER 2 (SMALL/BLACK)----****----\n\n");
                exit(0);
            }
            if (d == 2) {
                kmovw;
               /* if (kmoves == 0) {
                    printf("\n\n\t----****----CHECKMATE----****----\n\n");
                    printf("\n\n\t----****----WINNER IS PLAYER 2 (SMALL/BLACK)----****----\n\n");
                    exit(0);
                }*/
            }
            change(r2, c2, r1, c1);
            printf("\n----****----ILLEGAL MOVE NO %d----****----", illw);
            goto again1;
        }
    }
    count = 0;

}

void player2()
{
    int p1, p2, c1, r1, c2, r2, ch = 0, d = 0;
    checkkingb();
    if (count != 0) {
        ch = 1;
        printf("\n----****----ITS A CHECK FOR YOU----****----\n");
        kmovb();
       // if (kmoves == 0) {
         //   d = 2;
        //}
    }

    printf("\nPLAYER 2 - Small Case \n");
again2:

    printf("\nEnter Position of Element to change ( RC ): ");
    scanf_s("%d", &p1);

    c1 = p1 % 10;
    r1 = p1 / 10;

    switch (board[r1][c1])
    {
    case 'p': pawnb(r1, c1);
        break;
    case 'r': rookb(r1, c1);
        break;
    case 'h': horseb(r1, c1);
        break;
    case 'c': camelb(r1, c1);
        break;
    case 'k': kingb(r1, c1);
        break;
    case 'q': queenb(r1, c1);
        break;
    default: printf("Invalid Position ! "); goto again2;
    }

    printf("\nEnter Position of Place to Send ( RC ): ");
    scanf_s("%d", &p2);

    c2 = p2 % 10;
    r2 = p2 / 10;


    change(r1, c1, r2, c2);
    if (ch == 1) {
        count = 0;
       // printf("\n%d\n", 1);
        checkkingb();
        printf("%d", count);
        if (count != 0) {
            illb++;
            if (illb > 2) {

                printf("\n\n\t----****----CHECKMATE----****----\n\n");
                printf("\n\n\t----****----WINNER IS PLAYER 1 (CAPITAL/WHITE)----****----\n\n");
                exit(0);
            }
                /*if (d == 2) {
                    kmovb;
                    if (kmoves == 0) {
                        printf("\n\n\t----****----CHECKMATE----****----\n\n");
                        printf("\n\n\t----****----WINNER IS PLAYER 1 (CAPITAL/WHITE)----****----\n\n");
                        exit(0);
                    }
                }*/
            change(r2, c2, r1, c1);
            printf("\n----****----ILLEGAL MOVE NO %d----****----", illb);
            goto again2;
        }
    }

    count = 0;
}

int check(int x, int y)
{
    switch (board[x][y])
    {
    case 'p':
    case 'r':
    case 'h':
    case 'c':
    case 'k':
    case 'q': return 1; break;
    default: return 0;
    }
}

int check2(int x, int y)
{
    switch (board[x][y])
    {
    case 'P':
    case 'R':
    case 'H':
    case 'C':
    case 'K':
    case 'Q': return 1; break;
    default: return 0;
    }
}
int checkkingw() {
    int f = 0;
    int i = 0, j = 0, l, m;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] == 'K') {
                f = 1;
                break;

            }
        }
        if (f == 1) {
            break;
        }
    }
    for (l = 0; l < 8; l++) {
        for (m = 0; m < 8; m++) {
            switch (board[l][m]) {
            case 'p':
                che_pawnb(l, m, i, j);
                break;

            case 'r':
                checkrookb(l, m, i, j);
                break;
            case 'h':
                che_horseb(l, m, i, j);
                break;
            case 'c':
                checkcamelb(l, m, i, j);
                break;
            case 'q':
                checkcamelb(l, m, i, j);
                checkrookb(l, m, i, j);
                break;

            }
        }

    }
}
int checkkingb() {
    int f = 0;
    int i = 0, j = 0, l, m;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] == 'k') {
                f = 1;
                break;

            }
        }
        if (f == 1) {
            break;
        }
    }
    for (l = 0; l < 8; l++) {
        for (m = 0; m < 8; m++) {
            switch (board[l][m]) {
            case 'P':
                che_pawnw(l, m, i, j);
                break;

            case 'R':
                checkrookw(l, m, i, j);
                break;
            case 'H':
                che_horsew(l, m, i, j);
                break;
            case 'C':
                checkcamelw(l, m, i, j);
                break;
            case 'Q':
                checkcamelw(l, m, i, j);
                checkrookw(l, m, i, j);
                break;
            }
        }

    }
}
void che_pawnw(int l, int m, int i, int j) {
    if (pwstatus[m] == 1)
    {
        if (board[l + 1][m] == ' ')
        {
            if (i == l + 1 && j == m) {

                count++;
            }
        }


        if (board[l + 2][m] == ' ') {
            if (i == l + 2 && j == m) {

                count++;
            }

        }


    }
    else
    {
        if (board[l + 1][m] == ' ') {
            if (i == l + 1 && j == m) {

                count++;
            }

        }


        if (check(l + 1, m + 1) == 1) {
            if (i == l + 1 && j == m + 1) {

                count++;
            }

        }


        if (check(l + 1, m - 1) == 1) {
            if (i == l + 1 && j == m - 1) {

                count++;
            }

        }

    }


}
void che_pawnb(int l, int m, int i, int j) {
    if (pbstatus[m] == 1)
    {
        if (board[l - 1][m] == ' ')
        {
            if (i == l - 1 && j == m) {

                count++;
            }

        }


        if (board[l - 2][m] == ' ')
        {
            if (i == l - 2 && j == m) {

                count++;
            }

        }

    }
    else
    {
        if (board[l - 1][m] == ' ')
        {
            if (i == l - 1 && j == m) {

                count++;
            }

        }


        if (check2(l - 1, m - 1) == 1)
        {
            if (i == l - 1 && j == m - 1) {

                count++;
            }

        }


        if (check2(l - 1, m + 1) == 1)
        {
            if (i == l - 1 && j == m + 1) {

                count++;
            }

        }

    }
}
void checkrookw(int r1, int c1, int i, int j) {
    int  n;
    n = c1;
    while (board[r1][n - 1] == ' ' || board[r1][n - 1] == 'k' || board[r1][n - 1] == 'q' || board[r1][n - 1] == 'h' || board[r1][n - 1] == 'c' || board[r1][n - 1] == 'r' || board[r1][n - 1] == 'p')
    {
        if (n == 0) { break; }
        if (board[r1][n - 1] == 'K' || board[r1][n - 1] == 'Q' || board[r1][n - 1] == 'H' || board[r1][n - 1] == 'C' || board[r1][n - 1] == 'R' || board[r1][n - 1] == 'P') { break; }
        if (i == r1 && j == n - 1) {
            //printf("Check for black");
            count++;
        }
        if (board[r1][n - 1] == 'p' || board[r1][n - 1] == 'h' || board[r1][n - 1] == 'k' || board[r1][n - 1] == 'q' || board[r1][n - 1] == 'c' || board[r1][n - 1] == 'r') { break; }
        n--;
    }

    n = c1;

    while ((board[r1][n + 1] == ' ' || board[r1][n + 1] == 'k' || board[r1][n + 1] == 'q' || board[r1][n + 1] == 'h' || board[r1][n + 1] == 'c' || board[r1][n + 1] == 'r' || board[r1][n + 1] == 'p') && (n + 1) <= 7)
    {


        if (board[r1][n + 1] == 'K' || board[r1][n + 1] == 'Q' || board[r1][n + 1] == 'H' || board[r1][n + 1] == 'C' || board[r1][n + 1] == 'R' || board[r1][n + 1] == 'P') { break; }

        if (i == r1 && j == n + 1) {
            //printf("Check for black");
            count++;

        }
        if (board[r1][n + 1] == 'p' || board[r1][n + 1] == 'h' || board[r1][n + 1] == 'k' || board[r1][n + 1] == 'q' || board[r1][n + 1] == 'c' || board[r1][n + 1] == 'r') { break; }

        n++;
    }



    n = r1;

    while ((board[n - 1][c1] == ' ' || board[n - 1][c1] == 'k' || board[n - 1][c1] == 'q' || board[n - 1][c1] == 'h' || board[n - 1][c1] == 'c' || board[n - 1][c1] == 'r' || board[n - 1][c1] == 'p') && n > -1)
    {

        if (board[n - 1][c1] == 'K' || board[n - 1][c1] == 'Q' || board[n - 1][c1] == 'H' || board[n - 1][c1] == 'C' || board[n - 1][c1] == 'R' || board[n - 1][c1] == 'P') { break; }
        if (i == n - 1 && j == c1) {
            //printf("Check for Black");
            count++;
        }
        if (board[n - 1][c1] == 'k' || board[n - 1][c1] == 'q' || board[n - 1][c1] == 'h' || board[n - 1][c1] == 'c' || board[n - 1][c1] == 'r' || board[n - 1][c1] == 'p') { break; }

        n--;
    }

    n = r1;

    while ((board[n + 1][c1] == ' ' || board[n + 1][c1] == 'k' || board[n + 1][c1] == 'q' || board[n + 1][c1] == 'h' || board[n + 1][c1] == 'c' || board[n + 1][c1] == 'r' || board[n + 1][c1] == 'p') && ((n) <= 7))
    {

        if (board[n + 1][c1] == 'K' || board[n + 1][c1] == 'Q' || board[n + 1][c1] == 'H' || board[n + 1][c1] == 'C' || board[n + 1][c1] == 'R' || board[n + 1][c1] == 'P') { break; }
        if (i == n + 1 && j == c1) {
            //printf("Check for black");
            count++;
        }
        if (board[n + 1][c1] == 'k' || board[n + 1][c1] == 'q' || board[n + 1][c1] == 'h' || board[n + 1][c1] == 'c' || board[n + 1][c1] == 'r' || board[n + 1][c1] == 'p') { break; }

        n++;
    }



}
void checkrookb(int r1, int c1, int i, int j) {
    int  n;



    n = c1;

    while (board[r1][n - 1] == ' ' || board[r1][n - 1] == 'K' || board[r1][n - 1] == 'Q' || board[r1][n - 1] == 'H' || board[r1][n - 1] == 'C' || board[r1][n - 1] == 'R' || board[r1][n - 1] == 'P')
    {
        if (n == 0) { break; }
        if (board[r1][n - 1] == 'p' || board[r1][n - 1] == 'h' || board[r1][n - 1] == 'k' || board[r1][n - 1] == 'q' || board[r1][n - 1] == 'c' || board[r1][n - 1] == 'r') { break; }
        if (board[r1][n - 1] == 'K') {
            //printf("Check for White");
            count++;
        }
        if (board[r1][n - 1] == 'K' || board[r1][n - 1] == 'Q' || board[r1][n - 1] == 'H' || board[r1][n - 1] == 'C' || board[r1][n - 1] == 'R' || board[r1][n - 1] == 'P') { break; }
        n--;
    }

    n = c1;

    while ((board[r1][n + 1] == ' ' || board[r1][n + 1] == 'K' || board[r1][n + 1] == 'Q' || board[r1][n + 1] == 'H' || board[r1][n + 1] == 'C' || board[r1][n + 1] == 'R' || board[r1][n + 1] == 'P') && (n + 1) <= 7)
    {
        if (board[r1][n + 1] == 'p' || board[r1][n + 1] == 'h' || board[r1][n + 1] == 'k' || board[r1][n + 1] == 'q' || board[r1][n + 1] == 'c' || board[r1][n + 1] == 'r') { break; }

        if (board[r1][n + 1] == 'K') {
            //printf("Check for White");
            count++;

        }
        if (board[r1][n + 1] == 'K' || board[r1][n + 1] == 'Q' || board[r1][n + 1] == 'H' || board[r1][n + 1] == 'C' || board[r1][n + 1] == 'R' || board[r1][n + 1] == 'P') { break; }

        n++;
    }



    n = r1;

    while ((board[n - 1][c1] == ' ' || board[n - 1][c1] == 'K' || board[n - 1][c1] == 'Q' || board[n - 1][c1] == 'H' || board[n - 1][c1] == 'C' || board[n - 1][c1] == 'R' || board[n - 1][c1] == 'P') && n > -1)
    {
        if (board[n - 1][c1] == 'k' || board[n - 1][c1] == 'q' || board[n - 1][c1] == 'h' || board[n - 1][c1] == 'c' || board[n - 1][c1] == 'r' || board[n - 1][c1] == 'p') { break; }

        if ((board[n - 1][c1] == 'K')) {
            //printf("Check for White");
            count++;
        }
        if (board[n - 1][c1] == 'K' || board[n - 1][c1] == 'Q' || board[n - 1][c1] == 'H' || board[n - 1][c1] == 'C' || board[n - 1][c1] == 'R' || board[n - 1][c1] == 'P') { break; }

        n--;
    }

    n = r1;

    while ((board[n + 1][c1] == ' ' || board[n + 1][c1] == 'K' || board[n + 1][c1] == 'Q' || board[n + 1][c1] == 'H' || board[n + 1][c1] == 'C' || board[n + 1][c1] == 'R' || board[n + 1][c1] == 'P') && ((n) <= 7))
    {
        if (board[n + 1][c1] == 'k' || board[n + 1][c1] == 'q' || board[n + 1][c1] == 'h' || board[n + 1][c1] == 'c' || board[n + 1][c1] == 'r' || board[n + 1][c1] == 'p') { break; }

        if (i == n + 1 && j == c1) {
            //printf("Check for White");
            count++;
        }
        if (board[n + 1][c1] == 'K' || board[n + 1][c1] == 'Q' || board[n + 1][c1] == 'H' || board[n + 1][c1] == 'C' || board[n + 1][c1] == 'R' || board[n + 1][c1] == 'P') { break; }

        n++;
    }




}
void che_horseb(int r1, int c1, int i, int j) {
    //

    if (board[r1 + 2][c1 + 1] == ' ' || board[r1 + 2][c1 + 1] == 'K' || board[r1 + 2][c1 + 1] == 'Q' || board[r1 + 2][c1 + 1] == 'R' || board[r1 + 2][c1 + 1] == 'C' || board[r1 + 2][c1 + 1] == 'P' || board[r1 + 2][c1 + 1] == 'H') {
        if (i == r1 + 2 && j == c1 + 1) {
            count++;
        }
    }
    if (board[r1 + 2][c1 - 1] == ' ' || board[r1 + 2][c1 - 1] == 'K' || board[r1 + 2][c1 - 1] == 'Q' || board[r1 + 2][c1 - 1] == 'R' || board[r1 + 2][c1 - 1] == 'C' || board[r1 + 2][c1 - 1] == 'P' || board[r1 + 2][c1 - 1] == 'H') {
        if ((c1 - 1) > -1) {
            if (i == r1 + 2 && j == c1 - 1) {
                count++;
            }

        }
    }

    if (board[r1 + 1][c1 + 2] == ' ' || board[r1 + 1][c1 + 2] == 'K' || board[r1 + 1][c1 + 2] == 'Q' || board[r1 + 1][c1 + 2] == 'R' || board[r1 + 1][c1 + 2] == 'C' || board[r1 + 1][c1 + 2] == 'P' || board[r1 + 1][c1 + 2] == 'H') {
        if ((c1 + 2) != 8) {
            if (i == r1 + 1 && j == c1 + 2) {
                count++;
            }

        }
    }
    if (board[r1 - 1][c1 + 2] == ' ' || board[r1 - 1][c1 + 2] == 'K' || board[r1 - 1][c1 + 2] == 'Q' || board[r1 - 1][c1 + 2] == 'R' || board[r1 - 1][c1 + 2] == 'C' || board[r1 - 1][c1 + 2] == 'P' || board[r1 - 1][c1 + 2] == 'H') {
        if (i == r1 - 1 && j == c1 + 2) {
            count++;
        }
    }

    if (board[r1 - 2][c1 - 1] == ' ' || board[r1 - 2][c1 - 1] == 'K' || board[r1 - 2][c1 - 1] == 'Q' || board[r1 - 2][c1 - 1] == 'R' || board[r1 - 2][c1 - 1] == 'C' || board[r1 - 2][c1 - 1] == 'P' || board[r1 - 2][c1 - 1] == 'H')
    {
        if ((c1 - 1) != -1)
        {
            if (i == r1 - 2 && j == c1 - 1) {
                count++;
            }

        }
    }

    if (board[r1 - 2][c1 + 1] == ' ' || board[r1 - 2][c1 + 1] == 'K' || board[r1 - 2][c1 + 1] == 'Q' || board[r1 - 2][c1 + 1] == 'R' || board[r1 - 2][c1 + 1] == 'C' || board[r1 - 2][c1 + 1] == 'P' || board[r1 - 2][c1 + 1] == 'H') {
        if (i == r1 - 2 && j == c1 + 1) {
            count++;
        }
    }

    if (board[r1 + 1][c1 - 2] == ' ' || board[r1 + 1][c1 - 2] == 'K' || board[r1 + 1][c1 - 2] == 'Q' || board[r1 + 1][c1 - 2] == 'R' || board[r1 + 1][c1 - 2] == 'C' || board[r1 + 1][c1 - 2] == 'P' || board[r1 + 1][c1 - 2] == 'H') {
        if (i == r1 + 1 && j == c1 - 2) {
            count++;
        }
    }


    if (board[r1 - 1][c1 - 2] == ' ' || board[r1 - 1][c1 - 2] == 'K' || board[r1 - 1][c1 - 2] == 'Q' || board[r1 - 1][c1 - 2] == 'R' || board[r1 - 1][c1 - 2] == 'C' || board[r1 - 1][c1 - 2] == 'P' || board[r1 - 1][c1 - 2] == 'H')
    {
        if ((c1 - 2) != -1)
        {
            if (i == r1 - 1 && j == c1 - 2) {
                count++;
            }

        }
    }


    //

}
void che_horsew(int r1, int c1, int i, int  j) {
    if (board[r1 + 2][c1 + 1] == ' ' || board[r1 + 2][c1 + 1] == 'k' || board[r1 + 2][c1 + 1] == 'q' || board[r1 + 2][c1 + 1] == 'r' || board[r1 + 2][c1 + 1] == 'c' || board[r1 + 2][c1 + 1] == 'p' || board[r1 + 2][c1 + 1] == 'h') {
        if (i == r1 + 2 && j == c1 + 1) {
            count++;
        }
    }
    if (board[r1 + 2][c1 - 1] == ' ' || board[r1 + 2][c1 - 1] == 'k' || board[r1 + 2][c1 - 1] == 'q' || board[r1 + 2][c1 - 1] == 'r' || board[r1 + 2][c1 - 1] == 'c' || board[r1 + 2][c1 - 1] == 'p' || board[r1 + 2][c1 - 1] == 'h') {
        if ((c1 - 1) > -1) {
            if (i == r1 + 2 && j == c1 - 1) {
                count++;
            }

        }
    }

    if (board[r1 + 1][c1 + 2] == ' ' || board[r1 + 1][c1 + 2] == 'k' || board[r1 + 1][c1 + 2] == 'q' || board[r1 + 1][c1 + 2] == 'r' || board[r1 + 1][c1 + 2] == 'c' || board[r1 + 1][c1 + 2] == 'p' || board[r1 + 1][c1 + 2] == 'h') {
        if ((c1 + 2) != 8) {
            if (i == r1 + 1 && j == c1 + 2) {
                count++;
            }

        }
    }
    if (board[r1 - 1][c1 + 2] == ' ' || board[r1 - 1][c1 + 2] == 'k' || board[r1 - 1][c1 + 2] == 'q' || board[r1 - 1][c1 + 2] == 'r' || board[r1 - 1][c1 + 2] == 'c' || board[r1 - 1][c1 + 2] == 'p' || board[r1 - 1][c1 + 2] == 'h') {
        if (i == r1 - 1 && j == c1 + 2) {
            count++;
        }
    }

    if (board[r1 - 2][c1 - 1] == ' ' || board[r1 - 2][c1 - 1] == 'k' || board[r1 - 2][c1 - 1] == 'q' || board[r1 - 2][c1 - 1] == 'r' || board[r1 - 2][c1 - 1] == 'c' || board[r1 - 2][c1 - 1] == 'p' || board[r1 - 2][c1 - 1] == 'h')
    {
        if ((c1 - 1) != -1)
        {
            if (i == r1 - 2 && j == c1 - 1) {
                count++;
            }

        }
    }

    if (board[r1 - 2][c1 + 1] == ' ' || board[r1 - 2][c1 + 1] == 'k' || board[r1 - 2][c1 + 1] == 'q' || board[r1 - 2][c1 + 1] == 'r' || board[r1 - 2][c1 + 1] == 'c' || board[r1 - 2][c1 + 1] == 'p' || board[r1 - 2][c1 + 1] == 'h') {
        if (i == r1 - 2 && j == c1 + 1) {
            count++;
        }
    }

    if (board[r1 + 1][c1 - 2] == ' ' || board[r1 + 1][c1 - 2] == 'k' || board[r1 + 1][c1 - 2] == 'q' || board[r1 + 1][c1 - 2] == 'r' || board[r1 + 1][c1 - 2] == 'c' || board[r1 + 1][c1 - 2] == 'p' || board[r1 + 1][c1 - 2] == 'h') {
        if (i == r1 + 1 && j == c1 - 2) {
            count++;
        }
    }


    if (board[r1 - 1][c1 - 2] == ' ' || board[r1 - 1][c1 - 2] == 'k' || board[r1 - 1][c1 - 2] == 'q' || board[r1 - 1][c1 - 2] == 'r' || board[r1 - 1][c1 - 2] == 'c' || board[r1 - 1][c1 - 2] == 'p' || board[r1 - 1][c1 - 2] == 'h')
    {
        if ((c1 - 2) != -1)
        {
            if (i == r1 - 1 && j == c1 - 2) {
                count++;
            }

        }
    }

}
void checkcamelw(int r1, int c1, int i, int j) {
    int a, b;



    a = 1, b = 1;

    while (board[r1 - a][c1 + b] == 'k' || board[r1 - a][c1 + b] == ' ' || board[r1 - a][c1 + b] == 'q' | board[r1 - a][c1 + b] == 'r' || board[r1 - a][c1 + b] == 'c' | board[r1 - a][c1 + b] == 'p' || board[r1 - a][c1 + b] == 'h')
    {
        if ((r1 - a) == -1 || (c1 + b) == 8) break;
        if (board[r1 - a][c1 + b] == 'K' || board[r1 - a][c1 + b] == 'Q' | board[r1 - a][c1 + b] == 'R' || board[r1 - a][c1 + b] == 'C' | board[r1 - a][c1 + b] == 'P' || board[r1 - a][c1 + b] == 'H') { break; }
        if ((i == r1 - a) && (j == c1 + b)) {
            count++;
        }

        if (board[r1 - a][c1 + b] == 'k' || board[r1 - a][c1 + b] == 'q' | board[r1 - a][c1 + b] == 'r' || board[r1 - a][c1 + b] == 'c' | board[r1 - a][c1 + b] == 'p' || board[r1 - a][c1 + b] == 'h') { break; }
        a++;
        b++;
    }


    a = 1, b = 1;

    while (board[r1 + a][c1 - b] == 'k' || board[r1 + a][c1 - b] == ' ' || board[r1 + a][c1 - b] == 'q' || board[r1 + a][c1 - b] == 'r' || board[r1 + a][c1 - b] == 'c' || board[r1 + a][c1 - b] == 'p' || board[r1 + a][c1 - b] == 'h')
    {
        if ((r1 + a) == 8 || (c1 - b) == -1) break;
        if (board[r1 + a][c1 - b] == 'K' || board[r1 + a][c1 - b] == 'Q' || board[r1 + a][c1 - b] == 'R' || board[r1 + a][c1 - b] == 'C' || board[r1 + a][c1 - b] == 'P' || board[r1 + a][c1 - b] == 'H') {
            break;
        }
        if ((i == r1 + a) && (j == c1 - b)) {
            count++;
        }
        if (board[r1 + a][c1 - b] == 'k' || board[r1 + a][c1 - b] == 'q' || board[r1 + a][c1 - b] == 'r' || board[r1 + a][c1 - b] == 'c' || board[r1 + a][c1 - b] == 'p' || board[r1 + a][c1 - b] == 'h') {
            break;
        }
        a++;
        b++;
    }

    a = 1, b = 1;


    while (board[r1 + a][c1 + b] == 'k' || board[r1 + a][c1 + b] == ' ' || board[r1 + a][c1 + b] == 'q' || board[r1 + a][c1 + b] == 'r' || board[r1 + a][c1 + b] == 'c' || board[r1 + a][c1 + b] == 'p' || board[r1 + a][c1 + b] == 'h')
    {
        if ((r1 + a) == 8 || (c1 + b) == 8) break;
        if (board[r1 + a][c1 + b] == 'K' || board[r1 + a][c1 + b] == 'Q' || board[r1 + a][c1 + b] == 'R' || board[r1 + a][c1 + b] == 'C' || board[r1 + a][c1 + b] == 'P' || board[r1 + a][c1 + b] == 'H') {
            break;
        }
        if ((i == r1 + a) && (j == c1 + b)) {
            count++;
        }
        if (board[r1 + a][c1 + b] == 'k' || board[r1 + a][c1 + b] == 'q' || board[r1 + a][c1 + b] == 'r' || board[r1 + a][c1 + b] == 'c' || board[r1 + a][c1 + b] == 'p' || board[r1 + a][c1 + b] == 'h') {
            break;
        }
        a++;
        b++;
    }

    a = 1;
    b = 1;

    while (board[r1 - a][c1 - b] == 'k' || board[r1 - a][c1 - b] == ' ' || board[r1 - a][c1 - b] == 'q' || board[r1 - a][c1 - b] == 'r' || board[r1 - a][c1 - b] == 'c' || board[r1 - a][c1 - b] == 'p' || board[r1 - a][c1 - b] == 'h')
    {
        if ((r1 - a) == -1 || (c1 - b) == -1) break;
        if (board[r1 - a][c1 - b] == 'K' || board[r1 - a][c1 - b] == 'Q' || board[r1 - a][c1 - b] == 'R' || board[r1 - a][c1 - b] == 'C' || board[r1 - a][c1 - b] == 'P' || board[r1 - a][c1 - b] == 'H') { break; }
        if ((i == r1 - a) && (j == c1 - b)) {
            count++;
        }
        if (board[r1 - a][c1 - b] == 'k' || board[r1 - a][c1 - b] == 'q' || board[r1 - a][c1 - b] == 'r' || board[r1 - a][c1 - b] == 'c' || board[r1 - a][c1 - b] == 'p' || board[r1 - a][c1 - b] == 'h') {
            break;
        }
        a++;
        b++;
    }

}
void checkcamelb(int r1, int c1, int i, int j) {
    int a, b;



    a = 1, b = 1;

    while (board[r1 - a][c1 + b] == ' ' || board[r1 - a][c1 + b] == 'K' || board[r1 - a][c1 + b] == 'Q' | board[r1 - a][c1 + b] == 'R' || board[r1 - a][c1 + b] == 'C' | board[r1 - a][c1 + b] == 'P' || board[r1 - a][c1 + b] == 'H')
    {
        if ((r1 - a) == -1 || (c1 + b) == 8) break;

        if (board[r1 - a][c1 + b] == 'k' || board[r1 - a][c1 + b] == 'q' | board[r1 - a][c1 + b] == 'r' || board[r1 - a][c1 + b] == 'c' | board[r1 - a][c1 + b] == 'p' || board[r1 - a][c1 + b] == 'h') { break; }
        if ((i == r1 - a) && (j == c1 + b)) {
            count++;
        }

        if (board[r1 - a][c1 + b] == 'K' || board[r1 - a][c1 + b] == 'Q' | board[r1 - a][c1 + b] == 'R' || board[r1 - a][c1 + b] == 'C' | board[r1 - a][c1 + b] == 'P' || board[r1 - a][c1 + b] == 'H') { break; }

        a++;
        b++;
    }


    a = 1, b = 1;

    while (board[r1 + a][c1 - b] == ' ' || board[r1 + a][c1 - b] == 'K' || board[r1 + a][c1 - b] == 'Q' || board[r1 + a][c1 - b] == 'R' || board[r1 + a][c1 - b] == 'C' || board[r1 + a][c1 - b] == 'P' || board[r1 + a][c1 - b] == 'H')
    {
        if ((r1 + a) == 8 || (c1 - b) == -1) break;

        if (board[r1 + a][c1 - b] == 'k' || board[r1 + a][c1 - b] == 'q' || board[r1 + a][c1 - b] == 'r' || board[r1 + a][c1 - b] == 'c' || board[r1 + a][c1 - b] == 'p' || board[r1 + a][c1 - b] == 'h') {
            break;
        }
        if ((i == r1 + a) && (j == c1 - b)) {
            count++;
        }
        //printf("%d%d , ", r1 + a, c1 - b);
        if (board[r1 + a][c1 - b] == 'K' || board[r1 + a][c1 - b] == 'Q' || board[r1 + a][c1 - b] == 'R' || board[r1 + a][c1 - b] == 'C' || board[r1 + a][c1 - b] == 'P' || board[r1 + a][c1 - b] == 'H') {
            break;
        }


        a++;
        b++;
    }

    a = 1, b = 1;


    while (board[r1 + a][c1 + b] == ' ' || board[r1 + a][c1 + b] == 'K' || board[r1 + a][c1 + b] == 'Q' || board[r1 + a][c1 + b] == 'R' || board[r1 + a][c1 + b] == 'C' || board[r1 + a][c1 + b] == 'P' || board[r1 + a][c1 + b] == 'H')
    {
        if ((r1 + a) == 8 || (c1 + b) == 8) break;
        if (board[r1 + a][c1 + b] == 'k' || board[r1 + a][c1 + b] == 'q' || board[r1 + a][c1 + b] == 'r' || board[r1 + a][c1 + b] == 'c' || board[r1 + a][c1 + b] == 'p' || board[r1 + a][c1 + b] == 'h') {
            break;
        }
        if ((i == r1 + a) && (j == c1 + b)) {
            count++;
        }
        //printf("%d%d , ", r1 + a, c1 + b);


        if (board[r1 + a][c1 + b] == 'K' || board[r1 + a][c1 + b] == 'Q' || board[r1 + a][c1 + b] == 'R' || board[r1 + a][c1 + b] == 'C' || board[r1 + a][c1 + b] == 'P' || board[r1 + a][c1 + b] == 'H') {
            break;
        }

        a++;
        b++;
    }

    a = 1;
    b = 1;

    while (board[r1 - a][c1 - b] == ' ' || board[r1 - a][c1 - b] == 'K' || board[r1 - a][c1 - b] == 'Q' || board[r1 - a][c1 - b] == 'R' || board[r1 - a][c1 - b] == 'C' || board[r1 - a][c1 - b] == 'P' || board[r1 - a][c1 - b] == 'H')
    {
        if ((r1 - a) == -1 || (c1 - b) == -1) break;

        if (board[r1 - a][c1 - b] == 'k' || board[r1 - a][c1 - b] == 'q' || board[r1 - a][c1 - b] == 'r' || board[r1 - a][c1 - b] == 'c' || board[r1 - a][c1 - b] == 'p' || board[r1 - a][c1 - b] == 'h') {
            break;
        }
        if ((i == r1 - a) && (j == c1 - b)) {
            count++;
        }
        //printf("%d%d , ", r1 - a, c1 - b);

        if (board[r1 - a][c1 - b] == 'K' || board[r1 - a][c1 - b] == 'Q' || board[r1 - a][c1 - b] == 'R' || board[r1 - a][c1 - b] == 'C' || board[r1 - a][c1 - b] == 'P' || board[r1 - a][c1 - b] == 'H') { break; }


        a++;
        b++;
    }
}
void kmovb() {
    int r1, c1;
    kmoves = 0;
    for (r1 = 0; r1 < 8; r1++) {
        for (c1 = 0; c1 < 8; c1++) {
            if (board[r1][c1 + 1] == ' ' || board[r1][c1 + 1] == 'Q' || board[r1][c1 + 1] == 'H' || board[r1][c1 + 1] == 'C' || board[r1][c1 + 1] == 'R' || board[r1][c1 + 1] == 'P') {
                //printf("%d%d , ", r1, c1 + 1);
                kmoves++;
            }

            if (board[r1][c1 - 1] == ' ' || board[r1][c1 - 1] == 'Q' || board[r1][c1 - 1] == 'H' || board[r1][c1 - 1] == 'C' || board[r1][c1 - 1] == 'R' || board[r1][c1 - 1] == 'P') {
                //printf("%d%d , ", r1, c1 - 1);
                kmoves++;
            }

            if (board[r1 + 1][c1] == ' ' || board[r1 + 1][c1] == 'Q' || board[r1 + 1][c1] == 'H' || board[r1 + 1][c1] == 'C' || board[r1 + 1][c1] == 'R' || board[r1 + 1][c1] == 'P') {
                //printf("%d%d , ", r1 + 1, c1);
                kmoves++;
            }

            if (board[r1 - 1][c1] == ' ' || board[r1 - 1][c1] == 'Q' || board[r1 - 1][c1] == 'H' || board[r1 - 1][c1] == 'C' || board[r1 - 1][c1] == 'R' || board[r1 - 1][c1] == 'P') {
                //printf("%d%d , ", r1 - 1, c1);
                kmoves++;
            }

            if (board[r1 + 1][c1 + 1] == ' ' || board[r1 + 1][c1 + 1] == 'Q' || board[r1 + 1][c1 + 1] == 'H' || board[r1 + 1][c1 + 1] == 'C' || board[r1 + 1][c1 + 1] == 'R' || board[r1 + 1][c1 + 1] == 'P') {
                //printf("%d%d , ", r1 + 1, c1 + 1);
                kmoves++;

            }

            if (board[r1 - 1][c1 - 1] == ' ' || board[r1 - 1][c1 - 1] == 'Q' || board[r1 - 1][c1 - 1] == 'H' || board[r1 - 1][c1 - 1] == 'C' || board[r1 - 1][c1 - 1] == 'R' || board[r1 - 1][c1 - 1] == 'P') {
               // printf("%d%d , ", r1 - 1, c1 - 1);
                kmoves++;
            }

            if (board[r1 - 1][c1 + 1] == ' ' || board[r1 - 1][c1 + 1] == 'Q' || board[r1 - 1][c1 + 1] == 'H' || board[r1 - 1][c1 + 1] == 'C' || board[r1 - 1][c1 + 1] == 'R' || board[r1 - 1][c1 + 1] == 'P') {
                //printf("%d%d , ", r1 - 1, c1 + 1);
                kmoves++;
            }

            if (board[r1 + 1][c1 - 1] == ' ' || board[r1 + 1][c1 - 1] == 'Q' || board[r1 + 1][c1 - 1] == 'H' || board[r1 + 1][c1 - 1] == 'C' || board[r1 + 1][c1 - 1] == 'R' || board[r1 + 1][c1 - 1] == 'P') {
                //printf("%d%d , ", r1 + 1, c1 - 1);
                kmoves++;
            }
        }
    }
    
}
void kmovw() {
    kmoves = 0;
    int r1, c1;
    for (r1 = 0; r1 < 8; r1++) {
        for (c1 = 0; c1 < 8; c1++) {
            
            //printf("Available are: ");
            if (board[r1][c1 + 1] == ' ' || board[r1][c1 + 1] == 'q' || board[r1][c1 + 1] == 'h' || board[r1][c1 + 1] == 'c' || board[r1][c1 + 1] == 'r' || board[r1][c1 + 1] == 'p') {
               // printf("%d%d , ", r1, c1 + 1);
                kmoves++;
            }

            if (board[r1][c1 - 1] == ' ' || board[r1][c1 - 1] == 'q' || board[r1][c1 - 1] == 'h' || board[r1][c1 - 1] == 'c' || board[r1][c1 - 1] == 'r' || board[r1][c1 - 1] == 'p') {
                //printf("%d%d , ", r1, c1 - 1);
                kmoves++;
            }

            if (board[r1 + 1][c1] == ' ' || board[r1 + 1][c1] == 'q' || board[r1 + 1][c1] == 'h' || board[r1 + 1][c1] == 'c' || board[r1 + 1][c1] == 'r' || board[r1 + 1][c1] == 'p') {
                //printf("%d%d , ", r1 + 1, c1);
                kmoves++;
            }

            if (board[r1 - 1][c1] == ' ' || board[r1 - 1][c1] == 'q' || board[r1 - 1][c1] == 'h' || board[r1 - 1][c1] == 'c' || board[r1 - 1][c1] == 'r' || board[r1 - 1][c1] == 'p') {
                //printf("%d%d , ", r1 - 1, c1);
                kmoves++;
            }

            if (board[r1 + 1][c1 + 1] == ' ' || board[r1 + 1][c1 + 1] == 'q' || board[r1 + 1][c1 + 1] == 'h' || board[r1 + 1][c1 + 1] == 'c' || board[r1 + 1][c1 + 1] == 'r' || board[r1 + 1][c1 + 1] == 'p') {
                //printf("%d%d , ", r1 + 1, c1 + 1);
                kmoves++;
            }

            if (board[r1 - 1][c1 - 1] == ' ' || board[r1 - 1][c1 - 1] == 'q' || board[r1 - 1][c1 - 1] == 'h' || board[r1 - 1][c1 - 1] == 'c' || board[r1 - 1][c1 - 1] == 'r' || board[r1 - 1][c1 - 1] == 'p') {
               // printf("%d%d , ", r1 - 1, c1 - 1);
                kmoves++;
            }

            if (board[r1 - 1][c1 + 1] == ' ' || board[r1 - 1][c1 + 1] == 'q' || board[r1 - 1][c1 + 1] == 'h' || board[r1 - 1][c1 + 1] == 'c' || board[r1 - 1][c1 + 1] == 'r' || board[r1 - 1][c1 + 1] == 'p') {
               // printf("%d%d , ", r1 - 1, c1 + 1);
                kmoves++;
            }

            if (board[r1 + 1][c1 - 1] == ' ' || board[r1 + 1][c1 - 1] == 'q' || board[r1 + 1][c1 - 1] == 'h' || board[r1 + 1][c1 - 1] == 'c' || board[r1 + 1][c1 - 1] == 'r' || board[r1 + 1][c1 - 1] == 'p') {
               // printf("%d%d , ", r1 + 1, c1 - 1);
                kmoves++;
            }
        }
    }

}
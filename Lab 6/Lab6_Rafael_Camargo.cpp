#include <stdio.h>
#include <conio.h>
#include <conio2.h>
int main ()
{
    int a, b, i, j, k, demora = 2000000;
    printf ("Maximize a tela e digite algo: ");
    getche ();
    clrscr ();

    gotoxy(13,3);
    printf("CONTEMPLE O SURGIMENTO E DESAPARECIMENTO DO CARACOL CELESTIAL");


    printf("\r");

    for(j = 80; j >0 ; j--)
    {
        textbackground(WHITE);
        for (i = 85-j; i <= j; i++)
        {
            gotoxy (i, 85-j);
            printf (" ");
            for (k = 1; k <= demora; k++);
        }
        for (i = 84-j; i <= j; i++)
        {

            gotoxy (j, i+1);
            printf (" ");
            for (k = 1; k <= demora; k++);
        }
        for (i = j; i >= 85-j; i--)
        {
            gotoxy (i, j+1);
            printf (" ");
            for (k = 1; k <= demora; k++);
        }
        for (i = j; i >= 85-j; i--)
        {
            gotoxy (85-j, i);
            printf (" ");
            for (k = 1; k <= demora; k++);
        }
    }
    for(j = 0; j <80 ; j++)
    {
        textbackground(BLACK);
        for (i = j-1; i >= 84-j; i--)
        {
            gotoxy (j, i+1);
            printf (" ");
            for (k = 1; k <= demora; k++);
        }
        for (i = j-1; i > 85-j; i--)
        {
            gotoxy (i, 85-j);
            printf (" ");
            for (k = 1; k <= demora; k++);
        }
        for (i = 85-j; i <= j+1; i++)
        {
            gotoxy (85-j, i);
            printf (" ");
            for (k = 1; k <= demora; k++);
        }
        for (i = 86-j; i <= j; i++)
        {
            gotoxy (i, j+1);
            printf (" ");
            for (k = 1; k <= demora; k++);
        }
    }

    gotoxy (42, 42);
    printf("FIM!");

    gotoxy (32, 43);

    printf ("Digite algo para encerrar: ");
    getch ();
    return 0;
}

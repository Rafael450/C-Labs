#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char c;
    int n, i, achou;
    printf("DIVISORES DE VARIOS NUMEROS MAIORES QUE 1\n");
    do
    {
        printf("\nDivisores de um numero?(s/n) ");
        do
        {
            scanf(" %c", &c);
        }while(c != 's' && c != 'n' && c != 'S' && c != 'N');
        if(c == 's' || c == 'S')
        {
            printf("\nDigite um numero maior que 1:  ");
            scanf(" %d", &n);
            while(n<2)
            {
                printf("\nNumero improprio; digite novamente: ");
                scanf(" %d", &n);
            }
            printf("\nDivisores de %d : \n", n);
            i = 2;
            achou = 0;
            while(i <= n/2)
            {
                if(n % i == 0)
                {
                    printf("\n\t%d ", i);
                    achou = 1;
                }
                i = i+1;
            }
            if(achou == 0)
            {
                printf("\n%d eh primo", n);
            }
            printf("\n");

        }
    }while(c == 's' || c == 'S');



    printf("\n");
    system("pause");
    return 0;
}



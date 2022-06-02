//versao2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    int x, m, n; float pi = 3.14159265358979323846;
    printf("Digite o limite inferior da tabela: ");
    scanf("%d", &m);
    printf("Digite o limite superior da tabela: ");
    scanf("%d", &n);
    printf("\n\t\t**********************************************************************");
    printf("\n\t\t*       x *   x^4-20x^2+5 *       sen(x) *                 x^7/ln(x) *");
    printf("\n\t\t* ------------------------------------------------------------------ *");
    x=m;
    while(x <= n)
    {
        if (x > 0 && x != 1 )
        {
            printf("\n\t\t*%8d *%14d *%13.7f *%26.8f *", x, x*x*x*x-20*x*x+5, sin(x*pi/180), pow(x, 7)/(log(x)));
        }
        else
        {
            printf("\n\t\t*%8d *%14d *%13.7f *%26s *", x, x*x*x*x-20*x*x+5, sin(x*pi/180), "----------");
        }
        x=x+1;
    }
    printf("\n\t\t**********************************************************************");
    printf("\n\n");
    system("pause"); system("pause");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n, cont, num, npar, n37, fat, aux1, aux2, maior, menor, fibo;
    float mediari, soma;
    char lixo;

    n=0;
    while(n==0)
    {
        printf("Digite o numero de termos: ");
        scanf(" %d%c", &n, &lixo);
        if(n <= 0)
        {
            printf("\nO numero digitado nao eh positivo. Tente novamente.\n\n");
            n = 0;
        }

    }
    cont = 1;
    npar = 0;
    n37=0;
    soma = 0;
    while(cont <= n)
    {
        printf("Digite o %do numero: ", cont);
        scanf(" %d%c", &num, &lixo);
        //
        soma = soma + num;
        //
        if(num % 2 ==0)
        {
            npar = npar + 1;
        }
        //
        if(num % 3 == 0 || num % 7 == 0)
        {
            n37 = n37 + 1;
        }
        //
        fat = 1;
        aux1 = 1;
        aux2 = 1;
        if(num==1)
        {
            printf("\n\t1 eh fatorial igual a 1!\n\n", num, aux2);
        }
        while( num > fat)
        {
            fat = fat*aux2;
            if(num == fat)
            {
                printf("\n\t%d eh fatorial igual a %d!\n\n", num, aux2);
            }
            aux2= aux2 + 1;


        }
        //
        if(cont==1)
        {
            menor = num;
            maior = num;
        }
        if(num > maior)
        {
            maior = num;
        }
        if(num < menor)
        {
            menor = num;
        }
        //
        aux1 = 1;
        aux2 = 0;
        fibo = 0;
        if (num==0)
        {
            printf("\n\t0 eh um dos termos da Serie de Fibonacci\n\n", num);
        }
        while(num > fibo )
        {
            fibo = aux1 + aux2;
            aux2 = aux1;
            aux1 = fibo;
            if(num == fibo)
            {
                printf("\n\t%d eh um dos termos da Serie de Fibonacci\n\n", num);
            }
        }


        cont = cont + 1;
    }
    mediari= soma/n;
    printf("\n\n\t MEDIA ARITIMETICA: %f\n", mediari);
    printf("\n\n\t NUMERO DE PARES: %d\n", npar);
    printf("\n\n\t NUMERO DE MULTIPLOS DE 3 OU 7: %d\n", n37 );
    printf("\n\n\t MAIOR NUMERO DIGITADO: %d\t\t MENOR NUMERO DIGITADO: %d\n", maior, menor);

    printf("\n\n");
    system("pause");
    return 0;
}



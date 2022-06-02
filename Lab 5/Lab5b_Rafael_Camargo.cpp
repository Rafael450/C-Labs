#include <stdio.h>
#include <stdlib.h>

/* Cabecalho, declaracoes e digitacao do numero de cadeias */

int main()
{ //  Inicio da funcao main
    char c, carac;
    int estado, i, n;
    printf("C A D E I A S   N U M E R I C A S");
    printf("\n\nNumero de cadeiras a serem testadas: ");
    scanf(" %d", &n);
    for (i = 1; i <= n; i++)
    {

        /* Digitacao da cadeia a ser testada */

        printf("\n\nDigite a %da cadeia encerrada por <enter>: ", i);
        /* Percurso no automato usando os caracteres da cadeia */

        for (estado = 1, scanf(" %c", &carac); carac != '\n'; scanf("%c", &carac))
        {
            switch (estado)
            {
            case 1: // Teste do caractere no estado 1
                switch (carac)
                {
                case '+': case '-':
                    estado = 2;
                    break;
                case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0':
                    estado = 3;
                    break;
                case '.':
                    estado = 4;
                    break;
                default:
                    estado = 9;
                }
                break;
            case 2: // Teste do caractere no estado 2
                switch (carac)
                {
                case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0':
                    estado = 3;
                    break;
                case '.':
                    estado = 4;
                    break;
                default:
                    estado = 9;
                }
                break;
            case 3: // Teste do caractere no estado 3
                switch (carac)
                {
                case 'E': case 'e':
                    estado = 6;
                    break;
                case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0':
                    estado = 3;
                    break;
                case '.':
                    estado = 5;
                    break;
                default:
                    estado = 9;
                }
                break;
            case 4: // Teste do caractere no estado 4
                switch (carac)
                {
                case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0':
                    estado = 5;
     
                    break;
                default:
                    estado = 9;
                }
                break;
            case 5: // Teste do caractere no estado 5
                switch (carac)
                {
                case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0':
                    estado = 5;
                    break;
                case 'E': case 'e':
                    estado = 6;
                    break;
                default:
                    estado = 9;
                }
                break;
            case 6: // Teste do caractere no estado 6
                switch (carac)
                {
                case '+': case '-':
                    estado = 7;
                    break;
                case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0':
                    estado = 8;
                    break;
                default:
                    estado = 9;
                }
                break;
            case 7: // Teste do caractere no estado 7
                switch (carac)
                {
                case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0':
                    estado = 8;
                    break;
                default:
                    estado = 9;
                }
                break;
            case 8: // Teste do caractere no estado 8
                switch (carac)
                {
                case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0':
                    estado = 8;
                    break;
                default:
                    estado = 9;
                }
                break;
            case 9: // Acao para o estado 9 (dispensavel)
                switch (carac)
                {
                default:
                    estado = 9;
                }
                break;
            }
        }
        /* Escrita do resultado do teste */

        if (estado != 3 && estado != 5 && estado != 8)
            printf("\n\tCadeia reprovada!");
        else
            printf("\n\tCadeia aprovada!");

    }

    /* Fechamento da tela */

    printf("\n\n");
    system("pause");
    return 0;

} //Fim da funcao main e do programa

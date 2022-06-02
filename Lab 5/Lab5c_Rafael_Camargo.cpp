#include <stdio.h>
#include <stdlib.h>

/* Cabecalho, declaracoes e digitacao do numero de cadeias */

int main () {   //  Inicio da funcao main
 	char c, carac, lixo;
 	int estado, i, n;
 	printf ("C A D E I A S   B I N A R I A S");
 	printf ("\n\nNumero de cadeiras a serem testadas: ");
 	scanf ("%d%c", &n, &lixo);
	for (i = 1; i <= n; i++) 
    {

/* Digitacao da cadeia a ser testada */

 		printf ("\n\nDigite a %da cadeia encerrada por <enter>: ", i);
/* Percurso no automato usando os caracteres da cadeia */

        for (estado = 1, scanf ("%c", &carac); carac != '\n'; scanf ("%c", &carac))
        {

            switch (estado) 
            {
                case 1:         // Teste do caractere no estado 1
                    switch (carac) 
                    {
                        case '1': estado = 2;; break;
                        case '0': estado = 3;; break;
                        default: estado = 4;
                    }
                    break;
                case 2:         // Teste do caractere no estado 2
                    switch (carac) 
                    {
                        case '0': estado = 3; break;
                        default: estado = 4;
                    }
                    break;
                case 3:         // Teste do caractere no estado 3
                    switch (carac) 
                    {
                        case '1': estado = 2; break;
                        default: estado = 4;
                    }
                    break;
                case 4:         // Acao para o estado 4 (dispensavel)
                    switch (carac) 
                    {
                        default: estado = 4;
                    }
                    break;
            }
        }
/* Escrita do resultado do teste */

      	if (estado == 1 || estado == 4)
            printf ("\n\tCadeia reprovada!");
      	else
        	printf ("\n\tCadeia aprovada!");
	}

/* Fechamento da tela */

	printf ("\n\n"); system ("pause");
	return 0;

}       //Fim da funcao main e do programa

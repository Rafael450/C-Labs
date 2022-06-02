#include <stdio.h>
#include <stdlib.h>

int main () 
{   
    //declaracao das variaveis
    FILE *FileIn, *FileOut;
    int A[100][100], B[100][100] = {0}, Vzero[100], Vmenor[100], Vimpar[100]; // iguala-se os elementos da matriz B a zero para evitar problemas de memória
    float Vmed[100];
    int m, n, i, j, k, l, zero, menor, impar; 

 	FileIn = fopen("input.txt", "r"); // abertura arquivo do input

    //impressao dos dados no terminal
    printf("MATRIZES BIDIMENSIONAIS NUMERICAS\n\n");
    printf("Nome do arquivo de entrada: input.txt\n");
    printf("Nome do arquivo com os resultados: output.txt\n");

    //leitura da input
    fscanf(FileIn, "%d %d", &m, &n);    
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            fscanf(FileIn, "%d", &A[i][j]); // Colocando a matriz do input na matriz A
        }
    }

    //montagem do vetor com os numeros maiores que zero em cada coluna da matriz

    for(j = 0; j < n; j++)
    {
        for(i = 0, zero = 0; i < m; i++)
        {
            if(A[i][j] > 0)
                zero++;
        }
        Vzero[j] = zero;
    }

    //montagem do vetor com a media aritimetica com dos quadrados das linhas da matriz

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            Vmed[i] += A[i][j]*A[i][j];
        }
    }

    //montagem do vetor com o menor numero numa coluna da matriz

    for(j = 0; j < n; j++)
    {
        for(i = 0, menor = A[0][j]; i < m; i++)
        {
            if(A[i][j] < menor)
                menor = A[i][j];
        }
        Vmenor[j] = menor;
    }
    //montagem do vetor com a quantidade de numeros impares em cada linha da matriz
 
    for(i = 0; i < m; i++)
    {
        for(j = 0, impar = 0; j < n; j++)
        {
            if(A[i][j] % 2 != 0)
            {
                impar++;
            }
            Vimpar[i] = impar;
        }
    }

    //montagem da matriz B a qual cada elemento representa a soma dos elementos pertencente as diagonais

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            for(k = i, l = j; l <= n && k <= m; k++, l++)
            {
                B[i][j] += A[k][l];
            }
            for(k = i, l = j; l <= n && k >= 0; k--, l++)
            {
                B[i][j] += A[k][l];
            }
            for(k = i, l = j; l >= 0 && k >= 0; k--, l--)
            {
                B[i][j] += A[k][l];
            }
            for(k = i, l = j; l >= 0 && k <= m; k++, l--)
            {
                B[i][j] += A[k][l];
            }
            B[i][j] -= 3*A[i][j];
        }
    }

    //Montagem do output.txt

    FileOut = fopen("output.txt", "w"); //abertura do arquivo do output
    fprintf(FileOut, "Matriz A:\n\n");
    fprintf(FileOut, "%*s", 13+12*n, "Elementos |");
    //montagem da matriz A com as informacoes solicitadas
    fprintf(FileOut, "Med dos Quad|   Impares  |\n------------");
    for(i = 0; i < n; i++)
    {
        fprintf(FileOut, "------------");
    }
    fprintf(FileOut, "|------------|------------|\n");
    //Print da matriz A, e das informacoes dos vetores com a media dos quadrados e quantidade de numeros impares
    for(i = 0; i < m ; i++)
    {
        fprintf(FileOut, "Linha %-5d:", i+1);
        for(j = 0; j < n; j++)
        {
            fprintf(FileOut, "%12d", A[i][j]);
        }
        fprintf(FileOut, "|%12.3f|%12d|\n", Vmed[i]/n, Vimpar[i]);
    }
    for(i = 0; i < n+1; i++)
    {
        fprintf(FileOut, "------------");
    }
    fprintf(FileOut, "|------------|------------|\n> zero:     ");
    //Impressao das informacoes dos vetores com a quantidade de numeros maiores que zero e o menor numero de cada coluna no terminal
    for(j = 0; j < n; j++)
    {
        fprintf(FileOut, "%12d", Vzero[j]);
    }
    fprintf(FileOut, "|\nMenor:      ");
    for(j = 0; j < n; j++)
    {
        fprintf(FileOut, "%12d", Vmenor[j]);
    }
    //Impressao da matriz B no terminal
    fprintf(FileOut, "|\n\nMatriz B:\n\n");
    for(i = 0; i < n+1; i++)
    {
        fprintf(FileOut, "------------");
    }
    for (i = 0; i < m; i++) 
    {
        fprintf(FileOut, "\nLinha %-5d:", i+1);
		for (j = 0; j < n; j++) 
			fprintf(FileOut, "%12d", B[i][j]);
		fprintf(FileOut, "|");
	}
    fprintf(FileOut, "\n");
    for(i = 0; i < n+1; i++)
    {
        fprintf(FileOut, "------------");
    }
    //fechamento dos arquivos
    fclose(FileIn);
    fclose(FileOut);
    // finalização
    printf("\n\n"); 
    system("pause");
	return 0;

}

#include <stdio.h>
#include <stdlib.h>

typedef struct matquadrada matquadrada;
struct matquadrada
{
    int n;
    double elem[10][10];
};

int somas(int n)
{
    if(n == 1) 
        return 0;
    else if(n == 2)
        return 1;
    else if(n == 3)
        return 5;
    else
        return (somas(n-1)+1)*n;
}

int multiplicacoes(int n)
{
    if(n == 1) 
        return 0;
    else if(n == 2)
        return 2;
    else if(n == 3)
        return 12;
    else
        return (multiplicacoes(n-1)+1)*n;
}

void LerMatQuadrada(matquadrada *Mat, int n)
{
    char c;
    FILE *FileIn;
    FileIn = fopen("input.txt", "r");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fscanf(FileIn, "%lf", &(*Mat).elem[i][j]);
        do
            fscanf (FileIn, "%c", &c);
        while (c != '\n');
    }
    fclose(FileIn);
}

matquadrada MenorComplementar(matquadrada *Mat, int i, int j)
{
    matquadrada D;
    D.n = (*Mat).n-1;
    for(int k = 0; k < (*Mat).n; k++)
    {
        for(int l = 0; l < (*Mat).n; l++)
        {
            if(k < i && l < j)
                D.elem[k][l] = (*Mat).elem[k][l];
            else if(k > i && l < j)
                D.elem[k-1][l] = (*Mat).elem[k][l];
            else if(l > j && k < i)
                D.elem[k][l-1] = (*Mat).elem[k][l];
            else if(k > i && l > j )
                D.elem[k-1][l-1] = (*Mat).elem[k][l];
        }
    }
    return D;
}

double det(matquadrada *Mat, int n)
{
    double sum = 0;
    if(n <= 0) return -999999999;
    else if(n == 1) return (*Mat).elem[0][0];
    else if(n == 2) return (*Mat).elem[0][0]*(*Mat).elem[1][1] - (*Mat).elem[1][0]*(*Mat).elem[0][1];
    else if(n == 3) return (*Mat).elem[0][0]*(*Mat).elem[1][1]*(*Mat).elem[2][2] + (*Mat).elem[0][1]*(*Mat).elem[1][2]*(*Mat).elem[2][0] + (*Mat).elem[0][2]*(*Mat).elem[1][0]*(*Mat).elem[2][1] -
                           (*Mat).elem[0][1]*(*Mat).elem[1][0]*(*Mat).elem[2][2] - (*Mat).elem[0][0]*(*Mat).elem[1][2]*(*Mat).elem[2][1] - (*Mat).elem[0][2]*(*Mat).elem[1][1]*(*Mat).elem[2][0];
    else
        for(int i = 0; i < n; i++)
        {
            matquadrada x = MenorComplementar(Mat, i, 0);
            if(i % 2 == 0)
                sum+=(*Mat).elem[i][0]*det(&x, n-1);
            else
                sum-=(*Mat).elem[i][0]*det(&x, n-1);
        }
    return sum;
}
void EscreverMatQuadrada(matquadrada *Mat)
{
    printf("\n\nMatriz com dimensao %d:", (*Mat).n);
    for(int i = 0; i < (*Mat).n; i++)
    {
        printf("\n|");
        for(int j = 0; j < (*Mat).n; j++)
            printf("%5.0lf", (*Mat).elem[i][j]);
        printf("|");
    }
    printf("\nValor do determinante: %20.0lf", det(Mat, (*Mat).n));

}
int main()
{
    matquadrada A;
    printf("Calculo de determinante com instrumentacao");
    for(A.n = 1; A.n <= 10; A.n++)
    {
        LerMatQuadrada(&A, A.n);
        EscreverMatQuadrada(&A);
    }
    printf("\n\nNumeros de somas+subtracoes e multiplicacoes:\n\n");
    for(int i = 1; i <= 10; i++)
        printf("Dimensao:%4d%13d somas+subtracoes %8d multiplicacoes\n", i, somas(i), multiplicacoes(i));
    system("pause");
    return 0;
}

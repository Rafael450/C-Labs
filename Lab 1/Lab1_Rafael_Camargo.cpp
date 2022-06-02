//3ª versão
#include <stdio.h>
#include <stdlib.h>

int main(){
    int aluno, numal, numcad, numcan, numlap,numbor; float precocad, precocan, precolap, precobor, total;
    printf("COMPRA DE MATERIAL ESCOLAR:");
    printf("\nDigite o numero de alunos:");
    scanf("%d", &numal); printf("\n"); aluno = 1;
    while(aluno <= numal){
        printf("Aluno %d: \n\n\tNumero de cadernos: ", aluno); scanf("%d", &numcad);
        printf("\n\tPreco do caderno: "); scanf("%f", &precocad);

        printf("\n\n\tNumero de canetas: "); scanf("%d", &numcan);
        printf("\n\tPreco da caneta: "); scanf("%f", &precocan);

        printf("\n\n\tNumero de lapis: "); scanf("%d", &numlap);
        printf("\n\tPreco do lapis: "); scanf("%f", &precolap);

        printf("\n\n\tNumero de borrachas: "); scanf("%d", &numbor);
        printf("\n\tPreco da borracha: "); scanf("%f", &precobor);
        total=precocad*numcad+precocan*numcan+precolap*numlap+precobor*numbor;

        printf("\n\n\tAluno %d", aluno);
        printf("\n\t\t%d cadernos a R$%.1f cada", numcad, precocad);
        printf("\n\t\t%d canetas a R$%.1f cada", numcan, precocan);
        printf("\n\t\t%d lapis a R$%.1f cada", numlap, precolap);
        printf("\n\t\t%d borrachas a R$%.1f cada", numbor, precobor);
        printf("\n\tGasto total: R$%.1f\n\n", total);

        aluno = aluno + 1;
    }
    printf("\n\n");
    system("pause");
    return 0;
}

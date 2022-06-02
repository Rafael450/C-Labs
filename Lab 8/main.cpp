//2ª versão
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char logic;
const logic True = 1, False = 0;
typedef char cadeia[30];

typedef struct numero numero;
struct numero
{
    cadeia valnabase; 
    int base, valdecimal;
    logic valido;
};

typedef struct tabela tabela;
struct tabela
{
    numero VetNum[51];
    int ntab;
};


int main()
{
	numero num;
    tabela TabNum;
    int i, j, n, soma;
    FILE *FileIn,*FileOut;
    FileIn = fopen("input.txt", "r");
    TabNum.ntab = 0;

  	fscanf(FileIn, " %d", &TabNum.ntab);    
    for(i = 0; i < TabNum.ntab; i++)
    {
        fscanf(FileIn, " %s %d", num.valnabase, &num.base);
        num.valido = True;
        num.valdecimal = 0;
        if(num.base > 20 || num.base < 2)
            num.valido = False;
        for(j = 0; j < strlen(num.valnabase) && num.valido == True; j++)
        {
            if(num.valnabase[j] < '0' || (num.valnabase[j] >= ('0'+num.base) && num.valnabase[j] < 'A') || num.valnabase[j] >= ('A'+num.base-10))
                num.valido = False;
        }
        if(num.valido == True)
        {
            for(j = 0; j < strlen(num.valnabase); j++)
            {
                if(num.valnabase[j] <= '9')
                    num.valdecimal = num.valdecimal*num.base + num.valnabase[j] - '0';
                else
                    num.valdecimal = num.valdecimal*num.base + 10 + num.valnabase[j] - 'A';
            }
        }
        else
        {
            num.valdecimal = -1;
        }
        TabNum.VetNum[i] = num;
    }
    for(i = 0; i < TabNum.ntab; i++)
    {
        if(TabNum.VetNum[i].valido == True)
            soma += TabNum.VetNum[i].valdecimal;
    }
    fclose(FileIn);
    FileOut = fopen("output.txt", "w");
    fprintf(FileOut,"C O N V E R S O E S   D E   B A S E S   P A R A   A   B A S E   10\n\nForam realizadas %d conversoes:\n\n", TabNum.ntab);
    for(i = 0; i < TabNum.ntab; i++)
    {
        if(TabNum.VetNum[i].valido == True)
            fprintf(FileOut,"\t(%s)%d = (%d)10\n", TabNum.VetNum[i].valnabase, TabNum.VetNum[i].base, TabNum.VetNum[i].valdecimal);
        else
            fprintf(FileOut,"\t(%s)%d = Dados incompativeis\n", TabNum.VetNum[i].valnabase, TabNum.VetNum[i].base);
    }
    fprintf(FileOut,"\nSomatoria dos numeros validos = (%d)10", soma);
    fclose(FileOut);
    printf("\n\n");
    system("pause");
	return 0;
}

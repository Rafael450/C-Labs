#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

typedef char logic;
const logic True = 1, False = 0;
typedef struct celula celula;
typedef celula* pont;
struct celula {
	int num; 
    pont prox;
};
typedef pont numero;
numero NovoEncadeamento()
{
	int y;
    logic detailOne = True, first = True, digit = False, last = False;
    char c, cadeia[104];
    cadeia[0] = '0'; cadeia[1] = '0'; cadeia[2] = '0'; cadeia [3] = '0', cadeia [4] = '0';
    numero p, q;
  	p = (numero) malloc (sizeof(celula));
	p->prox = NULL;
    q = p;
    for(y = 0, scanf (" %c", &c); ((c != '\n' && digit) || (first && !digit)) && !last; scanf ("%c", &c), y = (first == True) ? y : y+1)
    {
        if(c >= '0' && c <= '9')
        {
            if(first && c !='0')
            {
                cadeia[4] = c;
                first = False;
                digit = True;
            }
            else if(first && c == '0')
                digit = True;
            else if(!first)
                cadeia[y+4] = c;
        }
        else if((c != '\n' || first == False) && c != ' ')
        {
            detailOne = False;
            c = '\n';
        }
        else if(c == ' ')
        { 
            last = True;
            y--;
        }
    }
    cadeia[y+4] = '\0';
    if(detailOne)
        for(int i = strlen(cadeia); i > 4;i-=4)
        {
            p->prox = (numero) malloc (sizeof(celula));
            p = p->prox;
            p->num = 0;
            for(int j = 4; j > 0; j--)
            {
                p->num = p->num*10 + cadeia[i-j]-'0';
            }
            p->prox = NULL;
        }
    else
    {
        p->prox = (numero) malloc (sizeof(celula));
        p = p->prox;
        p->num = -1;
        p->prox = NULL;
    }
	return q;
}
void EscreverEncadeamento (numero p)
{
	numero q;
    char strings[55][4], cadeia[220] = {'\000'};
    int i = 0, k= 0;
    logic first = True;
	for(q = p->prox; q != NULL; q = q->prox)
    {
        int f = q->num;
        for(int j = 3; j >= 0; j--)
        {
            strings[i][j] = f%10+'0';
            f=f/10;
        }
        i++;
    }
    for(i=i-1; i>=0; i--)
        for(int j = 0; j < 4; j++)
        {
            if(strings[i][j] !='0' && first)
            {
                cadeia[k] = strings[i][j];
                k++;
                first = False;
            }
            else if(!first)
            {
                cadeia[k] = strings[i][j];
                k++;
            }
        }
    if(strlen(cadeia)==0) 
        cadeia[0] = '0';
    else if(cadeia[0] == 47)
    {
        cadeia[0] = '-';
        cadeia[1] = '1';
        cadeia[2] = '\0';
    }
    printf("%s\n", cadeia);
}

numero Soma(numero x, numero y) {
	int carry = 0;
    numero presult, result, q, p;
    presult = (numero) malloc (sizeof(celula));
    result = presult;
    if(x->prox != NULL && y->prox != NULL)
    {
        if(x->prox->num == -1 || y->prox->num == -1)
        {
            presult->prox = (numero) malloc (sizeof(celula));
            presult->prox->num = -1;
            presult->prox->prox = NULL;
            return result;
        }
    }
    for(q = x->prox, p = y->prox; (q != NULL || p != NULL) || (!(q != NULL || p != NULL) && carry != 0); q = (q != NULL) ? q->prox : NULL, p = (p != NULL) ? p->prox : NULL)
    {
        presult->prox = (numero) malloc (sizeof(celula));
        presult = presult->prox;
        if(q != NULL && p != NULL)
            presult->num = p->num+q->num+carry;
        else if(q == NULL && p != NULL)
            presult->num = p->num+carry;
        else if(q != NULL && p == NULL)
            presult->num = q->num+carry;
        else
            presult->num = carry;
        carry = 0;
        if(presult->num >= 10000)
        {
            carry = presult->num/10000;
            presult->num = presult->num % 10000;
        }
        presult->prox = NULL;
    }
    return result;
}

numero AddZeros(numero x, int i)
{
    numero p;
    if(i == 0)
        return x;
    p = x->prox;
    x->prox = (numero) malloc (sizeof(celula));
    x->prox->num = 0;
    x->prox->prox = p;
    return AddZeros(x, i-1);
}

numero Multiplicacao(numero x, numero y)
{
    int carry = 0,i = 0;
    numero q, p, pin, sum;
    sum = (numero) malloc (sizeof(celula));
    if(x->prox != NULL && y->prox != NULL)
    {
        if(x->prox->num == -1 || y->prox->num == -1)
        {
            sum->prox = (numero) malloc (sizeof(celula));
            sum->prox->num = -1;
            sum->prox->prox = NULL;
            return sum;
        }
    }
    sum->prox = NULL;
    for(q = x->prox, pin = y->prox; (q != NULL); q = q->prox, i++)
    {
        numero n, ninicio;
        n = (numero) malloc (sizeof(celula));
        n->prox = NULL;
        ninicio = n;
        carry = 0;
        for(p = pin; (p != NULL) || ((p == NULL) && carry != 0); p = (p != NULL) ? p->prox : NULL)
        {
            n->prox = (numero) malloc (sizeof(celula));
            n = n->prox;
            if(p != NULL)
                n->num = p->num*q->num + carry;
            else
                n->num = carry;
            carry = 0;
            if(n->num >= 10000)
            {
                carry = n->num/10000;
                n->num = n->num % 10000;
            }
            n->prox = NULL;
        }
        ninicio = AddZeros(ninicio, i);
        sum = Soma(sum, ninicio);
    }
    return sum;
}

int main () 
{
       _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE );
   _CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDOUT );
   _CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE );
   _CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDOUT );
   _CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE );
   _CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDOUT );
    numero n1, n2, n3;
    printf("Digite o 1o numero: ");
    n1 = NovoEncadeamento();
    printf("\n\tPrimeiro encadeamento: ");
    EscreverEncadeamento(n1);
    printf("\n");
    printf("Digite o 2o numero: ");
    n2 = NovoEncadeamento();
    printf("\n\tSegundo encadeamento: ");
    EscreverEncadeamento(n2);
    n3 = Soma(n1,n2);
    printf("\n\tSoma dos numeros: ");
    EscreverEncadeamento(n3);
    n3 = Multiplicacao(n1,n2);
    printf("\n\tMultiplicacao dos numeros: ");
    EscreverEncadeamento(n3);

    printf("\n\n");
    //system("pause");
    _CrtDumpMemoryLeaks();
    return 0;
}
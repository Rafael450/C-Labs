#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char cadeia[31];
typedef struct time time;
struct time
{
    cadeia nome;
    int pontos = 0, vitorias = 0, golspro = 0, golscontra = 0, saldogols;
};

typedef struct tabelatimes tabelatimes;
struct tabelatimes
{
    time VetorTimes[30];
    int ntimes;
};

typedef struct resultado resultado;
struct resultado
{
    int local, visitante;
};

tabelatimes TabTimes;
FILE *FileIn, *FileOut;
resultado Jogos[30][30];

void InicializarArquivos(void);
void LerArmazenarTimes(void);
void EscreverTimes(void);
void LerArmazenarJogos(void);
void EscreverJogos(void);
void PreencherTabTimes(void);
void EscreverTabTimes(void);
void OrdenarTabTimes(void);
void EscreverClassificacaoFinal(void);

int main()
{
    InicializarArquivos();
    LerArmazenarTimes();
    EscreverTimes();
    LerArmazenarJogos();
    EscreverJogos();
    PreencherTabTimes();
    EscreverTabTimes();
    OrdenarTabTimes();
    EscreverClassificacaoFinal();
    printf("\n\n");
    system("pause");
    return 0;
}

void InicializarArquivos()
{
    printf("RESULTADOS DE UM CAMPEONATO\n\n");
    printf("Entrada de dados no arquivo Campeonato.dat\n\n");
    printf("Relatorio dos Resultados no arquivo Campeonato\n\n");
    FileIn = fopen("input.txt", "r");
    FileOut = fopen("output.txt", "w");
    fprintf(FileOut, "R E S U L T A D O S   D E   U M   C A M P E O N A T O\n\n");
}

void LerArmazenarTimes()
{
    char lixo;
    fscanf(FileIn, "%d%c", &TabTimes.ntimes, &lixo);
    for (int i = 0; i < TabTimes.ntimes; i++)
    {
        fgets(TabTimes.VetorTimes[i].nome, 25, FileIn);
        TabTimes.VetorTimes[i].nome[strlen(TabTimes.VetorTimes[i].nome) - 1] = '\0';
    }
}

void EscreverTimes()
{
    fprintf(FileOut,"%22s\n", "Times");
    fprintf(FileOut,"----------------------\n");
    for(int i = 0; i < TabTimes.ntimes; i++)
        fprintf(FileOut,"%22s\n",TabTimes.VetorTimes[i].nome);
    fprintf(FileOut,"\n\n");
}

void LerArmazenarJogos()
{
    for(int i = 0; i < TabTimes.ntimes; i++)
        for(int j = 0; j < TabTimes.ntimes; j++)
            if(i != j)
                fscanf(FileIn,"%d%d", &Jogos[i][j].local, &Jogos[i][j].visitante);
    fclose(FileIn);
}

void EscreverJogos()
{
    fprintf(FileOut,"                          ");
    for(int i = 0; i < TabTimes.ntimes; i++)
    {
        for(int k = 0; k < 3; k++)
            fprintf(FileOut,"%c", TabTimes.VetorTimes[i].nome[k]);
        fprintf(FileOut,"     ");
    }
    for(int i = 0; i < TabTimes.ntimes; i++)
    {
        fprintf(FileOut,"\n%22s", TabTimes.VetorTimes[i].nome);
        for(int j = 0; j < TabTimes.ntimes; j++)
        {
            if(i != j)
                fprintf(FileOut,"   %d x %d", Jogos[i][j].local, Jogos[i][j].visitante);
            else
                fprintf(FileOut,"   #####");
        }
    }
}

void PreencherTabTimes()
{
    for(int i = 0; i < TabTimes.ntimes; i++)
    {
       for(int j = 0; j < TabTimes.ntimes; j++)
        {
            if(i != j)
            {
                TabTimes.VetorTimes[i].golspro += Jogos[i][j].local;
                TabTimes.VetorTimes[j].golscontra += Jogos[i][j].local;
                TabTimes.VetorTimes[i].golscontra += Jogos[i][j].visitante;
                TabTimes.VetorTimes[j].golspro += Jogos[i][j].visitante;
                if(Jogos[i][j].local > Jogos[i][j].visitante)
                {
                    TabTimes.VetorTimes[i].vitorias++;
                    TabTimes.VetorTimes[i].pontos += 3;
                }
                else if(Jogos[i][j].local == Jogos[i][j].visitante)
                {
                    TabTimes.VetorTimes[i].pontos++;
                    TabTimes.VetorTimes[j].pontos++;
                }
                else
                {
                    TabTimes.VetorTimes[j].vitorias++;
                    TabTimes.VetorTimes[j].pontos += 3;
                }
            }
        }
        TabTimes.VetorTimes[i].saldogols = TabTimes.VetorTimes[i].golspro - TabTimes.VetorTimes[i].golscontra;
    }
}

void EscreverTabTimes()
{
    fprintf(FileOut, "\n\nTabela de desempenho dos times:\n\n");
    fprintf(FileOut, "%22s | %9s | %9s | %9s | %9s | %9s\n", "Time", "Pontos", "Vitorias", "G Pro", "G Contra", "Saldo G");
    fprintf(FileOut, "----------------------------------------------------------------------------------\n");
    for (int i = 0; i < TabTimes.ntimes; i++)
        fprintf(FileOut, "%22s | %9d | %9d | %9d | %9d | %9d\n", TabTimes.VetorTimes[i].nome, TabTimes.VetorTimes[i].pontos, TabTimes.VetorTimes[i].vitorias, TabTimes.VetorTimes[i].golspro, TabTimes.VetorTimes[i].golscontra, TabTimes.VetorTimes[i].saldogols);
}

void OrdenarTabTimes()
{
    int i;
    time aux;
    for (int trocou = 1, p = TabTimes.ntimes - 2; p >= 0 && trocou == 1; p--) 
		for (trocou = 0, i = 0; i <= p; i++)
        {
			if(TabTimes.VetorTimes[i].pontos > TabTimes.VetorTimes[i+1].pontos) 
            {
				aux = TabTimes.VetorTimes[i]; TabTimes.VetorTimes[i] = TabTimes.VetorTimes[i+1];
				TabTimes.VetorTimes[i+1] = aux; trocou = 1;
			}
            else if(TabTimes.VetorTimes[i].pontos == TabTimes.VetorTimes[i+1].pontos && TabTimes.VetorTimes[i].vitorias > TabTimes.VetorTimes[i+1].vitorias)
            {
                aux = TabTimes.VetorTimes[i]; TabTimes.VetorTimes[i] = TabTimes.VetorTimes[i+1];
				TabTimes.VetorTimes[i+1] = aux; trocou = 1;
            }
            else if(TabTimes.VetorTimes[i].pontos == TabTimes.VetorTimes[i+1].pontos && TabTimes.VetorTimes[i].vitorias == TabTimes.VetorTimes[i+1].vitorias && TabTimes.VetorTimes[i].saldogols > TabTimes.VetorTimes[i+1].saldogols)
            {
                aux = TabTimes.VetorTimes[i]; TabTimes.VetorTimes[i] = TabTimes.VetorTimes[i+1];
				TabTimes.VetorTimes[i+1] = aux; trocou = 1;
            }
            else if(TabTimes.VetorTimes[i].pontos == TabTimes.VetorTimes[i+1].pontos && TabTimes.VetorTimes[i].vitorias == TabTimes.VetorTimes[i+1].vitorias && TabTimes.VetorTimes[i].saldogols == TabTimes.VetorTimes[i+1].saldogols && TabTimes.VetorTimes[i].golspro > TabTimes.VetorTimes[i+1].golspro)
            {
                aux = TabTimes.VetorTimes[i]; TabTimes.VetorTimes[i] = TabTimes.VetorTimes[i+1];
				TabTimes.VetorTimes[i+1] = aux; trocou = 1;
            }
            else if(TabTimes.VetorTimes[i].pontos == TabTimes.VetorTimes[i+1].pontos && TabTimes.VetorTimes[i].vitorias == TabTimes.VetorTimes[i+1].vitorias && TabTimes.VetorTimes[i].saldogols == TabTimes.VetorTimes[i+1].saldogols && TabTimes.VetorTimes[i].golspro == TabTimes.VetorTimes[i+1].golspro && strcmp(TabTimes.VetorTimes[i+1].nome,TabTimes.VetorTimes[i].nome) > 0)
            {
                aux = TabTimes.VetorTimes[i]; TabTimes.VetorTimes[i] = TabTimes.VetorTimes[i+1];
				TabTimes.VetorTimes[i+1] = aux; trocou = 1;
            }
        }
}

void EscreverClassificacaoFinal()
{
    fprintf(FileOut, "\n\nClassificacao final:\n\n");
    fprintf(FileOut, "%24s | %9s | %9s | %9s | %9s\n", "Time", "Pontos", "Vitorias", "Saldo G", "G Pro");
    fprintf(FileOut, "------------------------------------------------------------------------\n");
    for(int i = TabTimes.ntimes-1; i >= 0; i--)
        fprintf(FileOut, "%d)%22s | %9d | %9d | %9d | %9d\n", TabTimes.ntimes-i, TabTimes.VetorTimes[i].nome, TabTimes.VetorTimes[i].pontos, TabTimes.VetorTimes[i].vitorias, TabTimes.VetorTimes[i].saldogols, TabTimes.VetorTimes[i].golspro);
    fclose(FileOut);
}


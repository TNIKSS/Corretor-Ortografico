#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MENOR(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
int DistLev( char *palavra1, char *palavra2);

int main(void)
{
    char dicionario[14][11];//Quantidade e tamanho das palvras
    char letra[64],palavra[64];
    int rank[14];
    int linha=0,coluna=0,pontos=0,n=0,sequencia=0,cont1=0,cont2=0,cont3=0;


    printf("Digite a quantiadade de sequencias:\n");
    scanf("%i",&sequencia);
    printf("\nDigite a palavra a ser compara:\n");
    scanf("%s",&palavra);

    //Leitura do Arquivo de Texto
    FILE *arquivo = fopen("tudo.txt", "r");
    if(arquivo == NULL)
    {
        return 1;
    }

    while(fgets(letra, sizeof(letra), arquivo) != NULL)
    {
        //printf("Arquivo txt: %s", letra);
        pontos=(DistLev(letra,palavra)-1);
        //printf("%d\n",pontos);
        if(pontos==0){
            printf("A palavra digitada esta correta.\n");
            return 1;
        }

        //Armazemanto de Pontos

        rank[n]=pontos;
        n++;


        //Armazenamento de Palavras
        coluna=0;
        do
        {
            dicionario[linha][coluna]=letra[coluna];
            coluna++;
        }
        while(letra[coluna] != '\n');
        dicionario[linha][coluna]='\0';
        linha++;

    }


    //Saida
    printf("\nAbaixo as palavras mais proximas:\n\n");


    while(cont3<sequencia)
    {
        cont2=0;
        while(cont2<14)
        {
            if(rank[cont2]==cont1)
            {

                printf("%s",dicionario[cont2]);
                printf("  a %i passos\n",rank[cont2]);
                cont3++;
            }
            cont2++;
        }
        cont1++;
    }

    //printf("%s",dicionario[2]);
    return 0;
}


int DistLev(char *s1, char *s2)
{
    unsigned int x, y, s1len, s2len;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int matrix[s2len+1][s1len+1];
    matrix[0][0] = 0;
    for (x = 1; x <= s2len; x++)
        matrix[x][0] = matrix[x-1][0] + 1;
    for (y = 1; y <= s1len; y++)
        matrix[0][y] = matrix[0][y-1] + 1;
    for (x = 1; x <= s2len; x++)
        for (y = 1; y <= s1len; y++)
            matrix[x][y] = MENOR(matrix[x-1][y] + 1, matrix[x][y-1] + 1, matrix[x-1][y-1] + (s1[y-1] == s2[x-1] ? 0 : 1));

    return(matrix[s2len][s1len]);
}


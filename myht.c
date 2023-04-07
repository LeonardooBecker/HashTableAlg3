#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define m 11
#define linesize 1024

int main()
{

    tabela_t *T1, *T2;
    int k;
    char *pt;
    char operacao[2];
    char linha[linesize];
    int i;

    T1 = malloc(sizeof(tabela_t) * m);
    T2 = malloc(sizeof(tabela_t) * m);

    for (i = 0; i < m; i++)
    {
        T1[i].excluido = 0;
        T2[i].excluido = 0;
        T1[i].inserido = 0;
        T2[i].inserido = 0;
    }

    while (!(feof(stdin)))
    {
        if ((fgets(linha, linesize, stdin)) && (linha[0] != '\n'))
        {
            pt = strtok(linha, " ");
            //strcpy(operacao,pt);
            strncpy(operacao,pt,2);
            pt = strtok(NULL, " ");
            sscanf(pt, "%d", &k);
            if (!(strcmp(operacao, "i")))
                inclui(k, T1, T2);
            if (!(strcmp(operacao, "r")))
                exclui(k, T1, T2);
        }
    }

    imprime(T1, T2);
    free(T1);
    free(T2);
    return 0;
}

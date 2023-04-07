#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "lib.h"
#define m 11

int h1(int k)
{
    return (k % m);
}

int h2(int k)
{
    return (floor(m * (k * 0.9 - floor(k * 0.9))));
}

void inclui(int k, tabela_t *T1, tabela_t *T2)
{
    int index, ki, kj;
    index = h1(abs(k));
    if (((T1[index].inserido == 1) && (T1[index].chave == k)) || ((T2[h2(abs(k))].inserido == 1) && (T2[h2(abs(k))].chave == k)))
        return;
    if ((T1[index].excluido == 0) && (T1[index].inserido == 1))
    {
        ki = T1[index].chave;
        kj = k;
        T2[h2(ki)].chave = ki;
        T2[h2(ki)].inserido = 1;
        T2[h2(ki)].excluido = 0;
        T1[h1(kj)].chave = kj;
        T1[h1(kj)].excluido = 0;
    }
    else
    {
        T1[index].chave = k;
        T1[index].excluido = 0;
        T1[index].inserido = 1;
    }
}

void exclui(int k, tabela_t *T1, tabela_t *T2)
{
    int index;
    index = h2(abs(k));
    if ((T2[index].excluido == 0) && (T2[index].inserido == 1))
    {
        T2[index].excluido = 1;
        T2[index].inserido = 0;
        return;
    }
    else if ((T1[h1(abs(k))].excluido == 0) && (T1[h1(abs(k))].inserido == 1))
    {
        T1[h1(abs(k))].excluido = 1;
        T1[h1(abs(k))].inserido = 0;
        return;
    }
    else if ((((T2[(h2(abs(k)))].excluido) == 1) && ((T2[(h2(abs(k)))].inserido) == 0)) || ((T1[h1(abs(k))].excluido == 1) && (T1[h1(abs(k))].inserido == 0)))
    {
        return;
    }
    else if (T2[h2(abs(k))].inserido == 0)
    {
        return;
    }
}

void imprime(tabela_t *T1, tabela_t *T2)
{
    int *vetResul;
    int i;
    int qntElementos = 0;
    int j = 0;
    for (i = 0; i < m; i++)
    {
        if (T1[i].inserido == 1)
            qntElementos++;
        if (T2[i].inserido == 1)
            qntElementos++;
    }
    vetResul = malloc(sizeof(int) * qntElementos);

    for (i = 0; i < m; i++)
    {
        if (T1[i].inserido == 1)
        {
            vetResul[j] = T1[i].chave;
            j++;
        }
        if (T2[i].inserido == 1)
        {
            vetResul[j] = T2[i].chave;
            j++;
        }
    }

    quickSort(vetResul, 0, (qntElementos-1));

    i = 0;
    while (i < qntElementos)
    {
        for (j = 0; j < m; j++)
        {
            if ((T1[j].inserido == 1) && ((vetResul[i]) == (T1[j].chave)))
            {
                printf("%d,T1,%d\n", T1[j].chave, j);
                break;
            }
            else if ((T2[j].inserido == 1) && ((vetResul[i]) == (T2[j].chave)))
            {
                printf("%d,T2,%d\n", T2[j].chave, j);
                break;
            }
        }
        i++;
    }
    free(vetResul);
}

void troca(int vet[], int i, int j)
{
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

int particiona(int vet[], int inicio, int fim)
{
    int pivo, pivo_indice, i;
    pivo = vet[fim];
    pivo_indice = inicio;
    for (i = inicio; i < fim; i++)
    {
        if (vet[i] <= pivo)
        {
            troca(vet, i, pivo_indice);
            pivo_indice++;
        }
    }
    troca(vet, pivo_indice, fim);
    return pivo_indice;
}

void quickSort(int vet[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo_indice = particiona(vet, inicio, fim);
        quickSort(vet, inicio, pivo_indice - 1);
        quickSort(vet, pivo_indice + 1, fim);
    }
}

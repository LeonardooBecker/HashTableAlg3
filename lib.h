#ifndef _LIBS_t_H
#define _LIBS_t_H

struct tabela
{
    int chave;
    int excluido;
    int inserido;
};
typedef struct tabela tabela_t;

int h1(int k);

int h2(int k);

void inclui(int k, tabela_t *T1, tabela_t *T2);

void exclui(int k, tabela_t *T1, tabela_t *T2);

void quickSort(int vet[], int inicio, int fim);

void imprime(tabela_t *T1, tabela_t *T2);

#endif

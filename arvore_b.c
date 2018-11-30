#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <limits.h>

#include "arvore_b.h"


No *cria_no(char *chave, Info info) {
    No *novo = (No *) malloc(sizeof(No));
    novo->num_chaves = 1;
    novo->folha = 1;
    novo->pai = NULL;
    novo->chave = (char *) malloc(sizeof(char) * (d * 2));
    novo->chave = chave;
    novo->info = (Info *)malloc(sizeof(Info));
    novo->info = info;
    novo->filho = (No **) malloc(sizeof(No *) * (d * 2) + 1);
    for (int i = 0; i < (d * 2 + 1); i++) {
        novo->filho[i] = NULL;
    }
    return novo;
}

int busca(int cod_cli, char *nome_arquivo_metadados, char *nome_arquivo_dados, int *pont, int *encontrou)
{
	//TODO: Inserir aqui o codigo do algoritmo
	*pont = INT_MAX;
	*encontrou = INT_MAX;
    return INT_MAX;
}

int insere(int cod_cli, char *nome_cli, char *nome_arquivo_metadados, char *nome_arquivo_dados)
{
	//TODO: Inserir aqui o codigo do algoritmo de insercao
    return INT_MAX;
}

int exclui(int cod_cli, char *nome_arquivo_metadados, char *nome_arquivo_dados)
{
	//TODO: Inserir aqui o codigo do algoritmo de remocao
    return INT_MAX;
}

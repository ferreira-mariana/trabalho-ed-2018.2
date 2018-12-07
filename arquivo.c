#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_b.h"

No* leLinhas(No *a, char *arquivo, int ordem){
    FILE *file;
    file = fopen(arquivo, "r");
    No *arv = inicializa();
    arv = a;
    int d = ordem;
    char linha[256];
    char *token;

    while (fgets(linha, sizeof(linha), file)){
        Info *dados = (Info *) malloc(sizeof(Info));
        token = strtok(linha, "/");//titulo
        strcpy(dados->titulo, token);
        token = strtok(NULL, "/");//ano
        char chave[200];
        strcpy(chave, dados->titulo);
        strcat(chave, token);//formou a chave primaria titulo do filme e ano
        dados->ano = atoi(token);
        token = strtok(NULL, "/");
        strcpy(dados->diretor, token);
        token = strtok(NULL, "/");
        strcpy(dados->genero, token);
        token = strtok(NULL, "/");
        dados->minutos = atoi(token);
        printf("--------------------------------------------\n");
        printf("Executando funcao LerArquivo\n");
        printf("%s\n",chave);
        arv = insere(arv, 1, chave, NULL, ordem, dados);
        printf("\nIMPRIMINDO ARVORE\n");
        imprime(arv,0);
    }
    return arv;
  }
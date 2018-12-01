#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_b.h"
/*
No *leLinhas(No *arv, char *nome, int ordem){
    FILE *arq;
    arq = fopen(nome, "r");
    char linha[256], *token;
    while (fgets(linha, sizeof(linha), arq)){
        Info *infos = (Info *) malloc(sizeof(Info));
        if(linha[1]=='\0') break; //string vazia


        token = strtok(linha, "/"); //retorna o que tá escrito na linha até a "/"

        strcpy(infos->titulo, token); //guarda o token no infos->titulo
        char chave[200];
        strcpy(chave, infos->titulo); //guarda infos->titulo na chave
        strcat(chave, token); // chave passa a ser titulo + ano
        infos->ano = atoi(token); //converte de string para inteiros
        token = strtok(NULL, "/"); //quando tiver tempo descobrir direito o que que isso faz
        
        strcpy(infos->diretor, token); //guarda token nos infos->diretor
        token = strtok(NULL, "/");
        strcpy(infos->genero, token); //guarda token nos infos->genero
        token = strtok(NULL, "/");
        infos->minutos = atoi(token);

        arv = insere(arv, 1, chave, NULL, ordem);
        imprime(arv,0);

    }
    return arv;
}
*/
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
        printf("Executando funcao LerArquivo\n");
        printf("%s\n",chave);
        arv = insere(arv, 1, chave, NULL, ordem);
        imprime(arv,0);
    }
    return arv;
  }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_b.h"

TAB* leLinhas(TAB *arv, char *nome){
    FILE *arq;
    arq = fopen(nome, "r");
    int ordem_d = 2; // mínimo de filhos d+1 maximo 2d+1
    char linha[256], *token;
    while (fgets(linha, sizeof(linha), arq)){
        Info *infos = (Info *) malloc(sizeof(Info));
        if(linha[1]=='\0') break; //string vazia


        token = strtok(linha, "/"); //retorna o que tá escrito na linha até a "/"

        strcpy(infos->titulo, token); //guarda o token no infos->titulo
        char chave[200];
        strcpy(chave, infos->titulo); //guarda infos->titulo na chave

        token = strtok(NULL, "/"); //quando tiver tempo descobrir direito o que que isso faz
        infos->ano = atoi(token); //converte de string para inteiros
        token = strtok(NULL, "/");
        strcpy(infos->diretor, token); //guarda token nos infos->diretor
        token = strtok(NULL, "/");
        strcpy(infos->genero, token); //guarda token nos infos->genero
        token = strtok(NULL, "/");
        infos->minutos = atoi(token);


        arv = Insere(arv, chave, infos, ordem_d);

    }
    return arv;
}

#define ARVORE_B_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info{
    char titulo[80];
    int ano;
    char diretor[50];
    char genero[30];
    int minutos;
}Info;

typedef struct No{
    int num_chaves, folha;
    char **chave;
    Info **info;
    struct No **filho, *pai;
}No;

No* leLinhas(No *arv, char *nome, int ordem);

No *inicializa(); //inicializa vazia
No *cria_no(int ordem); //aloca espaço pra um no
No *libera(No *arv, int ordem); //esvazia arvore toda
void imprime(No *arv, int nivel); // imprime arvore por niveis
No *busca_no(No* raiz, char* chave); //busca o no na arvore e se nao acha retorna o no onde a chave deveria estar
No *particiona(No *raiz, No *P, char *chave, No *pt, int ordem); //particiona o no, funcao auxiliar a de inserir
No *insere(No *raiz, int folha, char* chave, No *pt, int ordem); //insere no na arvore


//funcao antiga, nao to usando ainda
No *busca(No *no, char* ch);


//FALTA FAZER:

No* remove_no(No* raiz, char* chave, int ordem); //recebe a chave do no a ser removido e retorna a arvore original sem o no

void busca_infos(No* raiz, char* chave); //recebe uma arvore, usa a busca_no e imprime as infos daquela chave

No* altera_info(char* chave, char info_alterada, char* novo_valor);
    
    //recebe a chave, usa a busca_no
    //info alterada:
    //t = titulos, a = ano, d = diretor, g = genero, m = minutos
    //a pessoa digita a letra correspondente ao que ela quer alterar
    //se a pessoa digitar t por exemplo, altera o titulo para o novo_valor
    //caso o tipo da nova info seja int, converte novo_valor pra int e aí muda
    //retorna o no com as infos alteradas

void busca_filmes(No *raiz, char* diretor); //remove todos filmes de um diretor
    //procura em cada chave da arvore pra ver se aquele filme é desse diretor
    //imprime filme

No *remove_filmes(No *raiz, char* diretor);
    //procura em cada chave da arvore para ver se aquele filme é desse diretor, se sim chama a funcao remove_no
    //remove filme

/* FUNCOES QUE TEM QUE BOTAR NO PROGRAMA:
- Inserção e remoção de nós da árvore B (ou seja, inserção e remoção de filmes);
- Busca das informações subordinadas, dada a chave primária;
- Alteração SOMENTE das informações subordinadas, dada a chave primária;
Busca de todos os filmes de um determinado diretor; e
Remoção de todos os filmes de uma determinada categoria. */

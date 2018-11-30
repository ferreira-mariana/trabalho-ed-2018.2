#ifndef ARVORE_B_H
#define ARVORE_B_H

typedef struct info{
    char titulo[80];
    int ano;
    char diretor[50];
    char genero[30]
    int minutos;

}Info;

typedef struct No{
    int num_chaves, folha;
    char **chave;
    Info **info;
    struct No **filho, *pai;
}No;

//TALVEZ PRECISE ADICIONAR PARAMETROS TIPO ALTURA DA ARVORE (NIVEL) OU ORDEM DA ARVORE


No* cria_no(char* chave, Info info); //primeiro vai ter que criar um no com essas informacoes

No* insere_no(char* chave, Info info); //recebe o no novo e coloca na arvore e retorna a original com o no novo
//chama a cria_no e depois faz a insercao

No* remove_no(char* chave); //recebe a chave do no a ser removido e retorna a arvore original sem o no

No* busca_no(No* raiz, char* chave); //recebe a chave e a raiz e retorna o no que esta procurando
//se nao achar retorna NULL

void busca_infos(No* raiz, char* chave); //recebe uma arvore, usa a busca_no e imprime as infos daquela chave

//fazer insereinfo

No* altera_info(char* chave, char info_alterada, char* novo_valor);
    
    //recebe a chave, usa a busca_no
    //info alterada:
    //t = titulos, a = ano, d = diretor, g = genero, m = minutos
    //a pessoa digita a letra correspondente ao que ela quer alterar
    //se a pessoa digitar t por exemplo, altera o titulo para o novo_valor
    //caso o tipo da nova info seja int, converte novo_valor pra int e aí muda
    //retorna o no com as infos alteradas

void busca_filmes(No *raiz, char* diretor);
    //procura em cada chave da arvore pra ver se aquele filme tem esse diretor
    //imprime filme

No *remove_filmes(No *raiz, char* diretor);
    //procura em cada chave da arvore para ver se aquele filme tem esse diretor
    //remove filme

/* FUNCOES QUE TEM QUE BOTAR NO PROGRAMA:
- Inserção e remoção de nós da árvore B (ou seja, inserção e remoção de filmes);
- Busca das informações subordinadas, dada a chave primária;
- Alteração SOMENTE das informações subordinadas, dada a chave primária;
Busca de todos os filmes de um determinado diretor; e
Remoção de todos os filmes de uma determinada categoria. */

#endif

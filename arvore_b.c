//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "arvore_b.h"


No *cria_no(int ordem) {
    No *novo = (No *) malloc(sizeof(No));
    novo->num_chaves = 0;
    novo->folha = 1;
    novo->pai = NULL;
    novo->chave = (char**) malloc(sizeof(char*) * (ordem * 2));
    for(int i=0;i<(ordem*2);i++) novo->chave[i] = (char *) malloc((100)*sizeof(char));
    novo->info = (Info**)malloc(sizeof(Info*) * (ordem * 2));
    for(int i=0;i<(ordem*2);i++) novo->info[i] = (Info *) malloc((100)*sizeof(Info));
    novo->filho = (No**) malloc(sizeof(No *) * (ordem * 2 + 1));
    for(int i = 0; i < (ordem * 2 + 1); i++) {
        novo->filho[i] = NULL;
    }
    return novo;
}



No *inicializa() {
    return NULL;
}


No *libera(No *arv, int ordem) {
    if (arv != NULL) {
        int i;
        for (i = 0; i <= ordem * 2 + 1; i++) {
            libera(arv->filho[i], ordem);
        }
        free(arv->chave);
        free(arv->filho);
        free(arv);
    }
    return NULL;
}

void imprime(No *arv, int nivel) {
    printf("\nIMPRIMINDO ARVORE:\n");
    if (arv != NULL) {
        int i;
        for (i = 0; i < arv->num_chaves; i++) {
            printf("%s\n", arv->chave[i]); //imprime a chave atual ate chegar no fim do no
        }
        printf("\n");
        if (arv->folha != 1) { //se nao for folha chama a imprime pra cada um dos filhos e aumenta um nivel
            int i;
            for (i = 0; i <= arv->num_chaves; i++) { //nao sei se coloco <= ou so <
                imprime(arv->filho[i], nivel + 1);
            }
        }
    }
}

/* não está sendo utilizada
 *
No *busca_no(No* raiz, char* chave){
	printf("Buscando o no de chave %s\n", chave);

    if(!raiz) return NULL; //nao achou
    else{
        int i = 0;
        while(i < raiz->num_chaves && strcmp(chave, raiz->chave[i]) > 0){ //enquanto ainda tem chave no no e a chave do no atual for diferente
            printf("Chave atual: %s\n", raiz->chave[i]);
            i++;
        }
        if (i < raiz->num_chaves && strcmp(chave, raiz->chave[i]) == 0){ //achou
            printf("\nachei o no\n");
            return raiz;
        }
        else if(raiz->filho[i] != NULL){
            return busca(raiz->filho[i], chave); //faz a mesma busca para o filho onde a chave estaria
        }
        else{
            printf("\nnao achei\n");
            return raiz; //se não acha, retorna o no onde deveria estar a chave
        }
    }
}
*/

No *busca(No *no, char* chave) {
    printf("buscando a chave %s\n", chave);
    if (no != NULL) {
        int i = 0;
        while (i < no->num_chaves && strcmp(chave, no->chave[i])>0) {
            i++;
        }
        if (i < no->num_chaves && strcmp(chave, no->chave[i])==0) {
            return no;
        } else if (no->filho[i] != NULL) {
            return busca(no->filho[i], chave);
        } else return no; //nó era folha -- não existem mais nós a buscar, então retorna o nó onde a chave deveria estar
    } else return NULL; //nó é NULL, não há como buscar
}


//ADAPTAR A PARTICIONA E A INSERE DEPOIS

No *particiona(No *raiz, No *P, char *chave, No *pt, int ordem) {
    No *Q = cria_no(ordem);
    Q->num_chaves = ordem; //número de chaves na nova página Q é d
    Q->pai = P->pai;

    //Verifica a posição onde chave deve ser inserida
    int pos = -1;
    for (int i = 0; i < P->num_chaves; i++) {
        if (strcmp(chave, P->chave[i])>0) {
            pos = i + 1;
        }
    }

    if (pos == -1) {
        //chave a ser inserida é a menor de todas e deve ser inserida na primeira posição
        pos = 0;
    }

    //salva chave da posicao d para subir para o pai (note que d equivale a d+1 já que vetor começa em ZERO
    char *chave_d;
    No *pt_chave_d = Q; //ponteiro que sobre é sempre ponteiro para o novo nó Q
    if (pos != ordem && pos < ordem) {
        //chave vai ser inserida em posição menor que d, então tem que compensar diminuindo 1 no índice
        strcpy(chave_d,P->chave[ordem - 1]);
    } else if (pos != ordem) {
        strcpy(chave_d,P->chave[ordem]);
    } else {
        //chave que vai subir é a própria chave ch, e ela vai apontar para o novo nó Q
        strcpy(chave_d,chave);
    }

    //Ajusta chaves em Q, copiando de P as últimas d chaves
    int i = ordem * 2 - 1;
    int j = ordem - 1;

    while (j >= 0) {
        if (j != pos - ordem - 1) {
            strcpy(Q->chave[j],P->chave[i]);
            Q->filho[j + 1] = P->filho[i + 1];
            i--;
        } else {
            //insere ch em Q na posição correta
            strcpy(Q->chave[j],chave); //EU MUDEI ESSA PARTE TA DIFERENTE DO CODIGO DOS MENINOS NAO SEI SE TA CERTO
            Q->filho[j + 1] = pt;
        }
        j--;
    }

    //Ajusta ponteiro p[0] de Q, que tem que ser o ponteiro d de P
    Q->filho[0] = P->filho[ordem];

    //Ajusta chaves em P fazendo shif se necessário
    j = ordem;
    while (i > pos) {
        strcpy(P->chave[i], P->chave[i - 1]);
        P->filho[i + 1] = P->filho[i];
        i--;
    }

    // Trata caso onde ch tem que ser inserida em P
    if (pos <= ordem) {
        //insere ch em P na posição pos
        strcpy(P->chave[pos],chave);
        P->filho[pos + 1] = pt;
    }

    //Ajusta quantidades de chaves em P
    P->num_chaves = ordem;

    //Insere chave d+1 no pai de P e ponteiro apontando para a nova página Q

    No *pai = insere(P->pai, 0, chave_d, pt_chave_d, ordem);

    //Se P->pai era NULL, significa que árvore tem uma nova raiz, então é preciso ajustar os ponteiros para o pai de P e Q para apontar para esse novo nó
    if (P->pai == NULL) {
        P->pai = pai;
        Q->pai = pai;
        //Arruma ponteiros da nova raiz
        pai->filho[0] = P;
        pai->filho[1] = Q;
    }
    raiz = pai;
    return raiz;
}


No *insere(No *raiz, int folha, char* chave, No *pt, int ordem) {
    printf("executando insere\n");
    No *no;

    if (folha) {
        printf("eh folha\n");
        no = busca(raiz, chave);
        printf("ja buscou\n");
        if (no != NULL) {
            printf("achou na busca\n");
            //chave buscada pode existir dentro do nó retornado
            //verificar se realmente existe
            for (int i = 0; i < no->num_chaves; i++) {
                if (strcmp(chave, no->chave[i])==0) {
                    //chave já existe, portanto não pode ser inserida.
                    //retorna raiz original sem alterar a árvore
                    return raiz;
                }
            }
        }
    }

    else {
        printf("entrou no else\n");
        no = raiz;
    }

    if (raiz == NULL) {
        printf("raiz eh null\n");
        raiz = cria_no(ordem);
        strcpy(raiz->chave[0],chave);
        printf("inseriu chave\n");
        raiz->num_chaves = 1;
        printf("%s\n", raiz->chave[0]);
        return raiz;
    } else {
        printf("raiz nao eh null\n");
        if (no->num_chaves == (2 * ordem)) {
            //Nó está cheio -- é necessário particionar
            //raiz da árvore pode ter mudado, então captura possível nova raiz
            raiz = particiona(raiz, no, chave, pt, ordem);
        } else {
            //encontra posição de inserção
            int i = no->num_chaves;
            while (i > 0 && strcmp(chave , no->chave[i - 1])<0) {
                strcpy(no->chave[i],no->chave[i - 1]);
                no->filho[i + 1] = no->filho[i];
                i--;
            }
            if (i == -1) {
                i = 0;
            }
            strcpy(no->chave[i],chave);
            no->filho[i + 1] = pt;
            no->num_chaves++;
        }
    }
    return raiz;
}


int main(){
    char *arquivo = "arquivotrab.txt";
    No *arvore = inicializa();
    arvore = leLinhas(arvore, arquivo ,2);

    //int ordem = 2;
    //No *arv = inicializa();
    //char nome_arq[128];

    //printf("Por favor, digite o nome do arquivo: \n");
    //scanf("%s", nome_arq);


    //SE A PRIMEIRA PALAVRA FOR "MENOR" OU SEJA VIER ANTES NO ALFABETO RETORNA UM NUMERO NEGATIVO

/*

    arv = insere(arv, 1, "carol", NULL, ordem);

    imprime(arv,0);

    arv = insere(arv, 1, "oi", NULL, ordem);

    imprime(arv,0);

    arv = insere(arv, 1, "dudu", NULL, ordem);

    imprime(arv,0);

    arv = insere(arv, 1, "elisa", NULL, ordem);

    imprime(arv,0);

    arv = insere(arv, 1, "bia", NULL, ordem);

    imprime(arv,0);

*/
    //arv = leLinhas(arv, nome_arq, ordem);


    //imprime(arv, 0);
}

//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "arvore_b.h"

int id_arq = 0;

No *cria_no(int ordem) {
    No *novo = (No *) malloc(sizeof(No));
    novo->num_chaves = 0;
    novo->folha = 1;
    novo->pai = NULL;
    novo->chave = (char**) malloc(sizeof(char*) * (ordem * 2));
    for(int i=0;i<(ordem*2);i++) novo->chave[i] = (char *) malloc((100)*sizeof(char));
    novo->infos = (Info**)malloc(sizeof(Info*) * (ordem * 2));
    for(int i=0;i<(ordem*2);i++) novo->infos[i] = (Info *) malloc((100)*sizeof(Info));
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
/*
void imprime(No *arv, int nivel) {
    if (arv != NULL) {
        int i;
        for (i = 0; i < arv->num_chaves; i++) {
            printf("%s\n", arv->chave[i]); //imprime a chave atual ate chegar no fim do no
        }
        printf("\n");
        if (arv->folha != 1) { //se nao for folha chama a imprime pra cada um dos filhos e aumenta um nivel
    //        printf("NAO E FOLHA\n");
            int i;
            for (i = 0; i <= arv->num_chaves; i++) { //nao sei se coloco <= ou so <
                imprime(arv->filho[i], nivel + 1);
            }
        }
    }
}
*/
void imprime(No *a, int andar){
    if(a){
        int i,j;
        for(i=0; i<=a->num_chaves-1; i++){
            imprime(a->filho[i],andar+1);
            for(j=0; j<=andar; j++) printf("              ");
            printf("%s\n", a->chave[i]);
        }
        imprime(a->filho[i],andar+1);
    }
}


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

 //essa aqui vai poder sair.
No *busca(No *no, char* chave) {
    printf("buscando a chave %s\n", chave);
    if (no != NULL) {
        int i = 0;
        while (i < no->num_chaves && strcmp(chave, no->chave[i])>0) {
            //printf("vai pro lado\n");
            i++;
        }
        if (i < no->num_chaves && strcmp(chave, no->chave[i])==0) {
            printf("achou chave igual\n");
            return no;
        } else if (no->filho[i] != NULL) {
            printf("busca no filho");
            return busca(no->filho[i], chave);
        } else return no; //nó era folha -- não existem mais nós a buscar, então retorna o nó onde a chave deveria estar
    } else return NULL; //nó é NULL, não há como buscar
}


//ADAPTAR A PARTICIONA E A INSERE DEPOIS

No *particiona(No *raiz, No *P, char *chave, No *pt, int ordem, Info* infos) {
    No *Q = cria_no(ordem);
    Q->num_chaves = ordem; //número de chaves na nova página Q é d
    Q->pai = P->pai;
    //Verifica a posição onde chave deve ser inserida
    int pos = -1;


    for (int i = 0; i < P->num_chaves; i++) {
            if (strcmp(chave, P->chave[i]) > 0) {
                pos = i + 1;
            }
    }

    printf("\nPOSICAO: %d\n", pos);

    if (pos == -1) {
        //chave a ser inserida é a menor de todas e deve ser inserida na primeira posição
        pos = 0;
    }

    //salva chave da posicao d para subir para o pai (note que d equivale a d+1 já que vetor começa em ZERO
    char *chave_d = (char*) malloc(sizeof(char)*200);
    Info *infos_d = (Info *) malloc((100)*sizeof(Info));
    No *pt_chave_d = Q; //ponteiro que sobre é sempre ponteiro para o novo nó Q
    if (pos < ordem) {
        //chave vai ser inserida em posição menor que d, então tem que compensar diminuindo 1 no índice
        printf("CHAVE QUE VAI SUBIR: %s", P->chave[ordem-1]);
        strcpy(chave_d,P->chave[ordem - 1]);
        infos_d->ano = P->infos[ordem-1]->ano;
        infos_d->minutos = P->infos[ordem-1]->minutos;
        strcpy(infos_d->diretor, P->infos[ordem-1]->diretor);
        strcpy(infos_d->titulo, P->infos[ordem-1]->titulo);
        strcpy(infos_d->genero, P->infos[ordem-1]->genero);
    } else if (pos > ordem) {
        printf("CHAVE QUE VAI SUBIR: %s", P->chave[ordem]);
        strcpy(chave_d,P->chave[ordem]);
        infos_d->ano = P->infos[ordem]->ano;
        infos_d->minutos = P->infos[ordem]->minutos;
        strcpy(infos_d->diretor, P->infos[ordem]->diretor);
        strcpy(infos_d->titulo, P->infos[ordem]->titulo);
        strcpy(infos_d->genero, P->infos[ordem]->genero);

    } else {
        printf("CHAVE QUE VAI SUBIR: %s", chave);
        //chave que vai subir é a própria chave ch, e ela vai apontar para o novo nó Q
        strcpy(chave_d,chave);
        infos_d->ano = infos->ano;
        infos_d->minutos = infos->minutos;
        strcpy(infos_d->diretor, infos->diretor);
        strcpy(infos_d->titulo, infos->titulo);
        strcpy(infos_d->genero, infos->genero);

    }

    //Ajusta chaves em Q, copiando de P as últimas d chaves
    int i = ordem * 2 - 1;
    int j = ordem - 1;

    while (j >= 0) {
        if (j != pos - ordem - 1) {
            strcpy(Q->chave[j],P->chave[i]);
            Q->infos[j]->ano = P->infos[i]->ano;
            Q->infos[j]->minutos = P->infos[i]->minutos;
            strcpy(Q->infos[j]->diretor, P->infos[i]->diretor);
            strcpy(Q->infos[j]->titulo, P->infos[i]->titulo);
            strcpy(Q->infos[j]->genero, P->infos[i]->genero);
            Q->filho[j + 1] = P->filho[i + 1];
            i--;
        } else {
            //insere ch em Q na posição correta
            strcpy(Q->chave[j], chave); //EU MUDEI ESSA PARTE TA DIFERENTE DO CODIGO DOS MENINOS NAO SEI SE TA CERTO
            Q->infos[j]->ano = infos->ano;
            Q->infos[j]->minutos = infos->minutos;
            strcpy(Q->infos[j]->diretor, infos->diretor);
            strcpy(Q->infos[j]->titulo,infos->titulo);
            strcpy(Q->infos[j]->genero, infos->genero);
            Q->filho[j + 1] = pt;
        }
        j--;
    }

    //Ajusta ponteiro p[0] de Q, que tem que ser o ponteiro d de P
    Q->filho[0] = P->filho[ordem];
   printf("%s", Q->chave[0]);

    //Ajusta chaves em P fazendo shif se necessário
    j = ordem;
    printf("\ni = %d\nj = %d\npos = %d\n", i, j, pos);
    while (i > pos) {
        strcpy(P->chave[i], P->chave[i - 1]);
        P->infos[i]->ano = P->infos[i-1]->ano;
        P->infos[i]->minutos = P->infos[i-1]->minutos;
        strcpy(P->infos[i]->diretor, P->infos[i-1]->diretor);
        strcpy(P->infos[i]->titulo, P->infos[i-1]->titulo);
        strcpy(P->infos[i]->genero, P->infos[i-1]->genero);
        P->filho[i + 1] = P->filho[i];
        i--;
    }


    // Trata caso onde ch tem que ser inserida em P
    if (pos <= ordem) {
        //insere ch em P na posição pos
        strcpy(P->chave[pos],chave);
        P->infos[pos]->ano = infos->ano;
        P->infos[pos]->minutos = infos->minutos;
        strcpy(P->infos[pos]->diretor, infos->diretor);
        strcpy(P->infos[pos]->titulo,infos->titulo);
        strcpy(P->infos[pos]->genero, infos->genero);
        P->filho[pos + 1] = pt;
    }

    //Ajusta quantidades de chaves em P
    P->num_chaves = ordem;

    No *pai;

    if(P->pai != NULL && P->pai->pai != NULL) {
        //Insere chave d+1 no pai de P e ponteiro apontando para a nova página Q
        int contPos = 0;
        int cont = 0;

        for(int j=0; P->chave[j] != NULL; j++) { // = 2

            if (busca_no(P->pai->pai->filho[j], P->chave[0]) == P) {
                contPos = j;
                break;
            }}

        pai = insere(P->pai->pai->filho[contPos], 0, chave_d, pt_chave_d, ordem, infos_d);

    }else {
        pai = insere(P->pai, 0, chave_d, pt_chave_d, ordem, infos_d);
    }
    //Se P->pai era NULL, significa que árvore tem uma nova raiz, então é preciso ajustar os ponteiros para o pai de P e Q para apontar para esse novo nó
    if (P->pai == NULL) {
        P->pai = pai;
        Q->pai = pai;

        //Arruma ponteiros da nova raiz
        pai->filho[0] = P;
        pai->filho[1] = Q;
        pai->folha = 0;
  }

    raiz = pai;
    //imprime(raiz, 0);
    return raiz;
}


No *insere(No *raiz, int folha, char* chave, No *pt, int ordem, Info *infos) {
    printf("executando insere\n");
    No *no;

    if (folha) {
        printf("eh folha\n");
        no = busca(raiz, chave);
        printf("ja buscou\n");
        if (no != NULL) {
            //chave buscada pode existir dentro do nó retornado
            //verificar se realmente existe
            for (int i = 0; i < no->num_chaves; i++) {
                if (strcmp(chave, no->chave[i])==0) {
                    printf("chave ja existe\n");
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
        raiz->infos[0]->ano = infos->ano;
        raiz->infos[0]->minutos = infos->minutos;
        strcpy(raiz->infos[0]->diretor, infos->diretor);
        strcpy(raiz->infos[0]->titulo, infos->titulo);
        strcpy(raiz->infos[0]->genero, infos->genero);

        return raiz;
    } else {
        printf("raiz nao eh null\n");
        if (no->num_chaves == (2 * ordem)) {
            printf("o no ta cheio, tem que particionar\n");

            //Nó está cheio -- é necessário particionar
            //raiz da árvore pode ter mudado, então captura possível nova raiz

            if(no->pai != NULL && no->pai->pai != NULL){
                particiona(raiz, no, chave, pt, ordem, infos);
            }

            else
            {
                raiz = particiona(raiz, no, chave, pt, ordem, infos);
            }
        } else {
            //encontra posição de inserção

            int i = no->num_chaves;
            printf("chave: %s", no->chave[0]);
            while (i > 0 && strcmp(chave , no->chave[i - 1])<0) {
                strcpy(no->chave[i],no->chave[i - 1]);

                no->infos[i]->ano = no->infos[i-1]->ano;
                no->infos[i]->minutos = no->infos[i-1]->minutos;
                strcpy(no->infos[i]->diretor, no->infos[i-1]->diretor);
                strcpy(no->infos[i]->titulo, no->infos[i-1]->titulo);
                strcpy(no->infos[i]->genero, no->infos[i-1]->genero);


                no->filho[i + 1] = no->filho[i];
                i--;
            }
            if (i == -1) {
                i = 0;
            }
            strcpy(no->chave[i],chave);

            no->infos[i]->ano = infos->ano;
            no->infos[i]->minutos = infos->minutos;
            strcpy(no->infos[i]->diretor, infos->diretor);
            strcpy(no->infos[i]->titulo, infos->titulo);
            strcpy(no->infos[i]->genero, infos->genero);


            no->filho[i + 1] = pt;
            no->num_chaves++;
        }
    }
    return raiz;
}

Info *buscaInfo (No *a, char *chaves){
    No *no = inicializa();
    no = busca(a, chaves);
    int i;
    Info *infos;
    for (i=0; i < no->num_chaves; i++){
        if (strcmp(no->chave[i],chaves)==0){
            printf("Filme: %s\n",no->infos[i]->titulo);
            printf("Diretor: %s\n",no->infos[i]->diretor);
            printf("Ano: %d\n",no->infos[i]->ano);
            printf("Duracao: %d\n",no->infos[i]->minutos);
            printf("Genero: %s\n",no->infos[i]->genero);
            return no->infos[i];
        }
        else{
            infos = NULL;
        }
    }
    return infos;

}

No *EditaInfos(No *arv, char *ch){
    No *no = inicializa();
    no = busca(arv, ch);
    int i, pos = -1;
    for (i=0; i < no->num_chaves; i++){
        if (strcmp(no->chave[i],ch)==0) pos = i;
    }
    printf("Infos atuais:\n");
    Info *infos_atuais = buscaInfo(arv, ch);
    printf("\n");
    char diretor[50];
    char genero[30];
    int minutos;
    printf("Digite as novas informações\n");
    printf("Diretor: \n");
    scanf("%s", diretor);
    strcpy(no->infos[pos]->diretor, diretor);
    printf("Genero: \n");
    scanf("%s", genero);
    strcpy(no->infos[pos]->genero, genero);
    printf("Tempo de duracao: \n");
    scanf("%d", &no->infos[pos]->minutos);
    printf("\n");
    Info *change = buscaInfo(arv,ch);
    return arv;
}

void ImprimeInfos(No *arv, int nivel){
    if(arv){
        int i;
        for(i=0; i<=arv->num_chaves-1; i++){
            ImprimeInfos(arv->filho[i],nivel+1);
            printf("Chave: %s\n", arv->chave[i]);
            printf("Titulo do filme: %s\n", arv->infos[i]->titulo);
            printf("Genero: %s\n", arv->infos[i]->genero);
            printf("Diretor: %s\n", arv->infos[i]->diretor);
            printf("Ano: %d\n", arv->infos[i]->ano);
            printf("Tempo de duraçao: %d\n", arv->infos[i]->minutos);
            printf("---------------------------------------\n\n\n");
        }
        ImprimeInfos(arv->filho[i],nivel+1);
    }
}
//terminar aqui de editar e apagar isso

void escreve_arq(No *a) {
    char nome_arq[101];
    sprintf(nome_arq, "arq_%d", id_arq);
    id_arq++;
    FILE *fp = fopen(nome_arq, "wb");
    if(fp == NULL) {
        printf("fp == NULL na função: escreve_no_arquivo\n");
        exit(1);
    }
    int i;

    fwrite(&a->num_chaves, sizeof(int), 1, fp);
    for(i = 0; i < a->num_chaves; i++)
        fwrite(&a->chave[i], sizeof(char)*200, 1, fp);

    if(a->folha != 1) {
        for(i = 0; i < a->num_chaves; i++) {
            fwrite(a->filho[i]->chave[i], sizeof(char)*200, 1, fp);
        }
    }

    fclose(fp);
}

void salvar_arvore(No *no){
    if (no != NULL) {
        escreve_arq(no);
        int i = 0;
        for (i = 0; i < no->num_chaves; i++){
            if(no->filho[i]){
                salvar_arvore(no->filho[i]);
            }
        }
    }
}

void busca_diretor(No *arv, char* diretor, int nivel){
    if(arv){
        int i;
        for(i=0; i<=arv->num_chaves-1; i++){
            busca_diretor(arv->filho[i],diretor, nivel +1);
            if (strcmp(arv->infos[i]->diretor,diretor)==0){
                printf("Chave: %s\n", arv->chave[i]);
                printf("Titulo: %s\n", arv->infos[i]->titulo);
                printf("Genero: %s\n", arv->infos[i]->genero);
                printf("Diretor: %s\n", arv->infos[i]->diretor);
                printf("Ano: %d\n", arv->infos[i]->ano);
                printf("Duracao em minutos: %d\n", arv->infos[i]->minutos);
                printf("\n\n\n");
            }

        }
        busca_diretor(arv->filho[i],diretor, nivel +1);
    }
}




void remove_genero(No* arv, char* genero, int nivel, int ordem){
    if(arv){
        char *gen = genero;
        char *tok  ;
        int i;
        for(i = 0; i<=arv->num_chaves-1;i++){
            remove_genero(arv->filho[i], genero, nivel + 1, ordem);
            if(strcmp(genero, arv->infos[i]->genero)==0){
                remove_no(arv, arv->chave[i], ordem);
            }

        }
        remove_genero(arv->filho[i], genero, nivel + 1, ordem);
    }
}



No* remove_no(No* raiz, char* chave, int ordem){ //recebe a chave do no a ser removido e retorna a arvore original sem o no
    printf("removendo no %s...\n", chave);
    if(raiz == NULL) return NULL;
    int i;
    for (i = 0; i < raiz->num_chaves && strcasecmp(chave, raiz->chave[i]) > 0; i++);//procura a chave dentro daquele nó
    int poschave = i; //posicao da chave em que o for parou
    if(i==raiz->num_chaves) poschave--; //caso seja a ultima
    if (strcasecmp(chave, raiz->chave[poschave]) == 0) { //achou a chave do nó a ser removido
        printf("achou chave %s na pagina\n", chave);
        if(raiz->folha){
            printf("nó %s é folha\n", chave);
            for(int j = poschave; j < raiz->num_chaves-1; j++){
                strcpy(raiz->chave[j], raiz->chave[j+1]); //shift para esquerda das chaves
            }
            raiz->num_chaves--; //decrementa o numero de chaves
            //printf("decrementou o numero de chaves\n");
            return raiz;
        }

    }
    else{
        raiz->filho[i] = remove_no(raiz->filho[i], chave, ordem);
        if(raiz->filho[i]->num_chaves < ordem){
            No *filho_atual = raiz->filho[i]; //onde tinha a chave que foi removida
            No *irmao;
            if(i>0) irmao = raiz->filho[i-1]; //irmao da esquerda
            else irmao = raiz->filho[i+1]; //irmao da direita
            //porque o primeiro nao tem irmao da esquerda
            int j, k;
            if(filho_atual->num_chaves + irmao->num_chaves < 2*ordem){
                //essa parte ta dando erro
                printf("concatenar\n");
                if(i > 0){
                    for(j=0; j < irmao->num_chaves; j++);
                    //percorre o irmao ate a ultima posicao ocupada
                    if(poschave < raiz->num_chaves-1) poschave--;
                    //porque queremos o pai que está entre o filho e o irmao, mas se for o ultimo nao precisa

                    strcpy(irmao->chave[j], raiz->chave[poschave]); //recebe a chave do pai que está entre o filho e o irmao
                    irmao->num_chaves++;
                    j++;//proxima posição livre

                    for(k=0; k<filho_atual->num_chaves; k++){ //traz as chaves do filho para o irmao
                        strcpy(irmao->chave[j], filho_atual->chave[k]);
                        irmao->filho[j] = filho_atual->filho[k]; //passa os filhos tambem
                        irmao->num_chaves++;
                        j++; //vai pra proxima posicao livre
                    }
                }
                else{ //se i = 0, se for o primeiro; caso irmao da direita
                    printf("removendo do primeiro filho...\n");
                    for(j=0; j < filho_atual->num_chaves; j++);
                    //percorre o filho ate a ultima posicao ocupada
                    strcpy(filho_atual->chave[j], raiz->chave[poschave]); //recebe a chave do pai que está entre o filho e o irmao
                    filho_atual->num_chaves++;
                    j++;//proxima posição livre
                    for(k=0; k<irmao->num_chaves; k++){ //traz as chaves do irmao para o filho
                        strcpy(filho_atual->chave[j], irmao->chave[k]);
                        filho_atual->filho[j] = irmao->filho[k]; //passa os filhos tambem
                        filho_atual->num_chaves++;
                        j++; //vai pra proxima posicao livre
                    }

                }

                //printf("ja foi shift dos filhos\n");
                //printf("num chaves: %d\n", raiz->num_chaves);
                //printf("pos chave %d\n", poschave);

                if(poschave < raiz->num_chaves-1){ //só deve fazer o shift se nao for a ultima chave do nó
                    for(k=poschave; k<raiz->num_chaves-1; k++){ //shift nas chaves da raiz
                        strcpy(raiz->chave[k], raiz->chave[k+1]); //chega pra esquerda
                        raiz->filho[k+1] = raiz->filho[k+2]; //chega os filhos tambem
                        //tem que ser k+1 e k+2 porque tem mais filhos que chaves
                    }
                }
                raiz->num_chaves--;

            }
            else{
                printf("precisa fazer redistruibuição:\n");

            }

        }

    }
    return raiz;
}

void selecionar_operacao(No * arvore){
    int selecionando = 1;
    char *arquivo = "arquivotrab.txt";
    int ordem;
    printf("\nDigite a ordem da arvore desejada: ");
    scanf("%d", &ordem);
    printf("\nInserindo filmes do arquivo para a arvore \n");
    arvore = leLinhas(arvore, arquivo, ordem);


    while(selecionando){
        setbuf(stdin, NULL);
        printf("\n1 - Inserir outro filme\n");
        printf("\n2 - Buscar filme\n");
        printf("\n3 - Editar informações do filme\n");
        printf("\n4 - Imprimir todos os filmes\n");

        printf("\n5 - Buscar Filmografia do diretor\n");
        printf("\n6 - Remover filme\n");

        printf("\n7 - Remover filmes da categoria\n");
        printf("\n8 - Salvar arvore\n");


        printf("\nDigite outro numero para interromper a execucao \n\n");
        printf("\nDigite a operacao que deseja realizar\n");
        scanf(" %d", &selecionando);
        printf("\n");

        if(selecionando== 1 ){
            setbuf(stdin, NULL);
            fflush(stdin);
            Info *infos = (Info* )malloc(sizeof(Info));
            char nome[200];
            printf("Digite o nome do filme: ");
            scanf ( "%[^\n]", infos->titulo);
            fflush(stdin);
            strcpy(nome, infos->titulo);

            printf("Digite o ano do filme: ");
            char ano[10];
            scanf("%s", ano);
            fflush(stdin);
            infos->ano = atoi(ano);
            strcat(nome, ano);
            printf("Digite o diretor do filme: ");
            scanf("%s", infos->diretor);
            fflush(stdin);
            printf("Digite o genero do filme: ");
            scanf("%s", infos->genero);

            arvore = insere(arvore, arvore->folha, nome, arvore->pai, 2, infos);


            printf("%s\n", nome);
            printf("\n ARVORE DEPOIS DA INSERÇAO\n");
            imprime(arvore, 0);

        }

        else if(selecionando== 6 ){
            setbuf(stdin, NULL);
            fflush(stdin);
            char chave[200];

            printf("Digite a chave do filme que voce quer remover: ");


            scanf ( "%[^\n]", chave);

            fflush(stdin);


            arvore = remove_no(arvore, chave, ordem);
            imprime(arvore, 0);

        }



         else if(selecionando == 2 ){
            setbuf(stdin, NULL);
            fflush(stdin);
            printf("\nDigite o nome do filme que voce quer buscar:\n\n");
            char chave[200];
            scanf ( "%[^\n]", chave);
            Info *infos = (Info* )malloc(sizeof(Info));

            infos = buscaInfo(arvore, chave);

        }
        else if(selecionando == 3 ){
            setbuf(stdin, NULL);
            fflush(stdin);
            printf("Digite a chave do filme que voce quer editar: \n");
            char chave[200];
            scanf ( "%[^\n]", chave);
            Info *infos = (Info* )malloc(sizeof(Info));

            arvore = EditaInfos(arvore, chave);

        }

        else if(selecionando== 4 ){
            printf("\nImprimindo arvore\n\n");
            ImprimeInfos(arvore, 0);
        }
        else if(selecionando== 5){
            setbuf(stdin, NULL);
            fflush(stdin);
            printf("\nDigite o diretor que voce quer buscar: \n\n");
            char diretor[30];
            scanf ( "%[^\n]", diretor);
            busca_diretor(arvore, diretor, 0);

        }else if(selecionando== 6){
            setbuf(stdin, NULL);
            fflush(stdin);
            printf("\nDigite a chave do filme que voce quer remover: \n\n");
            char filme[200];
            scanf ( "%[^\n]", filme);
            remove_no(arvore, filme, ordem);

        }

        else if(selecionando== 7){
            setbuf(stdin, NULL);
            fflush(stdin);
            printf("\n Digite o genero que voce quer remover: \n\n");
            char genero[50];
            scanf ( "%[^\n]", genero);
            remove_genero(arvore, genero, 0, ordem);
        }
        else if(selecionando== 8){
            salvar_arvore(arvore);
        }

    }
}

int main(){
    No *arvore = inicializa();
    selecionar_operacao(arvore);

}
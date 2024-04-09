#include <stdio.h>
#include "linked.hpp"
#include <string.h>
#include <stdlib.h>





void preencher_lista(L_LIST lista, int * frequencia){
    for(int i = 0; i < 27 ;i++){
        if(frequencia[i] > 0){
            L_NODE novo = cria_node_lista(i + 97, frequencia[i]);
            insere_ordenado(lista,novo);
        }
    }
}

L_NODE monta_arvore(L_LIST lista){
    L_NODE p1,p2, novo;
      
    while(pega_qtd(lista) > 1){
        p1 = remove_lista(lista);
        p2 = remove_lista(lista);
        novo = cria_node_lista('+', pega_frequencia(p1) + pega_frequencia(p2));
        set_arvore(novo,p2,p1);
        insere_ordenado(lista,novo);
    }
    return pega_head(lista);
}

char ** estabelece_representacao(int colunas){
    char ** representacao = (char **) malloc(sizeof(char * ) * 27);

    for(int i = 0; i < 27; i++){
        representacao[i] = (char*)calloc(colunas, sizeof(char));
    }
    return representacao;

}

void gera_representacao(char ** repre, L_NODE raiz, char * rota, int col, char * alfabeto){
    
    int i;
    if(pega_dir(raiz) == NULL && pega_esq(raiz) == NULL){
        for( i = 0; i < 26; i++){
            if(pega_char(raiz) == alfabeto[i]){
                break;
            }
        }
        strcpy(repre[i], rota);
        
    }
    else{
        char esq[30], dir[30];
        strcpy(esq, rota);
        strcpy(dir, rota);
        strcat(esq, "0");
        strcat(esq, "1");
        gera_representacao(repre, pega_esq(raiz), esq, col, alfabeto);
        gera_representacao(repre, pega_dir(raiz), dir, col,alfabeto);
    }
}

void mostra_repre(char ** repre){
    int i;
    for(i = 0; i < 27; i++){
        if(strlen(repre[i]) > 0) printf("%d: %s\n", i, repre[i]);
        
    }
}

int main(){
    char ** repre;
    L_LIST lista = cria_lista();
    L_NODE arvore;
    int colunas;
    int indice;
    char palavra[30];
    int frequencia[26];
    char alfabeto[27];
    for(int j = 0; j < 27 ; j++){
        alfabeto[j] = 97 + j;
    }
    for(int j = 0; j < 26 ; j++){
        frequencia[j] = 0;
    }

    scanf("%s", palavra);
    for(int i = 0; i < strlen(palavra); i++){
        for(indice = 0; indice < 26; indice++){
            if(alfabeto[indice] == palavra[i]){
                break;
            }
        }
        frequencia[indice]++;
    }

    preencher_lista(lista, frequencia);
    arvore = monta_arvore(lista);
    colunas = altura_arvore(arvore) + 1;
    repre = estabelece_representacao(colunas);
    gera_representacao(repre, arvore, "", colunas, alfabeto);

    mostra_repre(repre);

    return 0;
}
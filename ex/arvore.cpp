#include "arvore.hpp"
#include <stdlib.h>
#include <stdio.h>


struct node{
    NODE direita;
    NODE esquerda;
    int dado;
};

struct arvore{
    NODE raiz;
    int qtd;
};

ARVORE cria_arvore(){
    ARVORE tree = NULL;
    tree = (ARVORE) malloc(sizeof(struct arvore));
    tree->raiz = NULL;
    tree->qtd = 0;
    return tree;
}

NODE cria_node(int dado){
    NODE novo = NULL;
    novo = (NODE) malloc(sizeof(struct node));
    novo->direita = NULL;
    novo->esquerda = NULL;
    novo->dado = dado;
    return novo;
}
void insere_node(NODE node, NODE * raiz){
    if(*raiz == NULL){
        *raiz = node;
        return;
    }
    if(node->dado < (*raiz)->dado){
        insere_node(node,&( *raiz)->esquerda);
    }
    else{
        insere_node(node, &(*raiz)->direita);
    }
}

void insere_arvore(int dado, ARVORE tree){
    NODE inserido = cria_node(dado);
    if(tree->raiz == NULL){
        tree->raiz = inserido;
        tree->qtd++;
        return;
    }
    insere_node(inserido, &tree->raiz);
    tree->qtd++;
    
}

void mostra_arvore(NODE raiz){
    
    if(raiz != NULL){
        mostra_arvore(raiz->esquerda);
        mostra_arvore(raiz->direita);
        printf("%d ", raiz->dado);
    }
}

NODE pega_raiz(ARVORE tree){
    return tree->raiz;
}
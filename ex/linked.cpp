#include "linked.hpp"
#include <stdlib.h>
#include <stdio.h>

struct l_node{
    L_NODE next;
    L_NODE direita, esquerda;
    char letra;
    int frequencia;
};

struct l_list{
    L_NODE head;
    int qtd;
};

L_LIST cria_lista(){
    L_LIST lista = NULL;
    lista = (L_LIST) malloc(sizeof(struct l_list));
    lista->head = NULL;
    lista->qtd =0;
    return lista;
};

L_NODE cria_node_lista(char letra, int frequencia){
    L_NODE new_node = NULL;
    new_node = (L_NODE) malloc(sizeof(struct l_node));
    new_node ->next = NULL;
    new_node->direita = NULL;
    new_node->esquerda = NULL;
    new_node->frequencia = frequencia;
    new_node->letra = letra;
    return new_node;
}

void mostra_node(L_NODE node){
    if(node == NULL) return;
    printf("%c ", node->letra);
    mostra_node(node->next);
}

void mostra_lista(L_LIST lista){
    printf("[");
    if(lista->head != NULL) mostra_node(lista->head);
    printf("]\n");
}




void insere_ordenado(L_LIST lista, L_NODE node){
    L_NODE atual = lista->head;
    L_NODE ant = NULL;

    while (atual != NULL && atual->frequencia <= node->frequencia) {
        ant = atual;
        atual = atual->next;
    }

    if (ant == NULL) {
        node->next = lista->head;
        lista->head = node;
    } else {
        ant->next = node;
        node->next = atual;
    }

    lista->qtd++;
}

L_NODE remove_lista(L_LIST lista){
    L_NODE temp = NULL;
    if(lista->head){
        temp = lista->head;
        lista->head = temp->next;
        temp->next = NULL;
        lista->qtd--;
    }
    return temp;
}

int pega_qtd(L_LIST lista){
    return lista->qtd;
}

int pega_frequencia(L_NODE node){
    return node->frequencia;
}

void set_arvore(L_NODE node, L_NODE direita, L_NODE esquerda){
    node->direita = direita;
    node->esquerda = esquerda;
}

L_NODE pega_head(L_LIST lista){
    return lista->head;
}

void mostra_arvore(L_NODE raiz){
    if(raiz->esquerda == NULL && raiz->direita == NULL){
        printf("%c ", raiz->letra);
    }
    else{
        mostra_arvore(raiz->esquerda);
        mostra_arvore(raiz->direita);
    }
}

int altura_arvore(L_NODE raiz){
    int esquerda, direita;
    if(raiz == NULL){
        return -1;
    }
    esquerda = altura_arvore(raiz->esquerda) + 1;
    direita = altura_arvore(raiz->direita) + 1;
    if(direita > esquerda) return direita;
    return esquerda;
}

L_NODE pega_esq(L_NODE raiz){
    return raiz->esquerda;
}
L_NODE pega_dir(L_NODE raiz){
    return raiz->direita;
}
char pega_char(L_NODE node){
    return node->letra;
}

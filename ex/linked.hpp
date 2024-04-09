#ifndef __LINKED_HPP__
#define __LINKED_HPP__

#include <stdio.h>

typedef struct l_node * L_NODE;

typedef struct l_list * L_LIST;

L_LIST cria_lista();
L_NODE cria_node_lista(char letra, int frequencia);
void mostra_node(L_NODE node);
void mostra_lista(L_LIST lista);
void insere_ordenado(L_LIST lista, L_NODE node);
L_NODE remove_lista(L_LIST lista);
int pega_qtd(L_LIST lista);
int pega_frequencia(L_NODE node);
void set_arvore(L_NODE node, L_NODE direita, L_NODE esquerda);
void set_next(L_NODE node, L_NODE next);
L_NODE pega_head(L_LIST lista);
void mostra_arvore(L_NODE raiz);
int altura_arvore(L_NODE raiz);
L_NODE pega_esq(L_NODE raiz);
L_NODE pega_dir(L_NODE raiz);
char pega_char(L_NODE node);

#endif
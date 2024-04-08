#ifndef __LINKED_HPP__
#define __LINKED_HPP__

#include <stdio.h>
#include "arvore.hpp"

typedef struct l_node * L_NODE;

typedef struct l_list * L_LIST;

L_LIST cria_lista();
L_NODE cria_node_lista(NODE raiz, char letra, int frequencia);
void mostra_node(L_NODE node);
void mostra_lista(L_LIST lista);
void insere_ordenado(L_LIST lista, L_NODE node);
L_NODE remove_lista(L_LIST lista);
int pega_qtd(L_LIST lista);
int pega_frequencia(L_NODE node);

#endif
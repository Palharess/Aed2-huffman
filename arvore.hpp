#ifndef __ARVORE_HPP__

typedef struct arvore * ARVORE;
typedef struct node * NODE;

ARVORE cria_arvore();
NODE cria_node(int dado);
void insere_node(NODE node, NODE * raiz);
void insere_arvore(int dado, ARVORE tree);
void mostra_arvore(NODE raiz);
NODE pega_raiz(ARVORE tree);

#define __ARVORE_HPP__


#endif
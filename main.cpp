#include <stdio.h>
#include "arvore.hpp"

int main(){
    ARVORE tree = cria_arvore();
    
    insere_arvore(5, tree);
    insere_arvore(3, tree);
    insere_arvore(8, tree);
    insere_arvore(1, tree);
    insere_arvore(4, tree);
    insere_arvore(6, tree);
    
    insere_arvore(9, tree);
    
    mostra_arvore(pega_raiz(tree));


    return 0;
}
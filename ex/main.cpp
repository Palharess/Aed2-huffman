#include <stdio.h>
#include "arvore.hpp"
#include "linked.hpp"
#include <string.h>
#include <stdlib.h>

typedef struct juntou {
    NODE raiz;
    L_NODE node;
}Juntou;




void preencher_lista(L_LIST lista, int * frequencia){
    for(int i = 0; i < 26 ;i++){
        if(frequencia[i] > 0){
            printf("%d", frequencia[i]);
            NODE node = cria_node(frequencia[i]);
            L_NODE novo = cria_node_lista(node, i + 97, frequencia[i]);
            insere_ordenado(lista,novo);

        }
    }
}

NODE monta_arvore(L_LIST lista){
    L_NODE p1,p2;
    
    
    
    while(pega_qtd(lista) > 1){
        Juntou * j = (Juntou *) malloc(sizeof(Juntou));
        p1 = remove_lista(lista);
        p2 = remove_lista(lista);
        NODE raiz = cria_node();
        L_NODE novo = cria_node_lista(,'+', pega_frequencia(p1) + pega_frequencia(p2));
    }
}


int main(){
    ARVORE tree = cria_arvore();
    L_LIST lista = cria_lista();
    int indice;
    char palavra[30];
    int frequencia[26];
    char alfabeto[27];
    for(int j = 0; j < 26 ; j++){
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
    mostra_lista(lista);
    


    return 0;
}
#include "./arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    FILE* file;
    apointerP root = NULL;
    apointerP* no;
    char list[11][20] = {{"apartamento"}, {"casa"}, {"em"}, {"entrar"}, {"ninguem"},{"porem"}, {"quem"}, {"quer"}, {"sairam"}, {"tambem"}, {"todos"}};
    insertArq(file, "texto.txt", &root, 1);
    insertArq(file, "texto2.txt", &root, 2);

    apointerDoc aux;

    for (int i = 0; i < 11; i++){    
        no = busca(&root, list[i]);
        aux = (*no)->NoI.doc;
        while(aux != NULL){
            if (!strcmp(list[i], (*no)->NoI.key)){
                printf("[%s] no documento %d repetiu %d vezes\n", list[i], aux->idDoc, aux->qtd );
            }
            aux = aux->next;
        }
    }
    
}

//olhar quatidade de vezes doc

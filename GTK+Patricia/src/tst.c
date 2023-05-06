#include "../include/tst.h"
#include <string.h>

void newNo(apointerTst* rootTst, char* palavra, int indice){
    (*rootTst) = (apointerTst) malloc(sizeof(tst));
    (*rootTst)->bit = palavra[indice];
    (*rootTst)->center = NULL;
    (*rootTst)->right = NULL;
    (*rootTst)->left = NULL;
}

void insertTst(apointerTst* rootTst, char palavra[20], int indice){

    if ((*rootTst) == NULL || (*rootTst)->bit == '\0'){
        newNo(rootTst, palavra, indice);
    }

    if ((*rootTst)->bit == palavra[indice]){
        if (indice+1 == strlen(palavra)){
            strcpy((*rootTst)->key, palavra);
            return;
        }
        insertTst(&(*rootTst)->center, palavra, indice+1);
    }

    if ((*rootTst)->bit > palavra[indice]){
        insertTst(&(*rootTst)->left, palavra, indice);
    }

    if ((*rootTst)->bit < palavra[indice]){
        insertTst(&(*rootTst)->right, palavra, indice);
    }

}

void searchPalavra(apointerTst rootTst, char* palavra, int indice){
    if (rootTst == NULL){
        printf("Não encontrado");
        return;
    }

    if (!(strcmp(rootTst->key, palavra))){
        printf("achoiu %s\n", rootTst->key);
        return;
    }

    if (rootTst->bit > palavra[indice]){
        searchPalavra(rootTst->left, palavra, indice);
    }
    if (rootTst->bit < palavra[indice]){
        searchPalavra(rootTst->right, palavra, indice);
    }
    if (rootTst->bit == palavra[indice]){
        searchPalavra(rootTst->center, palavra, indice+1);
    }
}


#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct tst* apointerTst;

typedef struct tst{
    char key[20];
    char bit;
    apointerTst right;
    apointerTst left;
    apointerTst center;
    bool isKey;
}tst;

void insertTst(apointerTst* root, char palavra[20], int indice);

void insere(apointerTst* raiz, char *palavra, int id);

void newNo(apointerTst* root, char* palavra, int indice);

void searchPalavra(apointerTst root, char* palavra, int indice);




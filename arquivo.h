#include <stdio.h>
#include "./Patricia.h"

typedef struct ArquivoTxt* apointerTxt;

typedef struct ArquivoTxt{
    char name[20];
    int len;
    double relevancia;
    int idDoc;
    apointerTxt next;
}ArquivoTxt;

void insertArq(FILE* file, char* arquivo, apointerP* root, int idDoc, apointerTxt* arquivosTxt  );
void printPat(apointerP* root);
void criaArqTxt(apointerTxt* arquivo, char name[20], int idDoc);
void findTxt(apointerTxt* arquivosTxt, apointerTxt* arqTxt, int idDoc);
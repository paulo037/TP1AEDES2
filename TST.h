#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct no{
    char chave;
    unsigned ender: 1;
    struct no *Esquerda;
    struct no *Meio;
    struct no *Direita;

}Node;

void Dicionario(Node **pointer,FILE *fp,char *palavra);
Node *novoNo(char data);
void insere(Node **raiz, char *palavra);
void percorreI(Node *raiz, char *buffer, int profundidade);
void percorre(Node *raiz);
int search(Node *raiz, char *palavra);





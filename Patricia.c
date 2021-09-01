#include "./Patricia.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void insertRoot(apointerP* root, char* string){
    if ((*root) == NULL){
       criaNoExterno(root, string);
    }else{
        apointerP no = NULL;
        if ((*root)->tipo == Externo){
            caseOne(&no, root, string);
        }else{
            int cont = 0;
            int flag = 0;
            iInsert(root, string, &no, &flag, Externo, &cont);
        }
    }
}

void iInsert(apointerP* root, char* string, apointerP* no,int*  flag, dierecao dir, int* cont){
    int fim = (*cont);
    (*cont)++;
    if ((*root)->tipo == Interno){
        int i = (*root)->NoI.index;
        if ((*root)->NoI.bit > string[i]){
            iInsert(&(*root)->NoI.left, string, no, flag, dir, (cont));
            dir = left;
        }else {
            iInsert(&(*root)->NoI.right, string, no, flag, dir, (cont));
            dir = right;
        }
        if ((*no)->NoI.index >= (*root)->NoI.index && !(*flag)){
            insert(no, root, dir);
            (*flag) = 1;
        }
    }else{ 

        int j = 0;
        int index = 0;
        while((*root)->NoI.key[j] == string[j]){
            if((*root)->NoI.key[j] == '\0' || string[j] == '\0')break;
            index++;
            j++;
        }
        createNo(no, string, index);
        return;
    }
    if (!fim && !(*flag)){
        if ((*no)->NoI.index < (*root)->NoI.index)
            insertInicio(no, root, dir);
        else  insert(no, root, dir);
    }
}

void createNo(apointerP* no, char* string, int index){
    apointerP externo = NULL;
    criaNoInterno(no, &index, string);
    criaNoExterno(&externo, string);
    (*no)->NoI.right = externo;
}
void insertInicio(apointerP* no, apointerP* root,dierecao dir){
    if (dir == right){
        (*no)->NoI.left = (*root);
        (*root)= (*no);
    }else{
        (*no)->NoI.left = (*root);
        (*root) = (*no);
    }
}
void insert(apointerP* no, apointerP* root, dierecao dir){
    if (dir == right){
        (*no)->NoI.left = (*root)->NoI.right;
        (*root)->NoI.right = (*no);
    }else{
        (*no)->NoI.left = (*root)->NoI.left;
        (*root)->NoI.left = (*no);
    }
}


void criaNoInterno(apointerP* root, int* index,char* string){
    (*root) = (apointerP) malloc(sizeof(Patricia));
    (*root)->tipo = Interno;
    (*root)->NoI.index = (*index);
    (*root)->NoI.bit = string[(*index)];
    (*root)->NoI.left = NULL;
    (*root)->NoI.right = NULL;
}

void criaNoExterno(apointerP* root,char* string){
    int tam = strlen(string);
    (*root) = (apointerP) malloc(sizeof(Patricia));
    (*root)->NoI.key = malloc(tam * sizeof(char));
    strcpy((*root)->NoI.key, string);
    (*root)->tipo = Externo;
}

void caseOne(apointerP* no, apointerP* root, char* string){
    int j = 0;
    int index = 0;
    while((*root)->NoI.key[j] == string[j]){
        if((*root)->NoI.key[j] == '\0' || string[j] == '\0')break;
        index++;
        j++;
    }
    createNo(no, string, index);
    (*no)->NoI.left = (*root);
    (*root) = (*no);
}

void busca(apointerP* root, char* string){
    if((*root)->tipo == Interno){
        int i = (*root)->NoI.index;
        if ((*root)->NoI.bit > string[i]){
            busca(&(*root)->NoI.left, string);
        }else busca(&(*root)->NoI.right, string);
    }else if (!stricmp((*root)->NoI.key, string)){
        printf("esta na arvore\n");
    }
}
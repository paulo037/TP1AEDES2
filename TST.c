#include "TST.h"


void Dicionario(Node **pointer,FILE *fp,char *palavra){
    int i;
    while(fgets(palavra,30,fp)){
        for(i=0;i<(int)strlen(palavra);i++){
            if(palavra[i]=='\n'){
                palavra[i]='\0';
            }
        }
        insere(pointer,palavra); 
    }
}


Node *novoNo(char data){
    Node *novo=(Node*)malloc(sizeof(Node));
    novo->chave=data;
    novo->ender=0;
    novo->Esquerda=novo->Meio=novo->Direita=NULL;
    return novo;
}

void insere(Node **raiz, char *palavra){
    if((*raiz)==NULL){
        *raiz= novoNo(*palavra);
    }

    if((*palavra)<(*raiz)->chave){
        insere(&((*raiz)->Esquerda),palavra);
    }
    else if((*palavra)>(*raiz)->chave){
        insere(&((*raiz)->Direita),palavra);
    }
    else{
        if(*(palavra+1)){
            insere(&((*raiz)->Meio),palavra+1);
        }
        else{
            (*raiz)->ender=1;
        }
    }
}

void percorreI(Node *raiz, char *buffer, int profundidade){
    if(raiz!=NULL){
        percorreI(raiz->Esquerda, buffer, profundidade);
        buffer[profundidade]=raiz->chave;
        if(raiz->ender==1){
            buffer[profundidade+1]='\0';
            printf("%s\n",buffer);
        }
        percorreI(raiz->Meio, buffer, profundidade+1);
        percorreI(raiz->Direita, buffer, profundidade);
    }
}

void percorre(Node *raiz){
    char buffer[30];
    percorreI(raiz, &buffer[0],0);
}

int search(Node *raiz, char *palavra){
    if(raiz==NULL){
        return 0;
    }

    if(*palavra<raiz->chave){
        return search(raiz->Esquerda, palavra);
    }
    else if(*palavra>raiz->chave){
        return search(raiz->Direita,palavra);
    }
    else{
        if(*(palavra+1)=='\0'){
            return raiz->ender;
        }
        return search(raiz->Meio,palavra+1);
    }
}

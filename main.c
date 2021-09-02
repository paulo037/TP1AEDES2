#include "TST.h"

int main()
{
    FILE *fp;
    Node *raiz=NULL;
    char palavra[30];
    int i;
    fp=fopen("Dicionario//Dictionary.txt","r");
    while(fgets(palavra,30,fp)){
        for(i=0;i<(int)strlen(palavra);i++){
            if(palavra[i]=='\n'){
                palavra[i]='\0';
            }
        }
        insere(&raiz,&palavra[0]); 
    }
    printf("TRAVERSAL:\n");
    percorre(raiz);
    printf("\n\nPESQUISA:");
    search(raiz,"luffy")? printf("ENCONTROU\n"):printf("NAO ENCONTROU\n");
    return 0;
}

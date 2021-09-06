#include "TST.h"

int main()
{
    FILE *fp;
    Node *raiz=NULL;
    char palavra[30];
    fp=fopen("Dicionario//Dictionary.txt","r");
    Dicionario(&raiz,fp,&palavra[0]);
    /*printf("TRAVERSAL:\n");
    percorre(raiz);
    printf("\n\nPESQUISA:");
    search(raiz,"a")? printf("ENCONTROU\n"):printf("NAO ENCONTROU\n");  -> Apenas para testar a TST*/
    return 0;
}

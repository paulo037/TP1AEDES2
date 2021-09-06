#include "./arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    FILE* file;
    apointerP root = NULL;
    apointerP* no;
    
     int opc, idatual = 1;
    char arquivo[20];

    do{ 
        printf("(1) Inserir Arquivo\n(2) printar Patricia\n(3) Busca\n ->");
        scanf("%d", &opc);
        switch (opc){
        case 1:
            scanf("%s", arquivo);
            file = fopen(arquivo, "r");
             if (file == NULL){
                printf("arquivo não encontrado");
                break;
             }
            // criaArq(file, , idatual, "texto");
            insertArq(file, arquivo, &root, idatual);
            idatual++;
            break;
        
        case 2:
            printPat(&root);
            break;
        default:
            break;
        }
    }while(opc != 0);
    
}

//olhar quatidade de vezes doc

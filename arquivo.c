#include "./arquivo.h"

void insertArq(FILE* file, char* arquivo, apointerP* root){
    char c;
    char palavra[30];
    int cont = 0, flag = 0;

    file = fopen(arquivo, "r");
    
    if (file == NULL){
        printf("arquivo não encontrado");
        return;
    }

    do{
        c = fgetc(file);
        if (c == ' ' || c == '.' || c == ','){
            if (flag == 0){
                palavra[cont] = '\0';
                insertRoot(root, palavra);

                flag = 1;
                cont = 0;
            }else cont++;
        } 
        else{
            palavra[cont] = c;
            cont++;
            flag = 0;
        }

    }while(c != EOF);
}
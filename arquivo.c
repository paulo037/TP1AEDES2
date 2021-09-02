#include "./arquivo.h"
#include <string.h>

void insertArq(FILE* file, char* arquivo, apointerP* root){
    char c;
    char palavra[30];
    int cont = 0, flag = 0;
    apointerP* no;
    apointerDoc* aux; 
    no = NULL;
    int idDoc = 1;

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
                if ((*root) != NULL){
                    no = busca(root, palavra);
                    if (!strcmp(palavra, (*no)->NoI.key)){
                       aux = &(*no)->NoI.doc;

                        while(idDoc != (*aux)->idDoc){
                            aux = &(*aux)->next;
                            if ((*aux) == NULL){
                                criaDoc(aux, idDoc);
                                break;
                            } 
                        }
                        if (idDoc == (*aux)->idDoc) (*aux)->qtd ++;
                    }else{
                        insertRoot(root, palavra, idDoc);   
                    }
                }else{
                    insertRoot(root, palavra, idDoc);   
                }

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
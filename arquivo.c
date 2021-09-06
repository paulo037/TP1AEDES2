#include "./arquivo.h"
#include <string.h>
#include <ctype.h>

void insertArq(FILE* file, char* arquivo, apointerP* root, int idDoc){
    char c;
    char palavra[30];
    int cont = 0, flag = 0;
    apointerP* no;
    apointerDoc* aux; 
    no = NULL;

    do{
        c = fgetc(file);
        if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '?'){
            if (flag == 0){
                palavra[cont] = '\0';
                if ((*root) != NULL){
                    no = busca(root, palavra);
                    if (!strcmp(palavra, (*no)->NoI.key)){
                       aux = &(*no)->NoI.doc;

                        do{

                            if ((*aux) == NULL){
                                criaDoc(aux, idDoc);
                                cont = 0;
                                flag = 1;
                                break;
                            }

                            if (idDoc == (*aux)->idDoc) {
                                (*aux)->qtd ++;
                                cont = 0;
                                flag = 1;
                                break;
                            }                          

                            aux = &(*aux)->next;

                        }while(1);
                        
                    }else{
                        insertRoot(root, palavra, idDoc);
                        cont = 0;
                        flag = 1;   
                    }
                }else{
                    insertRoot(root, palavra, idDoc); 
                    cont = 0;
                    flag = 1;  
                }
            }
        } 
        else{
            palavra[cont] = tolower(c);
            cont++;
            flag = 0;
        }

    }while(c != EOF);
    fclose(file);
}
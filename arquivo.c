#include "./arquivo.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void insertArq(FILE* file, char* arquivo, apointerP* root, int idDoc, apointerTxt* arquivosTxt){
    char c;
    char palavra[30];
    int cont = 0, flag = 0;
    apointerP* no;
    apointerDoc* aux; 
    apointerTxt arqTxt;
    findTxt(arquivosTxt, &arqTxt, idDoc);    
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
                        arqTxt->len++;   
                    }
                }else{
                    insertRoot(root, palavra, idDoc); 
                    cont = 0;
                    flag = 1;
                    arqTxt->len++;  
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

void criaArqTxt(apointerTxt* arquivo, char name[20], int idDoc){
    if ((*arquivo) == NULL){
        (*arquivo) = (apointerTxt) malloc(sizeof(ArquivoTxt));
        (*arquivo)->len = 0;
        strcpy( (*arquivo)->name, name);
        (*arquivo)->relevancia = 0;
        (*arquivo)->idDoc = idDoc;
        (*arquivo)->next = NULL;
    }else{
        criaArqTxt(&(*arquivo)->next, name, idDoc);
    }
}
   

void findTxt(apointerTxt* arquivosTxt, apointerTxt* arqTxt, int idDoc){
    if((*arquivosTxt) == NULL)return;
    if ((*arquivosTxt)->idDoc == idDoc){
        (*arqTxt) = (*arquivosTxt);
    }else{
        findTxt(&(*arquivosTxt)->next, arqTxt,idDoc);
    }
}
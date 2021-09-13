#include "../include/arquivo.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <gtk/gtk.h>




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
                                arqTxt->len++;
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

void search(apointerTxt* arquivosTxt, apointerP root, char termos[]){
    char termoDeBusca[20];
    char* termo;
    apointerP no;
    apointerTxt  arqAtual;

    if (root == NULL || (*arquivosTxt) == NULL)return;

    termo = strtok(termos, ", \n\0");

    zeraRelevancia(arquivosTxt);
    while(termo != NULL){
        arqAtual = (*arquivosTxt);
        strcpy(termoDeBusca, termo);
        no =  *(busca(&root, termoDeBusca));

        if(!strcmp(termoDeBusca, no->NoI.key)){
            while(arqAtual != NULL){
                calcRelevancia(&arqAtual, no, arquivosTxt);
                arqAtual = arqAtual->next;
            }
        }

        termo = strtok(NULL, ", \n\0");
    }
}

int dj(apointerP root){
    apointerDoc documento = root->NoI.doc;
    int dj = 0;
    while(documento != NULL){
        dj++;
        documento = documento->next;
    }
    return dj;
}

int N(apointerTxt* arquivoTxt){
    apointerTxt  aux = (*arquivoTxt);
    int N = 0;
    while(aux != NULL){
        N++;
        aux = aux->next;
    }
    return N;
}

void calcRelevancia(apointerTxt* arqAtual, apointerP root, apointerTxt* arquivosTxt){
    int q, Dj, fji, ni;
    double n, w = 0, x;
    apointerDoc doc;
    doc = root->NoI.doc;

    while(doc->idDoc != (*arqAtual)->idDoc){
        doc = doc->next;
        if (doc == NULL)return;
    }
    Dj = dj(root);
    fji = doc->qtd;
    n = N(arquivosTxt);
    x = log2(n);
    ni = (*arqAtual)->len;
    w = fji * x / Dj/ni;
    (*arqAtual)->relevancia += w;
}

void zeraRelevancia(apointerTxt* arquivosTxt){
    apointerTxt aux = (*arquivosTxt);

    while(aux->next != NULL){
        aux->relevancia = 0;
        aux = aux->next;
    }
}

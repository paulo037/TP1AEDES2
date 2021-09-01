#include "./arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    FILE* file;
    apointerP root = NULL;

    insertArq(file, "texto.txt", &root);

    busca(&root, "available");
    
}

#include "./include/tst.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    apointerTst root;
    FILE* file;
    root = NULL;
    insertDic(file, &root);
    searchPalavra(root, "word", 0);
    printTstOrd(root);
}
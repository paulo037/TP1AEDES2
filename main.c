#include "./Patricia.h"
#include <stdio.h>

int main(){
    apointerP root = NULL;
    insertRoot(&root, "010010");
    insertRoot(&root, "010011");
    insertRoot(&root, "011000");
    insertRoot(&root, "100001");
    insertRoot(&root, "101000");
    insertRoot(&root, "101111");
    busca(&root, "1011");
}

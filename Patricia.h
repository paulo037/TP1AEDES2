typedef enum{
    Interno, Externo
}tipoNo;

typedef enum{
    left, right
}dierecao;

typedef struct Patricia* apointerP;

typedef struct Patricia {

    tipoNo tipo;
    union {
        struct{
          int index;
          char bit;
          apointerP left, right;
        };
        char* key;
    }NoI;
  
}Patricia;



void criaNoInterno(apointerP* root, int* index,char* string);
void criaNoExterno(apointerP* root,char* string);
void insertRoot(apointerP* root, char* string);
void iInsert(apointerP* root, char* string, apointerP* no,int*  flag, dierecao dir, int* end);
void createNo(apointerP* no, char* string, int index);
void insert(apointerP* no, apointerP* root, dierecao dir);
void caseOne(apointerP* no, apointerP* root, char* string);
void insertInicio(apointerP* no, apointerP* root,dierecao dir);
void busca(apointerP* root, char* string);
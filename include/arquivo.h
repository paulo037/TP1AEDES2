#include <stdio.h>
#include "./Patricia.h"
#include <gtk/gtk.h>



typedef GtkListBoxForeachFunc (*ptr)(GtkWidget *row, GtkListBox* list_view, gpointer* data);

typedef struct ArquivoTxt* apointerTxt;

typedef struct iters{
  GtkTreeIter *iter;
  int pos;
  int len;
  struct iters *next;
}GtkIters;

typedef struct ArquivoTxt{
    char name[20];
    int len;
    double relevancia;
    int idDoc;
    apointerTxt next;
}ArquivoTxt;

void insertArq(FILE* file, char* arquivo, apointerP* root, int idDoc, apointerTxt* arquivosTxt  );
void printPat(apointerP* root);
void criaArqTxt(apointerTxt* arquivo, char name[20], int idDoc);
void findTxt(apointerTxt* arquivosTxt, apointerTxt* arqTxt, int idDoc);
void search(apointerTxt* ArquivosTxt, apointerP root, char termos[]);
int dj(apointerP root);
int N(apointerTxt* arquivoTxt);
void calcRelevancia(apointerTxt* arqAtual, apointerP root, apointerTxt* arquivosTxt);
void zeraRelevancia(apointerTxt* arquivosTxt);



#include "../include/interface.h"

FILE* file;
apointerP root = NULL;
apointerTxt arquivosTxt = NULL;
int idatual = 1;
char arquivo[20];

int PAT_COLUMNS = 2, LIST_COLUMNS = 1;


//fechar a guia
void on_window_destroy( GtkWidget *widget, gpointer   data ){
   gtk_main_quit ();
 }

void on_button_inserir_clicked (GtkWidget * widget, gpointer data){
   gtk_stack_set_visible_child_name(stack, "view_insercao");
}

void on_button_pesquisar_clicked (GtkWidget * widget, gpointer data){
   gtk_stack_set_visible_child_name(stack, "view_pesquisa");
}

void on_button_mostrar_clicked (GtkWidget * widget, gpointer data){
   
   gtk_stack_set_visible_child_name(stack, "view_mostrar");
}


 void on_button_voltar_clicked (GtkWidget * widget, gpointer data){
   gtk_stack_set_visible_child_name(stack, "view_menu");
}

void on_button_inserir_entry_clicked (GtkWidget * widget, gpointer data){
    const gchar *arq;
    char arquivo[50];
    GtkWidget *dialog;
    GtkStack *stackDialog;
    entry = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_entry_txt"));


    arq = gtk_entry_get_text(GTK_ENTRY(entry));
    strcpy(arquivo, arq);
    file = fopen(arquivo, "r");
    if (file == NULL){
        dialog = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_msg_erro"));
        gtk_widget_show_all(dialog);
      
    }else{
        criaArqTxt(&arquivosTxt, arquivo, idatual);
        insertArq(file, arquivo, &root, idatual, &arquivosTxt);
        idatual++;
        init_list(patricia_view, " <qtde, idDoc>", &PAT_COLUMNS);
        viewPat(&root, patricia_view, N(&arquivosTxt));
        gtk_entry_set_text(GTK_ENTRY(entry), "");
        dialog = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_msg_inserido"));
        gtk_widget_show_all(dialog);
    }

    
}

void printOrdenado(apointerTxt* arquivosTxt, GtkWidget* list_view ){
    apointerTxt maior, aux, no, pai;
    apointerTxt* atual;
    GtkWidget *vbox, *label;
    int position = 0;


    if ((*arquivosTxt) == NULL)return;

    atual = arquivosTxt;
    maior = (*arquivosTxt);
    no = (*arquivosTxt);

    while((*atual)->next != NULL){
        while(no->next != NULL){
            if(no->next->relevancia > maior->relevancia){
                pai = no;
                maior = no->next;
            }
            no = no->next;
        }
        if (maior->relevancia > (*atual)->relevancia){
            aux = maior->next;
            pai->next = aux;
            maior->next = (*atual);
            (*atual) = maior;
        }
        atual = &(*atual)->next;
        maior = (*atual);
        no = (*atual);
    }
    
    aux  = (*arquivosTxt);
    list_remove_all(list_view );

    while(aux != NULL){
        add_to_list(list_view, strtok(aux->name, "."), 0);
        aux = aux->next;
    }
 

}

void add_to_list(GtkWidget *list_view, const gchar *str, int pos) {
    
    GtkListStore *store;
    GtkTreeIter iter;
    store = GTK_LIST_STORE(gtk_tree_view_get_model
        (GTK_TREE_VIEW(list_view)));
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, pos, str,-1);
}

void list_remove_all(GtkWidget *list_view ){
    
    GtkListStore *store;

    store = GTK_LIST_STORE(gtk_tree_view_get_model
        (GTK_TREE_VIEW(list_view)));
        
    gtk_list_store_clear(store);
}

void init_list(GtkWidget *list, char* title, int* N_COLUMNS) {

    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkListStore *store, aux;
    GType types[(*N_COLUMNS)];

    for(int c = 0; c < (*N_COLUMNS); c++){
        types[c] = G_TYPE_STRING;
    }
    column = gtk_tree_view_column_new();
    renderer = gtk_cell_renderer_text_new();

    column = gtk_tree_view_column_new_with_attributes(title, renderer, "text", (*N_COLUMNS)-1, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

    store = gtk_list_store_newv((*N_COLUMNS), types);

    gtk_tree_view_set_model(GTK_TREE_VIEW(list), 
        GTK_TREE_MODEL(store));

    g_object_unref(store);
    (*N_COLUMNS)++;
}




void viewPat(apointerP* root, GtkWidget *pat_view, int n){
    int len, j;
    char string[20];
    GtkListStore *store;
    GtkTreeIter iter;
    
    if ((*root)== NULL) return;

    if ((*root)->tipo == Interno){
        viewPat(&(*root)->NoI.left, pat_view, 0);
        viewPat(&(*root)->NoI.right, pat_view, 0);
    }else if ((*root)->tipo == Externo){
        store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(pat_view)));
        apointerDoc aux = (*root)->NoI.doc;
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, 0, (*root)->NoI.key,-1);
        j = 1;
        while(aux != NULL){
            convert(aux->idDoc, aux->qtd, string);
            gtk_list_store_set(store, &iter, j, string,-1);
            aux = aux->next;
            j++;
        }
    }


}

void on_view_gtk_list_result(const gchar *string){
   char st[50];
   strcpy(st, string);
   search(&arquivosTxt, root, st);
   printOrdenado(&arquivosTxt, list_view);
   gtk_stack_set_visible_child_name(stack, "view_resultado_pesquisa");
}

void on_button_pesquisar_entry_clicked (GtkWidget * widget, gpointer data){
   const gchar *string;
   entry = GTK_WIDGET(gtk_builder_get_object(builder, "pesquisa_entry"));
   string = gtk_entry_get_text(GTK_ENTRY(entry));
   on_view_gtk_list_result(string);
   gtk_entry_set_text(GTK_ENTRY(entry), "");
   
}

void convert(int id, int qtde, char string[]){
    char sid[6], sqtde[6];
    snprintf(sid, 6, "%d", id);
    snprintf(sqtde, 6, "%d", qtde);
    strcpy(string, "<");
    strcat(string, sqtde);
    strcat(string, ">, <");
    strcat(string, sid);
    strcat(string, ">\0");
}

void on_gtk_dialog_erro_close(){
    GtkWidget *dialog;
  
    dialog = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_msg_erro"));
    gtk_widget_hide(dialog);
}

void on_gtk_dialog_inserido_close(){
    GtkWidget *dialog;
  
    dialog = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_msg_inserido"));
    gtk_widget_hide(dialog);
}
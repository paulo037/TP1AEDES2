#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <math.h>
#include <ctype.h>

GtkWidget *window;
GtkWidget *container;
GtkWidget *entry;
GtkWidget *botao;
GtkBuilder *builder;


GtkListStore *store;
GtkTreeIter iter;
GtkEntryCompletion *completion;
GtkTreeModel *completion_model;


typedef struct{
    FILE *fp;
}data;

data Data;

GtkTreeModel *create_completion_model (void){ //Cria a Tree
    char aux[30];
    store = gtk_list_store_new (1, G_TYPE_STRING);
    /* Append one word */
    while(fgets(aux,30,Data.fp)){ //Mesmo esquema da TST mas pegando do arquivo
        gtk_list_store_append (store, &iter);
        gtk_list_store_set (store, &iter, 0, aux, -1);
    }
    return GTK_TREE_MODEL (store); //Retorna o ponteiro pro main
}

void clear_code(GtkButton *b){
    gtk_editable_delete_text (GTK_EDITABLE(entry), 0, -1);
}

void changed(GtkEntry *e){
    char tmp[128];
	sprintf(tmp, "entry=%s", gtk_entry_get_text(e));
}

int main(int argc, char *argv[]){
    Data.fp=fopen("Dictionary.txt","r");
    gtk_init(&argc,&argv);

    builder=gtk_builder_new_from_file("gtktest.glade");
    window=GTK_WIDGET(gtk_builder_get_object(builder,"window"));

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit),NULL);
    gtk_builder_connect_signals(builder, NULL);

    container=GTK_WIDGET(gtk_builder_get_object(builder,"container"));
    botao=GTK_WIDGET(gtk_builder_get_object(builder,"botao"));
    entry=GTK_WIDGET(gtk_builder_get_object(builder,"entry"));

    
    completion = gtk_entry_completion_new (); //Cria estrutura que vai completar
    gtk_entry_set_completion (GTK_ENTRY (entry), completion); //Seta pra entry o completion
    g_object_unref (completion);
    completion_model = create_completion_model (); //Aqui vai criar a Tree que vai ser onde ficam as palavras
    gtk_entry_completion_set_model (completion, completion_model); //Vai setar o completion com a lista criada
    g_object_unref (completion_model);
    gtk_entry_completion_set_text_column (completion, 0); //Vai indicar a coluna das palavras, EU ACHO

    g_signal_connect(G_OBJECT(botao),"clicked",G_CALLBACK(clear_code),NULL);
    g_signal_connect(G_OBJECT(entry),"changed",G_CALLBACK(changed),NULL);
    
    
    gtk_widget_show_all(window);
    gtk_main();

    if(Data.fp!=NULL){
        fclose(Data.fp);
    }

    return EXIT_SUCCESS;

}



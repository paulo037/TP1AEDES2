#include "../include/interface.h"
//#include "../include/tst.h"

GtkListStore *store;
GtkTreeIter iter;
GtkEntryCompletion *completion;
GtkTreeModel *completion_model;
GtkEntry* entryserch;

typedef struct{
    FILE *fp;
}data;

data Data;

GtkTreeModel *create_completion_model (void){ //Cria a Tree
    int i;
    char aux[30];
    store = gtk_list_store_new (1, G_TYPE_STRING);
    
    while(fgets(aux,30,Data.fp)){ //Mesmo esquema da TST mas pegando do arquivo
        for(i=0;i<strlen(aux);i++){
            if(aux[i]=='\n'){
                aux[i]=0;
            }
         }
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

int main( int   argc, char *argv[] ){

   gtk_init (&argc, &argv);

   Data.fp= fopen("./dicionario.txt", "r");
   builder = gtk_builder_new_from_file("ui.glade");

   gtk_builder_add_callback_symbols(builder,
      "on_window_destroy", G_CALLBACK(on_window_destroy),//fecha guia

      "on_button_inserir_clicked", G_CALLBACK(on_button_inserir_clicked),//butao inseir menu
      "on_button_mostrar_clicked", G_CALLBACK(on_button_mostrar_clicked),//butao mostrar menu
      "on_button_pesquisar_clicked", G_CALLBACK(on_button_pesquisar_clicked),//butao pesquisar menu

      "on_pesquisa_entry_activate", G_CALLBACK(on_button_pesquisar_entry_clicked),
      "on_button_pesquisar_entry_clicked", G_CALLBACK(on_button_pesquisar_entry_clicked),

      "on_button_inserir_entry_clicked", G_CALLBACK(on_button_inserir_entry_clicked),
      "on_gtk_entry_txt_activate", G_CALLBACK(on_button_inserir_entry_clicked),

      "on_button_voltar_pesquisa_clicked", G_CALLBACK(on_button_voltar_clicked),
      "on_button_voltar_insercao_clicked", G_CALLBACK(on_button_voltar_clicked),
      "on_button_voltar_patricia_clicked", G_CALLBACK(on_button_voltar_clicked),

      "on_button_voltar_insercao_dic_clicked", G_CALLBACK(on_button_voltar_clicked),
      "on_button_voltar_imprim_tst_clicked", G_CALLBACK(on_button_voltar_clicked),
      "on_button_voltar_pesquisa_pat_clicked", G_CALLBACK(on_button_voltar_clicked),
      "on_button_voltar_resultado_busca_clicked", G_CALLBACK(on_button_pesquisar_clicked),
      "on_gtk_button_ok_erro_clicked",G_CALLBACK(on_gtk_dialog_erro_close),
      "on_gtk_button_ok_inserido_clicked",G_CALLBACK(on_gtk_dialog_inserido_close),

      "on_button_busca_pat_clicked", G_CALLBACK(on_button_busca_pat_clicked),

      "on_button_imprimir_TST_clicked", G_CALLBACK(on_button_imprimir_TST_clicked),

      "on_button_imprimir_dic_clicked", G_CALLBACK(on_button_imprimir_dic_clicked),   

      "on_button_inserir_dic_entry_clicked", G_CALLBACK(on_button_inserir_dic_entry_clicked),

   NULL);

      gtk_builder_connect_signals(builder, NULL);

      window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
      
      stack = GTK_STACK(gtk_builder_get_object(builder, "stack"));

      entryserch = GTK_ENTRY(gtk_builder_get_object(builder, ""));

      list_view = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_tree_view"));
      int one = 1;
      init_list(list_view, "Resultado da busca", &one);

      one =1;
      patricia_view = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_tree_patrcia"));
      init_list(patricia_view, "Palavra", &one);

      one = 1;
      tst_view = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_tree_TST"));
      init_list(tst_view, "Palavra", &one);

      completion = GTK_ENTRY_COMPLETION(gtk_builder_get_object(builder, "entry_comp"));

      completion_model = create_completion_model (); //Aqui vai criar a Tree que vai ser onde ficam as palavras
      gtk_entry_completion_set_model (completion, completion_model); //Vai setar o completion com a lista criada
      g_object_unref (completion_model);
      gtk_entry_completion_set_text_column (completion, 0); //Vai indicar a coluna das palavras, EU ACHO

      g_signal_connect(G_OBJECT(entryserch),"changed",G_CALLBACK(changed),NULL);

      gtk_widget_show_all(window);
      gtk_main ();
     
   return 0;
 }
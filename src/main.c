#include "../include/interface.h"

int main( int   argc, char *argv[] ){

   gtk_init (&argc, &argv);

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
      "on_button_voltar_resultado_busca_clicked", G_CALLBACK(on_button_pesquisar_clicked),
      "on_gtk_button_ok_erro_clicked",G_CALLBACK(on_gtk_dialog_erro_close),
      "on_gtk_button_ok_inserido_clicked",G_CALLBACK(on_gtk_dialog_inserido_close),
   NULL);

   gtk_builder_connect_signals(builder, NULL);

   window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
   
   stack = GTK_STACK(gtk_builder_get_object(builder, "stack"));

   list_view = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_tree_view"));
   gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(list_view), FALSE);
   int one = 1;
   init_list(list_view, "Resultado da busca", &one);

   one =1;
   patricia_view = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_tree_patrcia"));
   gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(list_view), TRUE);
   init_list(patricia_view, "Palavra", &one);


   gtk_widget_show_all(window);
   gtk_main ();
     
   return 0;
 }
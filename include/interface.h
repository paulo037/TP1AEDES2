#include <stdio.h>
#include <string.h>
#include "../include/arquivo.h"
#include <stdlib.h>
#include <gtk/gtk.h>


GtkBuilder *builder;
GtkStack *stack;
GtkWidget *list_view, *patricia_view;
GtkWidget *window, *entry;



//fechar a guia
void on_window_destroy( GtkWidget *widget, gpointer   data );

void on_button_inserir_clicked (GtkWidget * widget, gpointer data);

void on_button_pesquisar_clicked (GtkWidget * widget, gpointer data);

void on_button_mostrar_clicked (GtkWidget * widget, gpointer data);

void on_button_voltar_clicked (GtkWidget * widget, gpointer data);

void on_button_inserir_entry_clicked (GtkWidget * widget, gpointer data);

void on_view_gtk_list_result(const gchar *string);

void on_button_pesquisar_entry_clicked (GtkWidget * widget, gpointer data);

void printOrdenado(apointerTxt* arquivosTxt, GtkWidget *list_view );

GtkListBoxForeachFunc listForEach(GtkWidget *row, GtkListBox* list_view, gpointer* data);

void init_list(GtkWidget *list, char* title, int* pos);

void add_to_list(GtkWidget *list_view, const gchar *str, int pos);

void list_remove_all(GtkWidget *list_view );

void gtk_get_types(GType *tipo, int n);

void viewPat(apointerP* root, GtkWidget *pat_view, int n);

void convert(int id, int qtde, char string[]);

void on_gtk_dialog_erro_close();

void on_gtk_dialog_inserido_close();
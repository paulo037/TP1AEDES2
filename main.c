#include "TST.h"
#include <gtk/gtk.h>
#include <gtk/gtkx.h>

/*==============DECLARAÇÕES GLOBAIS=============*/

typedef struct{
    Node *raiz;
    FILE *fp;
    char palavra[30];
}user_data;

user_data data;
GtkWidget *window;
GtkWidget *container;
GtkWidget *title;

GtkWidget *label1;
GtkWidget *label2;
GtkWidget *label3;
GtkWidget *label5;

GtkWidget *button[4000];
GtkWidget *view4;
GtkWidget *grid4;

GtkBuilder *builder;

/*================Funções=================*/

int gtkmain(int argc, char *argv[]){
    int row=0;
    char aux[30];
    gtk_init(&argc,&argv);

    builder=gtk_builder_new_from_file("interface2.glade");
    window=GTK_WIDGET(gtk_builder_get_object(builder,"window"));

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit),NULL);

    container=GTK_WIDGET(gtk_builder_get_object(builder,"container"));
    title=GTK_WIDGET(gtk_builder_get_object(builder,"Title"));
    label1=GTK_WIDGET(gtk_builder_get_object(builder, "label1"));
    label2=GTK_WIDGET(gtk_builder_get_object(builder, "label2"));
    label3=GTK_WIDGET(gtk_builder_get_object(builder, "label3"));
    label5=GTK_WIDGET(gtk_builder_get_object(builder, "label5"));

    view4=GTK_WIDGET(gtk_builder_get_object(builder, "view4"));
    grid4=GTK_WIDGET(gtk_builder_get_object(builder, "grid4"));

    if(data.fp!=NULL){
        gtk_label_set_text(label2,(const gchar*)"As palavras foram inseridas com sucesso!");
        while(fgets(aux,30,data.fp)){
            aux[strlen(aux)-1]=0;
            gtk_grid_insert_row(GTK_GRID(grid4), row);
            button[row]=gtk_button_new_with_label(aux);
            gtk_button_set_alignment (GTK_BUTTON(button[row]), 0.0, 0.5);
            gtk_grid_attach(GTK_GRID(grid4),button[row],1,row,1,1);
            row++;
        }
    }
    else{
        gtk_label_set_text(label2,(const gchar*)"Falha com o arquivo!");
        strcpy(aux,"FILE ERROR!");
        gtk_grid_insert_row(GTK_GRID(grid4), row);
        button[0]=gtk_button_new_with_label(aux);
        gtk_button_set_alignment (GTK_BUTTON(button[0]), 0.0, 0.5);
        gtk_grid_attach(GTK_GRID(grid4),button[0],1,0,1,1);
    }

    GdkColor color;
    GdkColor color2;
    color.red = 0xffff;
    color.green = 0xffff;
    color.blue = 0xffff;
    color2.red=0x2f00;
    color2.green=0x2f00;
    color2.blue=0x2f00;
    gtk_widget_modify_bg(GTK_WIDGET(window), GTK_STATE_NORMAL, &color);
    gtk_widget_modify_bg(GTK_WIDGET(grid4), GTK_STATE_NORMAL, &color2);

    gtk_widget_show_all(window);
    gtk_main();

    return EXIT_SUCCESS;
}


int main(int argc, char *argv[])
{

    data.raiz=NULL;
    data.fp=fopen("Dicionario//Dictionary.txt","r");
    gtkmain(argc,argv);
    printf("PALAVRAS:\n");
    printf("\n\nPESQUISA:");
    if(data.fp!=NULL){
        search(data.raiz,"abandon")? printf("ENCONTROU\n"):printf("NAO ENCONTROU\n");
    }
    fclose(data.fp);
    return 0;
}

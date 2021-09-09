#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>

// Declarando os Widgets

GtkWidget	*window;
GtkWidget	*container;
GtkWidget	*label1;
GtkWidget	*button1;
GtkWidget	*button2;
GtkWidget	*button3;
GtkWidget	*button4;
GtkWidget	*button5;
GtkBuilder	*builder; 

int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv); // Inicializando o GTK


// Ajustando o conteúdo do Projeto.glade

 
	builder = gtk_builder_new_from_file ("Projeto.glade");
 
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

        gtk_builder_connect_signals(builder, NULL);

	container = GTK_WIDGET(gtk_builder_get_object(builder, "container"));
	button1 = GTK_WIDGET(gtk_builder_get_object(builder, "Option1"));
	button2 = GTK_WIDGET(gtk_builder_get_object(builder, "Option2"));
	button3 = GTK_WIDGET(gtk_builder_get_object(builder, "Option3"));
	button4 = GTK_WIDGET(gtk_builder_get_object(builder, "Option4"));
	button5 = GTK_WIDGET(gtk_builder_get_object(builder, "Option5"));
	label1 = GTK_WIDGET(gtk_builder_get_object(builder, "Title"));

	gtk_widget_show(window);

	gtk_main();

	return EXIT_SUCCESS;
	}

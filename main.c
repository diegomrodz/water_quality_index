#include <stdio.h>
#include <glib.h>
#include <math.h>
#include <gtk/gtk.h>
#include "iqa/iqa.h"

const char* gTemplatePath = "layout/iqa_glade_template_v100.glade";

GtkBuilder* gBuilder;
GtkWidget* gWindow;

int main(int argc, char* argv[]) 
{
    GError* err = NULL;

    gtk_init(&argc, &argv);

    gBuilder = gtk_builder_new();

    if (!gtk_builder_add_from_file(gBuilder, gTemplatePath, &err)) 
    {
        printf("Erro ao carregar layout: %s\n", err->message);
        g_free(err);
        return 0;
    }

    gWindow = GTK_WIDGET(gtk_builder_get_object(gBuilder, "window"));
    g_signal_connect(gWindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);    

    g_object_unref(G_OBJECT(gBuilder));

    gtk_widget_show(gWindow);

    gtk_main();

    return 0;
}

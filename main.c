#include <stdio.h>
#include <glib.h>
#include <math.h>
#include <gtk/gtk.h>
#include "iqa/iqa.h"

void set_spin_btn(GtkSpinButton**, char*);
void set_spin_btn_value(GtkSpinButton**, double);
double get_spin_btn_value(GtkSpinButton**);

const char* gTemplatePath = "layout/iqa_glade_template_v100.glade";

GtkBuilder* gBuilder;
GtkWidget* gWindow;

GtkSpinButton* gSpinCF;
GtkSpinButton* gSpinPH;
GtkSpinButton* gSpinDBO;
GtkSpinButton* gSpinNT;
GtkSpinButton* gSpinFT;
GtkSpinButton* gSpinDT;
GtkSpinButton* gSpinTU;
GtkSpinButton* gSpinOD;
GtkSpinButton* gSpinST;

void set_spin_btn(GtkSpinButton** obj, char* id) 
{
    *obj = GTK_SPIN_BUTTON(gtk_builder_get_object(gBuilder, id));
}

void set_spin_btn_value(GtkSpinButton** obj, double value) 
{
    gtk_spin_button_set_value(*obj, (gdouble)value);
    gtk_spin_button_update(*obj);
}

double get_spin_btn_value(GtkSpinButton** obj) 
{
    return (double)gtk_spin_button_get_value(*obj);
}

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

    { // Setting up Spin Buttons
        set_spin_btn(&gSpinCF, "spinCF");
        set_spin_btn(&gSpinPH, "spinPH");
        set_spin_btn(&gSpinDBO, "spinDBO");
        set_spin_btn(&gSpinNT, "spinNT");
        set_spin_btn(&gSpinFT, "spinFT");
        set_spin_btn(&gSpinDT, "spinDT");
        set_spin_btn(&gSpinTU, "spinTU");
        set_spin_btn(&gSpinOD, "spinOD");
        set_spin_btn(&gSpinST, "spinST");

        set_spin_btn_value(&gSpinCF, IQA_CF_WEIGHT);

        printf("%lf\n", get_spin_btn_value(&gSpinCF));        
    }

    gtk_widget_show_all(gWindow);

    gtk_main();

    return 0;
}

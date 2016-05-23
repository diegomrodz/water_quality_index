#include <stdio.h>
#include <glib.h>
#include <math.h>
#include <gtk/gtk.h>
#include "iqa/iqa.h"

void set_spin_btn(GtkSpinButton**, char*);
void set_spin_btn_value(GtkSpinButton**, double);
double get_spin_btn_value(GtkSpinButton**);
void set_entry(GtkEntry**, char*);
void set_entry_value(GtkEntry**, char*);
char* get_entry_value(GtkEntry**);

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

GtkEntry* gEntryCF;
GtkEntry* gEntryPH;
GtkEntry* gEntryDBO;
GtkEntry* gEntryNT;
GtkEntry* gEntryFT;
GtkEntry* gEntryDT;
GtkEntry* gEntryTU;
GtkEntry* gEntryOD;
GtkEntry* gEntryST;

GtkEntry* gEntryIQA;
GtkEntry* gEntryIQAIndex;

GtkButton* gBtnCalculate;
GtkButton* gBtnClean;
GtkButton* gBtnReport;
GtkButton* gBtnAbout;

void set_spin_btn(GtkSpinButton** obj, char* id) 
{
    *obj = GTK_SPIN_BUTTON(gtk_builder_get_object(gBuilder, id));
}

void set_entry(GtkEntry** obj, char* id) 
{
    *obj = GTK_ENTRY(gtk_builder_get_object(gBuilder, id));
}

void set_spin_btn_value(GtkSpinButton** obj, double value) 
{
    gtk_spin_button_set_value(*obj, value);
    gtk_spin_button_update(*obj);
}

double get_spin_btn_value(GtkSpinButton** obj) 
{
    return (double)gtk_spin_button_get_value(*obj);
}

void set_entry_value(GtkEntry** obj, char* value) 
{
    gtk_entry_set_text(*obj, value);
}

char* get_entry_value(GtkEntry** obj)
{
    return (char*)gtk_entry_get_text(*obj);
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
        set_spin_btn_value(&gSpinPH, IQA_PH_WEIGHT);
        set_spin_btn_value(&gSpinDBO, IQA_DBO_WEIGHT);
        set_spin_btn_value(&gSpinNT, IQA_NT_WEIGHT);
        set_spin_btn_value(&gSpinFT, IQA_FT_WEIGHT);
        set_spin_btn_value(&gSpinDT, IQA_DT_WEIGHT);
        set_spin_btn_value(&gSpinTU, IQA_TU_WEIGHT);
        set_spin_btn_value(&gSpinOD, IQA_O2_WEIGHT);
        set_spin_btn_value(&gSpinST, IQA_ST_WEIGHT);    
    }

    { // Setting up Entries
        set_entry(&gEntryCF, "entryCF");
        set_entry(&gEntryPH, "entryPH");
        set_entry(&gEntryDBO, "entryDBO");
        set_entry(&gEntryNT, "entryNT");
        set_entry(&gEntryFT, "entryFT");
        set_entry(&gEntryDT, "entryDT");
        set_entry(&gEntryTU, "entryTU");
        set_entry(&gEntryOD, "entryOD");
        set_entry(&gEntryST, "entryST");
    }

    gtk_widget_show_all(gWindow);

    gtk_main();

    return 0;
}

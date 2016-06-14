#include <stdio.h>
#include <glib.h>
#include <math.h>
#include <gtk/gtk.h>
#include <string.h>
#include "iqa/iqa.h"

void set_spin_btn(GtkSpinButton**, char*);
void set_spin_btn_value(GtkSpinButton**, double);
double get_spin_btn_value(GtkSpinButton**);
void set_entry(GtkEntry**, char*);
void set_entry_value(GtkEntry**, char*);
char* get_entry_value(GtkEntry**);
void set_btn(GtkButton**, char*);

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

void set_btn(GtkButton** obj, char* id) 
{
    *obj = GTK_BUTTON(gtk_builder_get_object(gBuilder, id));
}

char* util_d2s(double d) 
{
    char s[sizeof(d)];
    memcpy(&s, &d, sizeof(d));
    return s;
}

void calculate_iqa() 
{
    IQA_T iqa_t;
    IQA_W_T iqa_w_t;
    double iqa;
    
    iqa_t.O2 = atof(get_entry_value(&gEntryOD));
    iqa_t.CF = atof(get_entry_value(&gEntryCF));
    iqa_t.PH = atof(get_entry_value(&gEntryPH));
    iqa_t.DBO = atof(get_entry_value(&gEntryDBO));
    iqa_t.DT = atof(get_entry_value(&gEntryDT));
    iqa_t.NT = atof(get_entry_value(&gEntryNT));
    iqa_t.FT = atof(get_entry_value(&gEntryFT));
    iqa_t.TU = atof(get_entry_value(&gEntryTU));
    iqa_t.ST = atof(get_entry_value(&gEntryST));
    
    if ( ! validate_t(iqa_t)) 
    {
        return 0; 
    }

    iqa_w_t.O2 = get_spin_btn_value(&gSpinOD);
    iqa_w_t.CF = get_spin_btn_value(&gSpinCF);
    iqa_w_t.PH = get_spin_btn_value(&gSpinPH);
    iqa_w_t.DBO = get_spin_btn_value(&gSpinDBO);
    iqa_w_t.DT = get_spin_btn_value(&gSpinDT);
    iqa_w_t.NT = get_spin_btn_value(&gSpinNT);
    iqa_w_t.FT = get_spin_btn_value(&gSpinFT);
    iqa_w_t.TU = get_spin_btn_value(&gSpinTU);
    iqa_w_t.ST = get_spin_btn_value(&gSpinST);
    
    iqa = iqa_c(iqa_t, iqa_w_t);    

    set_entry_value(&gEntryIQA, util_d2s(iqa));

    printf("%lf", iqa);
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

    { // Setting up buttons
        set_btn(&gBtnCalculate, "btnCalculate");
        set_btn(&gBtnClean, "btnClean");
        set_btn(&gBtnReport, "btnReport");
        set_btn(&gBtnAbout, "btnAbout");

        // Button actions
        g_signal_connect(gBtnCalculate, "clicked", G_CALLBACK(calculate_iqa), NULL);
    }

    gtk_widget_show_all(gWindow);

    gtk_main();

    return 0;
}

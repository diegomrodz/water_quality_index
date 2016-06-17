#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <math.h>
#include <gtk/gtk.h>
#include <glib/gstdio.h>
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

GtkComboBox* gComboIQAIndex;

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

void set_combo_box(GtkComboBox** obj, char* id) 
{
    *obj = GTK_COMBO_BOX(gtk_builder_get_object(gBuilder, id));
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

double get_entry_value_d(GtkEntry** obj) 
{
    char* text = get_entry_value(obj);

    return atof(text);
}

void set_btn(GtkButton** obj, char* id) 
{
    *obj = GTK_BUTTON(gtk_builder_get_object(gBuilder, id));
}

void print_iqa_t(IQA_T* t) 
{
    g_printf("\tIQA_T[O2] = %lf \n", t->O2);
    g_printf("\tIQA_T[CF] = %lf \n", t->CF);
    g_printf("\tIQA_T[PH] = %lf \n", t->PH);
    g_printf("\tIQA_T[DBO] = %lf \n", t->DBO);
    g_printf("\tIQA_T[DT] = %lf \n", t->DT);
    g_printf("\tIQA_T[NT] = %lf \n", t->NT);
    g_printf("\tIQA_T[FT] = %lf \n", t->FT);
    g_printf("\tIQA_T[TU] = %lf \n", t->TU);
    g_printf("\tIQA_T[ST] = %lf \n", t->ST);
}

void print_iqa_w_t(IQA_T* t) 
{
    g_printf("\tIQA_W_T[O2] = %lf \n", t->O2);
    g_printf("\tIQA_W_T[CF] = %lf \n", t->CF);
    g_printf("\tIQA_W_T[PH] = %lf \n", t->PH);
    g_printf("\tIQA_W_T[DBO] = %lf \n", t->DBO);
    g_printf("\tIQA_W_T[DT] = %lf \n", t->DT);
    g_printf("\tIQA_W_T[NT] = %lf \n", t->NT);
    g_printf("\tIQA_W_T[FT] = %lf \n", t->FT);
    g_printf("\tIQA_W_T[TU] = %lf \n", t->TU);
    g_printf("\tIQA_W_T[ST] = %lf \n", t->ST);
}


void calculate_iqa(GtkWidget* widget) 
{
    IQA_T iqa_t;
    IQA_W_T iqa_w_t;
    IQAIndex idx;
    double result;
    char result_text[10];    

    iqa_t.O2 = get_entry_value_d(&gEntryOD);
    iqa_t.CF = get_entry_value_d(&gEntryCF);
    iqa_t.PH = get_entry_value_d(&gEntryPH);
    iqa_t.DBO = get_entry_value_d(&gEntryDBO);
    iqa_t.DT = get_entry_value_d(&gEntryDT);
    iqa_t.NT = get_entry_value_d(&gEntryNT);
    iqa_t.FT = get_entry_value_d(&gEntryFT);
    iqa_t.TU = get_entry_value_d(&gEntryTU);
    iqa_t.ST = get_entry_value_d(&gEntryST);
    
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
    
    result = iqa_c(iqa_t, iqa_w_t);

    g_print("Nova Medicao\n\n");
    g_print("\tValores do IQA:\n");
    print_iqa_t(&iqa_t);

    g_print("\n\tPesos da Medição:\n");
    print_iqa_w_t(&iqa_w_t);

    g_printf("Resultado: %lf\n", result);

    sprintf(result_text, "%lf", result);

    idx = iqa_conama_index(result);

    set_entry_value(&gEntryIQA, result_text);
    set_entry_value(&gEntryIQAIndex, iqa_index_string(idx));
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

        set_entry(&gEntryIQA, "entryIQA");
        set_entry(&gEntryIQAIndex, "entryIQAIndex");
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

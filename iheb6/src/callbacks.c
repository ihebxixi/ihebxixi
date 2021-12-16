#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fouction.h"
etudiant pe;

int x,y,ze,re,eniv;

void
on_treeview_xixi_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* ID;
gchar* type;
gchar* numero;
gchar* text;
gchar* iure;
gchar* tezs;


GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{

gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&jour,1,&mois,2,&annee,3,&nom,4,&prenom,5,&ID,6,&type,7,&numero,8,&text,9,&iure,10,&tezs,-1);
strcpy(pe.Cin,jour);
strcpy(pe.nom_etudiant,mois);
strcpy(pe.prenom_etudiant,annee);
pe.jour1=nom;
pe.mois1=prenom;
pe.annee1=ID;

strcpy(pe.choix,type);
strcpy(pe.choix1,numero);
strcpy(pe.bloc,text);

strcpy(pe.eclasse,iure);
strcpy(pe.numero_tel,tezs);
}
}


void
on_xixi_modifier_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *iheb_xixi_menu,*iheb_xixi_Modifier;
iheb_xixi_Modifier=create_xixi_modifier();
iheb_xixi_menu=lookup_widget(button,"xixi_menu");
gtk_widget_show(iheb_xixi_Modifier);
gtk_widget_hide(iheb_xixi_menu);
}


void
on_xixi_ajouter_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *iheb_xixi_menu,*iheb_xixi_Ajouter;
iheb_xixi_Ajouter=create_xixi_ajouter();
iheb_xixi_menu=lookup_widget(button,"xixi_menu");
gtk_widget_show(iheb_xixi_Ajouter);
gtk_widget_hide(iheb_xixi_menu);
}


void
on_xixi_afficher_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *xixi_menu,*w1;
GtkWidget *treeview1;
xixi_menu=lookup_widget(button,"xixi_menu");
w1=xixi_menu;
gtk_widget_hide(xixi_menu);
gtk_widget_show(w1);
treeview1=lookup_widget(button,"treeview_xixi");
afficheretudiant(treeview1);

}


void
on_xixi_refresh_treeview_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *xixi_menu;
GtkWidget *treeview;
GtkWidget *w1;

w1=lookup_widget(button,"xixi_menu");
w1= create_xixi_menu();
gtk_widget_show (w1);

xixi_menu=lookup_widget(button,"xixi_menu");

treeview=lookup_widget(xixi_menu,"treeview_xixi");
afficheretudiant(treeview);




treeview=lookup_widget(w1,"treeview_xixi");
gtk_widget_show(w1);
//afficheretudiant(treeview);
gtk_widget_hide(xixi_menu);

}


void
on_xixi_par_niveau_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *xixi_menu;
GtkWidget *treeview1;
xixi_menu=lookup_widget(button,"xixi_menu");
treeview1=lookup_widget(button,"treeview_xixi");
printf("%d \n",eniv);
etudianteniv(eniv);
afficheetudiantniv(treeview1);
}


void
on_xixi_radio_niv1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  eniv=1;
}


void
on_xixi_radio_niv2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  eniv=2;
}


void
on_xixi_radio_niv3_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  eniv=3;
}


void
on_xixi_radio_niv4_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  eniv=4;
}


void
on_xixi_radio_niv5_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  eniv=5;
}


void
on_xixi_rehcerche_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
/*
GtkWidget *xixi_menu;
GtkWidget *recherche;
GtkWidget *treeview1;
//etudiant e;
char n[30];
//xixi_menu=lookup_widget(button,"xixi_menu");
recherche=lookup_widget(button,"xixi_rehcerche1");
//treeview1=lookup_widget(button,"treeview1");
int exist=0;


strcpy(n,gtk_entry_get_text(GTK_ENTRY(recherche)));
printf("%s \n",n);
//exist=chercheretudiant("etudiant.txt",n);

//afficherEXISTANCE(treeview1);

*/
GtkWidget *xixi_menu;
GtkWidget *recherche;
GtkWidget *treeview1;
etudiant e;
char n[30];
xixi_menu=lookup_widget(button,"xixi_menu");
recherche=lookup_widget(button,"xixi_recherche2");
treeview1=lookup_widget(xixi_menu,"treeview_xixi");
int exist=0;

printf("before strcpy\n");
strcpy(n,gtk_entry_get_text(GTK_ENTRY(recherche)));
printf("%s \n",n);

printf("before chercher\n");
chercheretudiant("etudiant.txt",n);
printf("afterchercher\n");
afficherEXISTANCE(treeview1);
printf("after afficher \n");

}


void
on_xixi_supprimer_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
suppression_hebergement(pe);
}


void
on_xixi_retour_menu_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *iheb_xixi_menu,*iheb_xixi_Ajouter;
iheb_xixi_menu=create_xixi_menu();
iheb_xixi_Ajouter=lookup_widget(button,"xixi_ajouter");
gtk_widget_show(iheb_xixi_menu);
gtk_widget_hide(iheb_xixi_Ajouter);


}


void
on_xixi_valider_ajout_clicked          (GtkWidget *objet_graphique,gpointer user_data) 

{
etudiant e;

GtkWidget *cin11, *nom11, *prenom11, *jour11, *mois11, *annee11, *numtel11, *combobox_xixi_bloc, *combobox_xixi_classe,*confirmation;


cin11=lookup_widget(objet_graphique,"xixi_cin");
nom11=lookup_widget(objet_graphique,"xixi_nom");
prenom11=lookup_widget(objet_graphique,"xixi_prenom");
jour11=lookup_widget(objet_graphique,"spinbutton_xixi_jour");
mois11=lookup_widget(objet_graphique,"spinbutton_xixi_mois");
annee11=lookup_widget(objet_graphique,"spinbutton_xixi_annee");
numtel11=lookup_widget(objet_graphique,"xixi_numero");
combobox_xixi_bloc=lookup_widget(objet_graphique,"combobox_xixi_bloc");
combobox_xixi_classe=lookup_widget(objet_graphique,"combobox_xixi_classe");


e.jour1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour11));
e.mois1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois11));
e.annee1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee11));
if (x==1){strcpy(e.choix,"homme");}
if(x==0) {strcpy(e.choix,"femme");}

if (ze==1){strcpy(e.choix1,"Double");}
if(ze==0) {strcpy(e.choix1,"Triple");}

strcpy(e.bloc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_xixi_bloc)));
strcpy(e.eclasse,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_xixi_classe)));
strcpy(e.Cin,gtk_entry_get_text(GTK_ENTRY(cin11)));
strcpy(e.nom_etudiant,gtk_entry_get_text(GTK_ENTRY(nom11)));
strcpy(e.prenom_etudiant,gtk_entry_get_text(GTK_ENTRY(prenom11)));
strcpy(e.numero_tel,gtk_entry_get_text(GTK_ENTRY(numtel11)));

confirmation=create_confirmation();

gtk_widget_show(confirmation);

gtk_entry_set_text(GTK_ENTRY(cin11),"");
gtk_entry_set_text(GTK_ENTRY(nom11),"");
gtk_entry_set_text(GTK_ENTRY(prenom11),"");
gtk_entry_set_text(GTK_ENTRY(jour11),"");
gtk_entry_set_text(GTK_ENTRY(mois11),"");
gtk_entry_set_text(GTK_ENTRY(annee11),"");
gtk_entry_set_text(GTK_ENTRY(numtel11),"");
gtk_entry_set_text(GTK_ENTRY(combobox_xixi_bloc),"");
gtk_entry_set_text(GTK_ENTRY(combobox_xixi_classe),"");

ajout_etudiant(e);
}


void
on_xixi_check_femme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))

x=0;
}


void
on_xixi_check_homme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))

x=1;
}


void
on_xixi_check_double_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))

ze=1;
}


void
on_xixi_check_triple_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))

ze=0;
}


void
on_xixi_retour_menu1_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *iheb_xixi_menu,*iheb_xixi_Modifier;
iheb_xixi_menu=create_xixi_menu();
iheb_xixi_Modifier=lookup_widget(button,"xixi_modifier");
gtk_widget_show(iheb_xixi_menu);
gtk_widget_hide(iheb_xixi_Modifier);
}


void
on_xixi_valider_mofiier_clicked        (GtkWidget *objet_graphique,gpointer user_data)
{
etudiant e;

GtkWidget *cin11, *nom11, *prenom11, *jour11, *mois11, *annee11, *numtel11, *combobox_xixi_bloc, *combobox_xixi_classe;

char m[30];

nom11=lookup_widget(objet_graphique,"xixi_nom1");
prenom11=lookup_widget(objet_graphique,"xixi_prenom1");
jour11=lookup_widget(objet_graphique,"spinbutton_xixi_jour1");
mois11=lookup_widget(objet_graphique,"spinbutton_xixi_mois1");
annee11=lookup_widget(objet_graphique,"spinbutton_xixi_annee1");
numtel11=lookup_widget(objet_graphique,"xixi_numero1");
combobox_xixi_bloc=lookup_widget(objet_graphique,"combobox_xixi_bloc1");
combobox_xixi_classe=lookup_widget(objet_graphique,"combobox_xixi_classe1");


e.jour1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour11));
e.mois1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois11));
e.annee1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee11));
if (y==1){strcpy(e.choix,"homme");}
if (y==0){strcpy(e.choix,"femme");}

if (re==1){strcpy(e.choix1,"Double");}
if(re==0); {strcpy(e.choix1,"Triple");}

strcpy(e.bloc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_xixi_bloc)));
strcpy(e.eclasse,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_xixi_classe)));
strcpy(e.nom_etudiant,gtk_entry_get_text(GTK_ENTRY(nom11)));
strcpy(e.prenom_etudiant,gtk_entry_get_text(GTK_ENTRY(prenom11)));
strcpy(e.numero_tel,gtk_entry_get_text(GTK_ENTRY(numtel11)));
strcpy(m,pe.Cin);
strcpy(e.Cin,pe.Cin);

gtk_entry_set_text(GTK_ENTRY(cin11),"");
gtk_entry_set_text(GTK_ENTRY(nom11),"");
gtk_entry_set_text(GTK_ENTRY(prenom11),"");
gtk_entry_set_text(GTK_ENTRY(jour11),"");
gtk_entry_set_text(GTK_ENTRY(mois11),"");
gtk_entry_set_text(GTK_ENTRY(annee11),"");
gtk_entry_set_text(GTK_ENTRY(numtel11),"");
gtk_entry_set_text(GTK_ENTRY(combobox_xixi_bloc),"");
gtk_entry_set_text(GTK_ENTRY(combobox_xixi_classe),"");

modification_etudiant("etudiant.txt",m,e);
}


void
on_xixi_check_homme1_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))

y=1;

}


void
on_xixi_check_femme1_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))

y=0;
}


void
on_xixi_check_double1_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))

re=1;
}


void
on_xixi_check_triple1_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))

re=0;
}


void
on_xixi_confirmation_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *confirmation;
 confirmation=lookup_widget(button,"confirmation");
gtk_widget_hide(confirmation);
}


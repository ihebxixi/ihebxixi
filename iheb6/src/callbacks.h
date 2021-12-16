#include <gtk/gtk.h>


void
on_treeview_xixi_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_xixi_modifier_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_xixi_ajouter_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_xixi_afficher_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_xixi_refresh_treeview_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_xixi_par_niveau_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_xixi_radio_niv1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_xixi_radio_niv2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_xixi_radio_niv3_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_xixi_radio_niv4_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_xixi_radio_niv5_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_xixi_rehcerche_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_xixi_supprimer_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_xixi_retour_menu_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_xixi_valider_ajout_clicked          (GtkWidget *objet_graphique,gpointer user_data);

void
on_xixi_check_femme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_xixi_check_homme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_xixi_check_double_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_xixi_check_triple_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_xixi_retour_menu1_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_xixi_valider_mofiier_clicked        (GtkWidget *objet_graphique,gpointer user_data);

void
on_xixi_check_homme1_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_xixi_check_femme1_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_xixi_check_double1_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_xixi_check_triple1_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_xixi_confirmation_clicked           (GtkButton       *button,
                                        gpointer         user_data);

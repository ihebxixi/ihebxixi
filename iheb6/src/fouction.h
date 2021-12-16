#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <gtk/gtk.h>

typedef struct
{
char Cin[50];
char nom_etudiant[50];
char prenom_etudiant[50];
int jour1;
int mois1;
int annee1;
char choix[50];
char choix1[50];
char bloc[50];
char eclasse[50];
char numero_tel[50];
}etudiant;




void afficheretudiant(GtkWidget *liste);
void ajout_etudiant(etudiant e );
void modification_etudiant(char nomfichier[],char m[],etudiant e);
void suppression_hebergement(etudiant e);
int chercheretudiant(char nomfichier[],char n[]);
//void affichage_etudiant();
void afficherEXISTANCE(GtkWidget *liste);
void afficheetudiantniv(GtkWidget *liste);
void etudianteniv(int eniv);
#endif // FONCTION_H_INCLUDED

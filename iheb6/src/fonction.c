#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "fouction.h"
enum{eCin,enom_etudiant,eprenom_etudiant,ejour,emois,eanne,echoix,echoix1,eblock,eeclasse,enump,COLUMNE};

 
void ajout_etudiant (etudiant e)
{
 
	FILE *f=NULL;
	f=fopen("etudiant.txt", "a+");
	if (f!=NULL){
       fprintf(f,"%s %s %s %d %d %d %s %s %s %s %s\n",e.Cin,e.nom_etudiant,e.prenom_etudiant,e.jour1,e.mois1,e.annee1,e.choix,e.choix1,e.bloc,e.eclasse,e.numero_tel);
	fclose(f);
        

	}
       
}
void suppression_hebergement(etudiant e)
{
FILE *f=NULL;
FILE *w=NULL;
char ch1[20],ch2[20],ch3[20],ch7[20],ch8[20],ch9[20],ch10[20],ch11[20];
int ch4,ch5,ch6;
f=fopen("etudiant.txt","r");
w=fopen("new.txt","a+");printf(" %s\n",e.Cin);
if(f!=NULL){
while (fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s \n",ch1,ch2,ch3,&ch4,&ch5,&ch6,ch7,ch8,ch9,ch10,ch11)!=EOF)
{   
if(strcmp(e.Cin,ch1)!=0)
       fprintf(w,"%s %s %s %d %d %d %s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10,ch11);
    }
  fclose(f);fclose(w);
remove("etudiant.txt");rename("new.txt","etudiant.txt");}}

void afficheretudiant(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
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
char ch1[20],ch2[20],ch3[20],ch7[20],ch8[20],ch9[20],ch10[20],ch11[20];
int ch4,ch5,ch6;
store=NULL;
FILE*f=NULL;
f=fopen("etudiant.txt","r");
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",eCin,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",enom_etudiant,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",eprenom_etudiant,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",ejour,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",emois,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",eanne,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("gender",renderer,"text",echoix,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("chambre",renderer,"text",echoix1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("block",renderer,"text",eblock,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("classe",renderer,"text",eeclasse,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("telephone",renderer,"text",enump,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNE,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
if(f==NULL)
{return;}
else{
while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s ",ch1,ch2,ch3,&ch4,&ch5,&ch6,ch7,ch8,ch9,ch10,ch11)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,eCin,ch1,enom_etudiant,ch2,eprenom_etudiant,ch3,ejour,ch4,emois,ch5,eanne,ch6,echoix,ch7,echoix1,ch8,eblock,ch9,eeclasse,ch10,enump,ch11,-1);

}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

int chercheretudiant(char nomfichier[],char n[])

{

        FILE *w=NULL;
        FILE *f=NULL;
        char ch1[30],ch2[30],ch3[30],ch7[30],ch8[30],ch9[30],ch10[30],ch11[30];
        int b,a,test=0;int ch4,ch5,ch6;
        //printf("donner l'id  d'utilisateur de verifier l'existance\n");
       // scanf("%d",&b);
        f=fopen(nomfichier,"r");
        w=fopen("existetudiant.txt","w");
        printf("inside");
        if(f!=NULL) 
        {
           while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s \n",ch1,ch2,ch3,&ch4,&ch5,&ch6,ch7,ch8,ch9,ch10,ch11)!=EOF ){

                if (strcmp(n,ch1)==0)
                {
                test=1;printf("%s %s %s %d %d %d %s %s %s %s %s\n" ,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10,ch11);
	        
		/*if (w!=NULL)*/{
                fprintf(w,"%s %s %s %d %d %d %s %s %s %s %s\n" ,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10,ch11);}
                }
               
        }
        }
        if (test==0) printf("user not found\n");
        fclose(f);fclose(w);
        return test;
   }


void afficherEXISTANCE(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
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
char ch1[20],ch2[20],ch3[20],ch7[20],ch8[20],ch9[20],ch10[20],ch11[20];
int ch4,ch5,ch6;
store=NULL;
FILE*f=NULL;
f=fopen("existetudiant.txt","r");
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",eCin,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",enom_etudiant,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",eprenom_etudiant,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",ejour,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",emois,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",eanne,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("gender",renderer,"text",echoix,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("chambre",renderer,"text",echoix1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("block",renderer,"text",eblock,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("classe",renderer,"text",eeclasse,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("telephone",renderer,"text",enump,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNE,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
if(f==NULL)
{return;}
else{
while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s ",ch1,ch2,ch3,&ch4,&ch5,&ch6,ch7,ch8,ch9,ch10,ch11)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,eCin,ch1,enom_etudiant,ch2,eprenom_etudiant,ch3,ejour,ch4,emois,ch5,eanne,ch6,echoix,ch7,echoix1,ch8,eblock,ch9,eeclasse,ch10,enump,ch11,-1);

}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void modification_etudiant(char nomfichier[],char m[],etudiant e)
 {
        FILE *f=NULL;
        FILE *new=NULL;
        char ch1[20],ch2[20],ch3[20],ch7[20],ch8[20],ch9[20],ch10[20],ch11[20];
int ch4,ch5,ch6;

        f=fopen("etudiant.txt","r");
        new=fopen("new.txt","a+");
        
        if(f!=NULL)
        {
            while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s \n",ch1,ch2,ch3,&ch4,&ch5,&ch6,ch7,ch8,ch9,ch10,ch11)!=EOF)
            {

                if (strcmp(m,ch1)!=0)
                    fprintf(new,"%s %s %s %d %d %d %s %s %s %s %s\n" ,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10,ch11);
                else
                {
                   printf("donner les nouveau donnees\n");
                   
                   fprintf(new,"%s %s %s %d %d %d %s %s %s %s %s\n" ,e.Cin,e.nom_etudiant,e.prenom_etudiant,e.jour1,e.mois1,e.annee1,e.choix,e.choix1,e.bloc,e.eclasse,e.numero_tel);
                 
                }
            }
        }
        
        fclose(f);
        fclose(new);
        remove("etudiant.txt");
        rename("new.txt","etudiant.txt");
     }

void afficheetudiantniv(GtkWidget *liste){GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
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
char ch1[20],ch2[20],ch3[20],ch7[20],ch8[20],ch9[20],ch10[20],ch11[20];
int ch4,ch5,ch6;
store=NULL;
FILE*f=NULL;
f=fopen("etudiantniveau.txt","r");
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",eCin,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",enom_etudiant,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",eprenom_etudiant,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",ejour,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",emois,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",eanne,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("gender",renderer,"text",echoix,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("chambre",renderer,"text",echoix1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("block",renderer,"text",eblock,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("classe",renderer,"text",eeclasse,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("telephone",renderer,"text",enump,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNE,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
if(f==NULL)
{return;}
else{
while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s ",ch1,ch2,ch3,&ch4,&ch5,&ch6,ch7,ch8,ch9,ch10,ch11)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,eCin,ch1,enom_etudiant,ch2,eprenom_etudiant,ch3,ejour,ch4,emois,ch5,eanne,ch6,echoix,ch7,echoix1,ch8,eblock,ch9,eeclasse,ch10,enump,ch11,-1);

}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}



}

void etudianteniv(int eniv)
{     printf("inside 0\n");
        FILE *w=NULL;
        FILE *f=NULL;
        char ch1[30],ch2[30],ch3[30],ch7[30],ch8[30],ch9[30],ch10[30],ch11[30];
        int b,a,test=0;int ch4,ch5,ch6;
        f=fopen("etudiant.txt","r");
        w=fopen("etudiantniveau.txt","w");
        printf("inside\n");
        if(f!=NULL) 
        {
           while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s \n",ch1,ch2,ch3,&ch4,&ch5,&ch6,ch7,ch8,ch9,ch10,ch11)!=EOF ){
                   printf("inside while \n");
                if (eniv==atoi(ch10))
                {printf("%d \n", eniv);
printf("%s \n",ch10);
                test=1;printf("%s %s %s %d %d %d %s %s %s %s %s\n" ,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10,ch11);
	        
		/*if (w!=NULL){*/
                fprintf(w,"%s %s %s %d %d %d %s %s %s %s %s\n" ,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10,ch11);}
                /*}*/
               
        }
        }
        
        fclose(f);fclose(w);
     


}






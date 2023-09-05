#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include <string.h>

int decision;


void
on_naim_bouraoui_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget* windowOK;
FILE *d=NULL;
d=fopen("suppression.txt","w");
GtkTreeIter iter;
	gint mois;
	gint jour;
	gchar* boisson;
	gchar* produit;
	gchar* vienoiserie;
	gchar* entreedej;
	gchar* platdej;
	gchar* dessertdej;
	gchar* entreedin;
	gchar* platdin;
	gchar* dessertdin;
	semaine menu;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter ,0,&mois,1,&jour,2,&boisson,3,&produit,     4,&vienoiserie,5,&entreedej,6,&platdej,7,&dessertdej,8,&entreedin,9,&platdin,10,&dessertdin,-1);
	menu.mois=mois;
	menu.jour=jour;
	if(d!=NULL)
	{
	fprintf(d,"%d %d",menu.mois,menu.jour);
	fclose(d);
	}
	windowOK=create_naim_bouraoui_confirmation();
	gtk_widget_show(windowOK);	
}
}

void
on_button_ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowMenu;
windowMenu=create_naim_bouraoui_ajout_menu();
gtk_widget_show (windowMenu);
}


void
on_button_modif_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget * windowModif;
GtkWidget * windowMenu,* window_afficher,* treeview,* mois1,* jour1,* boiss,* fenetre_afficher,
* produits,* vien,* entreepd,* platpd,* desspd,* entreed,* platd
,* dessd;
fenetre_afficher=lookup_widget(objet_graphique,"naim_bouraoui_gestion_des_menus");
treeview=lookup_widget(fenetre_afficher,"naim_bouraoui_treeview");
GtkTreeSelection *selection;
GtkTreeIter iter;
	gint mois;
	gint jour;
	gchar* boisson;
	gchar* produit;
	gchar* vienoiserie;
	gchar* entreedej;
	gchar* platdej;
	gchar* dessertdej;
	gchar* entreedin;
	gchar* platdin;
	gchar* dessertdin;
	selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
	GtkTreeModel* model;
	if (gtk_tree_selection_get_selected(selection,&model,&iter))
	{
	gtk_tree_model_get(model,&iter,0,&mois,1,&jour,2,&boisson,3,&produit,4,&vienoiserie,	5,&entreedej,6,&platdej,7,&dessertdej,8,&entreedin,9,&platdin,10,&dessertdin,-1);
	windowModif=create_naim_bouraoui_modif_menu();
	gtk_widget_show (windowModif);

	mois1=lookup_widget(windowModif,"naim_bouraoui_spin");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois1),mois);

	jour1=lookup_widget(windowModif,"naim_bouraoui_spin1");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour1),jour);

	boiss=lookup_widget(windowModif,"naim_bouraoui_boisson1");
	gtk_entry_set_text(GTK_ENTRY(boiss),boisson);

	produits=lookup_widget(windowModif,"naim_bouraoui_produit1");
	gtk_entry_set_text(GTK_ENTRY(produits),produit);

	vien=lookup_widget(windowModif,"naim_bouraoui_vienoi1");
	gtk_entry_set_text(GTK_ENTRY(vien),vienoiserie);

	entreepd=lookup_widget(windowModif,"naim_bouraoui_entreedej1");
	gtk_entry_set_text(GTK_ENTRY(entreepd),entreedej);

	platpd=lookup_widget(windowModif,"naim_bouraoui_platdej1");
	gtk_entry_set_text(GTK_ENTRY(platpd),platdej);

	desspd=lookup_widget(windowModif,"naim_bouraoui_dessdej1");
	gtk_entry_set_text(GTK_ENTRY(desspd),dessertdej);
	
	entreed=lookup_widget(windowModif,"naim_bouraoui_entreedin1");
	gtk_entry_set_text(GTK_ENTRY(entreed),entreedin);
	
	platd=lookup_widget(windowModif,"naim_bouraoui_platdin1");
	gtk_entry_set_text(GTK_ENTRY(platd),platdin);

	dessd=lookup_widget(windowModif,"naim_bouraoui_dessdin1");
	gtk_entry_set_text(GTK_ENTRY(dessd),dessertdin);
	}
}


void
on_button_supp_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *mois1 ,*jour1, *windowOK;
semaine menu;
FILE *d=NULL;
d=fopen("suppression.txt","w");
mois1=lookup_widget(button,"naim_bouraoui_spinbuttonM1");
jour1=lookup_widget(button,"naim_bouraoui_spinbuttonM2");
menu.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
menu.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));
if(d!=NULL)
{
fprintf(d,"%d %d",menu.mois,menu.jour);
fclose(d);
}
windowOK=create_naim_bouraoui_confirmation();
gtk_widget_show(windowOK);
}


void
on_button_rechercher_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
semaine menu;

GtkWidget *fenetre_afficher, *treeview, *mois2, *jour2;
mois2=lookup_widget(button,"naim_bouraoui_spinbuttonM1");
jour2=lookup_widget(button,"naim_bouraoui_spinbuttonM2");
menu.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois2));
menu.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour2));
fenetre_afficher=lookup_widget(button,"naim_bouraoui_gestion_des_menus");
treeview=lookup_widget(fenetre_afficher,"naim_bouraoui_treeview");
chercher(menu,treeview);
}


void
on_naim_bouraoui_checkbuttons_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
decision=3;
}


void
on_naim_bouraoui_checkbuttonT_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
decision=2;
}


void
on_naim_bouraoui_Afficher_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *fenetre_mode, *fenetre_afficher, *combobox;
int numsemaine;
fenetre_afficher=lookup_widget(objet,"naim_bouraoui_gestion_des_menus");
treeview=lookup_widget(fenetre_afficher,"naim_bouraoui_treeview");

combobox=lookup_widget(objet,"naim_bouraoui_combobox");
if(decision==3)
{
if(strcmp("",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
  numsemaine=10;
if(strcmp("Semaine 1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
  numsemaine=1;
else if (strcmp("Semaine 2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
  numsemaine=2;
else if (strcmp("Semaine 3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
  numsemaine=3;
else 
  numsemaine=4;
afficher(numsemaine,treeview);
}
if (decision==2)
{
affichage(treeview);
}
}


void
on_button_valider_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
int trouvee;
semaine semaine1;
GtkWidget *mois1, *jour1, *boiss, *produits, *vien, *entreepd, *platpd, *desspd, *entreed, *platd, *dessd;
mois1=lookup_widget(button,"naim_bouraoui_mois");
jour1=lookup_widget(button,"naim_bouraoui_jour");
boiss=lookup_widget(button,"naim_bouraoui_boisson");
produits=lookup_widget(button,"naim_bouraoui_cerealier");
vien=lookup_widget(button,"naim_bouraoui_vienoiserie");
entreepd=lookup_widget(button,"naim_bouraoui_entreedej");
platpd=lookup_widget(button,"naim_bouraoui_platdej");
desspd=lookup_widget(button,"naim_bouraoui_dessertdej");
entreed=lookup_widget(button,"naim_bouraoui_entreedin");
platd=lookup_widget(button,"naim_bouraoui_platdin");
dessd=lookup_widget(button,"naim_bouraoui_dessertdin");
semaine1.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
semaine1.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));
strcpy(semaine1.petit_dej.boisson,gtk_entry_get_text(GTK_ENTRY(boiss)));
strcpy(semaine1.petit_dej.produit_cerealier,gtk_entry_get_text(GTK_ENTRY(produits)));
strcpy(semaine1.petit_dej.vienoiserie,gtk_entry_get_text(GTK_ENTRY(vien)));
strcpy(semaine1.dejeuner.entree,gtk_entry_get_text(GTK_ENTRY(entreepd)));
strcpy(semaine1.dejeuner.plat_princ,gtk_entry_get_text(GTK_ENTRY(platpd)));
strcpy(semaine1.dejeuner.dessert,gtk_entry_get_text(GTK_ENTRY(desspd)));
strcpy(semaine1.diner.entree,gtk_entry_get_text(GTK_ENTRY(entreed)));
strcpy(semaine1.diner.plat_princ,gtk_entry_get_text(GTK_ENTRY(platd)));
strcpy(semaine1.diner.dessert,gtk_entry_get_text(GTK_ENTRY(dessd)));
trouvee=trouve(semaine1);
if(trouvee==0){
ajouter(semaine1);
}
}

void
on_naim_bouraoui_radiobutton_supprimer_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
decision=1;
}


void
on_naim_bouraoui_radiobutton_annuler_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
decision=0;
}


void
on_naim_bouraoui_ok_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_confirmation;
semaine menu;
FILE *f=NULL;
f=fopen("suppression.txt","r");
if(f!=NULL)
{
fscanf(f,"%d %d",&menu.mois,&menu.jour);
fclose(f);
}
else 
printf("file not found");
fenetre_confirmation=lookup_widget(button,"naim_bouraoui_confirmation");
if(decision==1)
{
supprimer(menu);
gtk_widget_destroy(fenetre_confirmation);
//affichage(treeview);
}
else if(decision==0)
gtk_widget_destroy(fenetre_confirmation);
}


void
on_naim_bouraoui_modifier2_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
semaine semaine1;
GtkWidget *mois1, *jour1, *boiss, *produits, *vien, *entreepd, *platpd, *desspd, *entreed, *platd, *dessd;
mois1=lookup_widget(button,"naim_bouraoui_spin");
jour1=lookup_widget(button,"naim_bouraoui_spin1");
boiss=lookup_widget(button,"naim_bouraoui_boisson1");
produits=lookup_widget(button,"naim_bouraoui_produit1");
vien=lookup_widget(button,"naim_bouraoui_vienoi1");
entreepd=lookup_widget(button,"naim_bouraoui_entreedej1");
platpd=lookup_widget(button,"naim_bouraoui_platdej1");
desspd=lookup_widget(button,"naim_bouraoui_dessdej1");
entreed=lookup_widget(button,"naim_bouraoui_entreedin1");
platd=lookup_widget(button,"naim_bouraoui_platdin1");
dessd=lookup_widget(button,"naim_bouraoui_dessdin1");

semaine1.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
semaine1.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));
strcpy(semaine1.petit_dej.boisson,gtk_entry_get_text(GTK_ENTRY(boiss)));
strcpy(semaine1.petit_dej.produit_cerealier,gtk_entry_get_text(GTK_ENTRY(produits)));
strcpy(semaine1.petit_dej.vienoiserie,gtk_entry_get_text(GTK_ENTRY(vien)));
strcpy(semaine1.dejeuner.entree,gtk_entry_get_text(GTK_ENTRY(entreepd)));
strcpy(semaine1.dejeuner.plat_princ,gtk_entry_get_text(GTK_ENTRY(platpd)));
strcpy(semaine1.dejeuner.dessert,gtk_entry_get_text(GTK_ENTRY(desspd)));
strcpy(semaine1.diner.entree,gtk_entry_get_text(GTK_ENTRY(entreed)));
strcpy(semaine1.diner.plat_princ,gtk_entry_get_text(GTK_ENTRY(platd)));
strcpy(semaine1.diner.dessert,gtk_entry_get_text(GTK_ENTRY(dessd)));
modifier(semaine1);
}


void
on_naim_bouraoui_BMmenu_clicked        (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
char ch1[100],ch2[100],ch3[100];
GtkWidget* fenetre_meilleur_menu,* fenetre_Mmenu,* labelMdej,* label_M_dejeuner, * label_M_diner;
fenetre_meilleur_menu=create_naim_bouraoui_meilleur_menu();
gtk_widget_show (fenetre_meilleur_menu);
labelMdej=lookup_widget(fenetre_meilleur_menu,"naim_bouraoui_meilleurdej");
label_M_dejeuner=lookup_widget(fenetre_meilleur_menu,"naim_bouraoui_meilleur_dejeuner");
label_M_diner=lookup_widget(fenetre_meilleur_menu,"naim_bouraoui_meilleur_diner");
affiche_meileur_menu(ch1,ch2,ch3);
gtk_label_set_text(GTK_LABEL(labelMdej),ch1);
gtk_label_set_text(GTK_LABEL(label_M_dejeuner),ch2);
gtk_label_set_text(GTK_LABEL(label_M_diner),ch3);
}


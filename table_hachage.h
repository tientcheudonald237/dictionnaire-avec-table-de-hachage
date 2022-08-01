#ifndef  __HACHAGE__H__
#define  __HACHAGE__H__
#include "fonction.h"
    // declarartion de mon type  pointeur sur liste et ma structure de donnee  
typedef struct Element Element;
struct Element{
    int infos;
    char *valeur;
    Element *suivant;
};
typedef struct Liste{
    Element *premier;
}Liste;

    int hachage(char *nom);
    int hachage1(char *chaine);
    void add(Liste *tete,int cle,char *valeur);
    void init(Liste *tete);
    void affiche_element(Liste*tete,int a);




// initialiser une liste 
Liste* initialiser();

// inserer un element as la fin d'une liste chainee
void ajouter_element_liste_fin(Liste *tete,int a,char* b);

// afficher ma liste
void affiche_liste(Liste*tete);

//supprimer un element as la tete
void supprime_element_debut(Liste *tete);

void supprime_element_valeur(Liste *tete,int a);

//supprimer un element as la fin
void supprime_element(Liste *tete,int a);


#endif
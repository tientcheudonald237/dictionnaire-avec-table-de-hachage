#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "table_hachage.h"
#include "fonction.h"

int hachage(char *nom){
    int hach = 0;
    for(int i =0;i<strlen(nom);i++){
        hach += nom[i]*i ;
    }
    hach = hach % 100 ;
    return hach;   
}

int hachage1(char *chaine){
    int i = 0, nombreHache = 0;
    for (i = 0 ; chaine[i] != '\0' ; i++){
        nombreHache += chaine[i];
    }
    nombreHache %= 100;
    return nombreHache;
}

void add(Liste *tete,int cle,char *valeur){
    ajouter_element_liste_fin(tete,cle,valeur);
}

void init(Liste *tete){
    ajouter_element_liste_fin(tete,hachage("manger"), "Avaler pour se nourrir (un aliment solide ou consistant) après avoir mâché" );
    ajouter_element_liste_fin(tete,hachage("aimer"), "Éprouver de l'affection, de l'amitié, de la sympathie pour (qqn)") ;
    ajouter_element_liste_fin(tete,hachage("pleurer"), "Répandre des larmes, sous l'effet d'une émotion pénible." );
    ajouter_element_liste_fin(tete,hachage("faire"), "Réaliser hors de soi (une chose matérielle)");
    ajouter_element_liste_fin(tete,hachage("courir"), "Se déplacer par une suite d'élans, en reposant alternativement le corps sur l'une puis l'autre jambe, et à une allure, la course, plus rapide que la marche" );
    ajouter_element_liste_fin(tete,hachage("marcher"), "se deplacer sur une courte distance" );
    ajouter_element_liste_fin(tete,hachage("etudier"), "Chercher à acquérir la connaissance de") ;
    ajouter_element_liste_fin(tete,hachage("chanter"), "Former avec la voix une suite de sons musicaux (chant).") ;
}

void affiche_element(Liste*tete,int a){
    if(tete == NULL )
        exit(EXIT_FAILURE);
    Element* p = malloc(sizeof(*p));
    int i = 0;
    p = tete->premier;
    while(p != NULL){
        if(p->infos == a){
           printf("[%d] : %s\n",p->infos,p->valeur);
           i++;
           break;
        }
        p = p->suivant;
    }
    if(i == 0){
        printf(" l'element n'est pas dans le dictionnaire \n");
    }
}







// initialiser une liste chainee
Liste* initialiser(){
    Liste* tete = malloc(sizeof(*tete));
    if( tete == NULL )
        exit(EXIT_FAILURE);
    tete->premier = NULL ;
    return tete;
}

// inserer un element as la fin d'une liste chainee
void ajouter_element_liste_fin(Liste *tete,int a,char* b){
    if(tete == NULL)
        exit(EXIT_FAILURE);
    Element *element = malloc(sizeof(*element));
    element->infos = a;
    element->valeur = b;
    element->suivant = NULL ;
    if( tete->premier != NULL){
        Element* p = malloc(sizeof(*p));
        p = tete->premier;
        while(p->suivant != NULL){
            p = p->suivant;
        }
        p->suivant = element;
    }else 
        tete->premier = element ;
}

// afficher ma liste
void affiche_liste(Liste*tete){
    if(tete == NULL )
        exit(EXIT_FAILURE);
    Element* p = malloc(sizeof(*p));
    p = tete->premier;
    while(p != NULL){
        printf("[%d] : %s\n",p->infos,p->valeur);
        p = p->suivant;
    }
}

//supprimer un element as la tete
void supprime_element_debut(Liste *tete){
    if(tete == NULL)
        exit(EXIT_FAILURE);
    Element *p = malloc(sizeof(*p));
    Element *sup = malloc(sizeof(*sup));
    p = tete->premier->suivant;
    sup = tete->premier ;
    tete->premier = p ;
    free(sup);
    
}
void supprime_element(Liste *tete,int a){
    if(tete == NULL)
        exit(EXIT_FAILURE);
        Element *p = malloc(sizeof(*p));
        Element *sup = malloc(sizeof(*sup));
    p = tete->premier;
    if(p->suivant->infos == a){
        supprime_element_debut(tete);
    }else{
        supprime_element_valeur(tete,a);
    }
}
// par rapport as son infos 
void supprime_element_valeur(Liste *tete,int a){
    if(tete == NULL)
        exit(EXIT_FAILURE);
    Element *p = malloc(sizeof(*p));
    Element *sup = malloc(sizeof(*sup));
    p = tete->premier;
    while(p->suivant->infos != a){
        p = p->suivant;
    }
    sup = p->suivant;
    p->suivant = p->suivant->suivant;
    free(sup);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "table_hachage.h"
#include "fonction.h"


int main(void){
    Liste *tete = malloc(sizeof(Liste));
    tete = initialiser();
    init(tete);
    int a,b = 1;
    printf("\n\t\t*********************************** dictionnaires *********************************\n");
    do{
        printf("\nvoicie notre dictionaires de donnée : \n \t1-definir un mot \n\t2-ajouter le dictionnaire d'un mot \n\t3-supprimer le dictionnaire d'un mot \n\t4-sortir\t:");
        scanf("%d",&a);
        char *ch = malloc(sizeof(char)*20);
        switch (a){
            case 1:
                printf("entrer le mot : ");
                scanf("%s",ch);
                affiche_element(tete,hachage(ch));
                break;
            case 2:
                printf("entrer le mot : ");
                scanf("%s",ch);
                printf("entrer sa definition : ");
                char def[50];
                scanf("%s",def);
                fgets(def,50,stdin);
                ajouter_element_liste_fin(tete,hachage(ch),def) ;
                break;
            case 3:
                printf("entrer le mot : ");
                scanf("%s",ch);
                supprime_element(tete,hachage(ch));
                break;   
            default:
                exit(EXIT_FAILURE);
                break;
        }
    }while(b == 1);
    return 0;
}
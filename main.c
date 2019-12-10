/*#####################################################################
                        Projet Grapheur
#####################################################################*/
#include "jeton.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lexical.h"

int main() {
    
    /*Variables nécessaires pour tout le programme */
    //int nbr_valeur = 10;//passage en global
    float borne_inf=0;
    float borne_sup=0;
    float ymin=0;
    float ymax=0;

    short mode_debug_main=1;/* active(1) ou désactive(0) le mode debug */

    /*#####################################################################
                      Partie 1 - analyse lexicale
                Echange avec l'utilisateur sur la saisie de formule
    #####################################################################*/

    //Déclaration et allocation d'un tableau de jeton (lexem, valeur)
    typejeton* tab = (typejeton*)malloc(50*sizeof(typejeton));
    //On récupére notre valeur de retour pour la fonction lexical
    typeerreur valeur_retour;

    char str[50];
    while(strcmp(str, "quit") != 0){
        printf("\nEntrez une formule (quit pour arreter) : ");
        scanf("%s", str);
        if(strcmp(str, "quit") == 0) {
            printf("\naurevoir. \n");
            continue;
        }
        printf("\n");
        valeur_retour = lexical(str, tab);
        if(valeur_retour == FONC_INCONNUE){
            printf("Fonction inconnue.\n");
            continue;
        }
        else if(valeur_retour == PARA_ERROR){
            printf("Nombre de paranth�ses impaire.\n");
            continue;
        }
        else if(valeur_retour == OPERATEUR_ERROR){
            printf("Opérateur sans ses deux opérandes autour.\n");
            continue;
        }
        else if(valeur_retour == VARIABLE_ERROR){
            printf("Problèmes de variables.\n");
            continue;
        }

        //affichage du tableau de la partie 1 - pour mise en commun du code
        if (mode_debug_main==1){
            printf("\nAffichage du tableau de la partie 1\n");
            affichage_tableau_lexical(tab);
        }
        /*#####################################################################
                      Partie 2 - analyse syntaxique
        Construction de l'arbre, basé sur le tableau fourni par la partie 1
        #####################################################################*/
        if (mode_debug_main==1){
            printf("\nAffichage de la construction de l'arbre partie 2\n");
        }
        
        /*
        **
        *CODE
        **
        */
        
        /*#####################################################################
                      Partie 3 - Evaluateur
                Evaluation de l'arbre fourni par la partie 2
        #####################################################################*/
        /*
        **
        *CODE
        **
        */

        //On demande nos bornes pour l'affichage du graphe
        //Borne inf
        borne_inf=0;
        printf("\nEntrez votre borne inférieure : ");
        scanf("%f", &borne_inf);

        //Borne sup
        borne_sup=borne_inf;
        /* controle sur les bornes fournies : */
        while (borne_sup<=borne_inf)
        {
            printf("\nEntrez votre borne supérieure à la borne inférieure : ");
            scanf("%f", &borne_sup);
        }
        
        if (mode_debug_main==1){
            printf("\nBorne inf et sup : %f - %f \n",borne_inf, borne_sup);
        }
        
        /*
        **
        *CODE
        **
        */
        

        /*#####################################################################
                      Partie 4 - Grapheur
            Traçage de la courbe 
        #####################################################################*/
        
        /*
        **
        *CODE
        **
        */
    
    }


    return 0;
}

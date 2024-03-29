/*#####################################################################
                        Projet Grapheur
#####################################################################*/
#include "jeton.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "syntaxique.h"
#include "lexical.h"
#include "evaluateur.h"
#include "grapheur.h"

Couple tab_valeur[nbr_valeur];
float offset;
float scale;
float Translate_x;
float Translate_y;

//int main() {// pour partie normale
int main(int argc, char** argv){//pour grapheur
    

    /*Variables nécessaires pour tout le programme */
    //int nbr_valeur = 10;//passage en global
    float borne_inf=0;
    float borne_sup=0;
    float ymin=0;
    float ymax=0;

    short mode_debug_main=0;/* active(1) ou désactive(0) le mode debug */

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
        int i=0;
        /* Construction de l'arbre */
        Arbre monArbre;
        monArbre = syntaxe(tab, &i);
        if (mode_debug_main==1){
            printf("i : %d\n",i);
            printf("Lexem racine de l'arbre : %d\n",monArbre->jeton.lexem);
            printf("valeur racine de l'arbre : %f\n\n",monArbre->jeton.valeur.reel);

            if(monArbre->pjeton_preced!= NULL){
                printf("Lexem gauche de l'arbre : %d\n",monArbre->pjeton_preced->jeton.lexem);
                printf("valeur reel gauche de l'arbre : %f\n",monArbre->pjeton_preced->jeton.valeur.reel);
            }else{
                printf("pj preced NULL \n");
            }
            
            if(monArbre->pjeton_suiv!= NULL){
                printf("Lexem droite de l'arbre : %d\n",monArbre->pjeton_suiv->jeton.lexem);
            }else{
                printf("pj suivant NULL \n");
            }
            printf("\nFIN Affichage de la construction de l'arbre partie 2\n\n");
        }
        
        /*#####################################################################
                      Partie 3 - Evaluateur
                Evaluation de l'arbre fourni par la partie 2
        #####################################################################*/
        if (mode_debug_main==1){
            float z = 0;
            z = evaluer(monArbre, 4);
            printf("voila la valeur z : %f\n\n\n",z);//affichage du r�sultat
        }

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
        
        // On définit le nombre de valeurs à évaluer
        // voir si le graphique nous permettra de le demander à l'utilisateur par la suite
        //nbr_valeur = 10;//passage en global

        //On déclare un tableau de couples avec nbr_valeur
        //Couple tab_valeur[nbr_valeur]; //passage en global

        ymin=0;
        ymax=0;
        
        // remplissage du tableau de couples, et retour des ymin et ymax
        remplis_tab_couple(borne_inf, borne_sup, nbr_valeur, monArbre, tab_valeur, &ymin, &ymax);
        //on fourni la borne inf, sup, nbr_valeur, l'arbre, et le tableau de couples
        
        // affichage du tableau en attendant d'avoir le grapheur
        affiche_tab_couple(tab_valeur, nbr_valeur);

        /* Voici les valeur fournies par la partie 3 à la partie 4 : */
        //xmin xmax ymin ymax et le tableau de couples
        
        printf("Bornes de x : min= %f - max= %f \n",borne_inf,borne_sup);
        printf("Bornes de y : min= %f - max= %f \n",ymin,ymax);
        

        /*#####################################################################
                      Partie 4 - Grapheur
            Traçage de la courbe 
        #####################################################################*/
        
        //Initialisation de l'offset
        offset= 1.0 / (ymax - ymin);
        //Initialisation de l'échelle
		scale= 1.0 / (borne_sup - borne_inf);
        //Initialisation de la position
		Translate_x= 0.0;
		Translate_y= 0.0;
        //Dessin de la courbe
    	InitGraph(argc, argv, "Grapheur", 1280, 720, Dessin, Cle);
    
    }


    return 0;
}

#include "jeton.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "syntaxique.h"
#include "lexical.h"
#include "evaluateur.h"
#include "grapheur.h"

int main() {

    //Tableau de jeton (lexem, valeur)
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

        //affichage du tableau
        printf("\nAffichage du tableau de la partie 1\n");
        affichage_tableau_lexical(tab);
        
        printf("\nAffichage de la construction de l'arbre partie 2\n");
        int i=0;
        /* Commenté par JT pour tester avec un arbre manuel*/
        Arbre monArbre;
        monArbre = syntaxe(tab, &i);
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
        
        //possibilité d'afficher l'arbre reçu ?
        /* Fin Commenté par JT pour tester avec un arbre manuel*/

        ////////////////////////////////////
        //Rajout Julien T pour tester avec un arbre monté à la main
            
            /* début de la génération de l'arbre de test */
            /* equation exemple  : f(x)=abs(2x))
            donc arbre : abs -> abs -> x -> x
                                            -> 2
            */
                /*Arbre Arb2 = (Arbre)malloc(sizeof(struct Node));//reservation de l'espace
                Arb2->pjeton_preced=NULL;
                Arb2->pjeton_suiv=NULL;
                Arb2->jeton.lexem=REEL;
                Arb2->jeton.valeur.reel=2;

                Arbre Arbx = (Arbre)malloc(sizeof(struct Node));//reservation de l'espace;
                Arbx->pjeton_preced=NULL;
                Arbx->pjeton_suiv=NULL;
                Arbx->jeton.lexem=VARIABLE;
                //Arbx->jeton.valeur.reel=x;

                Arbre Arbplus = (Arbre)malloc(sizeof(struct Node));//reservation de l'espace;;
                Arbplus->pjeton_preced=Arb2;
                Arbplus->pjeton_suiv=Arbx;
                Arbplus->jeton.lexem=OPERATEUR;
                Arbplus->jeton.valeur.operateur=FOIS;

                Arbre Arbfonction = (Arbre)malloc(sizeof(struct Node));//reservation de l'espace;;
                Arbfonction->pjeton_preced=Arbplus;
                Arbfonction->pjeton_suiv=NULL;
                Arbfonction->jeton.lexem=FONCTION;
                Arbfonction->jeton.valeur.fonction=ABS;

                Arbre Arbabs = (Arbre)malloc(sizeof(struct Node));//reservation de l'espace;;
                Arbabs->pjeton_preced=Arbfonction;
                Arbabs->pjeton_suiv=NULL;
                Arbabs->jeton.lexem=FONCTION;
                Arbabs->jeton.valeur.fonction=ABS;*/
            //Fin de générationd d'un arbre manuellement
        //////////////////////////////////
        
        //float x = 3;
        float z = 0;
        z = evaluer(monArbre, 4);
        printf("voila la valeur z : %f\n\n\n",z);//affichage du r�sultat

        /* Commenté par JT - le résultat n'est pas bon meme avec l'arbre fait en manuel*/

        //On demande nos bornes pour l'affichage du graphe
        //Borne inf
        float borne_inf=0;
        printf("\nEntrez la borne inf�rieure : ");
        scanf("%f", &borne_inf);

        //Borne sup
        float borne_sup=0;
        printf("\nEntrez la borne sup�rieur : ");
        scanf("%f", &borne_sup);

        //printf("\nBorne inf et sup : %f - %f \n",borne_inf, borne_sup);//Tests JT

        // On initialise un nombre de valeur max
        int nbr_valeur = 10;

        //tableau de nbe valeur couples
        Couple tab_valeur[nbr_valeur];
    
        /* Commenté par JT - problème pour passer les float en argument à la fonction*/
        // je teste d'entrée dans la fonction ce qui est en argument et je n'obtiens que des 0
        // remplissage du tableau
        remplis_tab_couple(borne_inf, borne_sup, nbr_valeur, monArbre, tab_valeur);

        // affichage du tableau
        affiche_tab_couple(tab_valeur, nbr_valeur);
        printf("\n");
        offset_x= 1.0 / (ymax - xmin);
		scale_x= 1.0 / (ymax - xmin);
		Translate_x= -xmin;
		Translate_y= -ymin;
		InitGraph(argc, argv, "Grapheur", 1280, 720, Dessin, Cle);
    }

    return 0;
}

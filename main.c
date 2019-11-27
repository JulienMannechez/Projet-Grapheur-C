#include "jeton.h"

int main() {

    //Tableau de jeton (lexem, valeur)
    typejeton* tab = (typejeton*)malloc(50*sizeof(typejeton));
    //On récupère notre valeur de retour pour la fonction lexical
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
            printf("Nombre de paranthèses impaire.\n");
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

        int i = 0;
        Arbre monArbre;
        monArbre = syntaxe(tab, &i);

        float x = 33;
        float y = 0;
        y = evaluer(monArbre, x);
        printf("voila la valeur y : %f\n\n\n",y);//affichage du résultat

        //On demande nos bornes pour l'affichage du graphe
        //Borne inf
        float borne_inf;
        printf("\nEntrez la borne inférieure : ");
        scanf("%f", &borne_inf);

        //Borne sup
        float borne_sup;
        printf("\nEntrez la borne supérieur : ");
        scanf("%f", &borne_sup);

        // On initialise un nombre de valeur max
        int nbr_valeur = 10;

        //tableau de nbe valeur couples
        Couple tab_valeur[nbr_valeur];

        // remplissage du tableau
        remplis_tab_couple(borne_inf, borne_sup, nbr_valeur, monArbre, tab_valeur);


        // affichage du tableau
        affiche_tab_couple(tab_valeur, nbr_valeur);


        printf("\n");
    }

    return 0;
}

#include "lexical.h"

int main() {

    //Tableau de jeton (lexem, valeur)
    typejeton* tab = (typejeton*)malloc(50*sizeof(typejeton));
    //On r�cup�re notre valeur de retour pour la fonction lexical
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
            printf("Op�rateur sans ses deux op�randes autour.\n");
            continue;
        }
        else if(valeur_retour == VARIABLE_ERROR){
            printf("Probl�mes de variables.\n");
            continue;
        }

        int i = 0;
        Arbre A = syntaxe(tab, &i);

        //On demande nos bornes pour l'affichage du graphe
        //Borne inf
        float borne_inf;
        printf("\nEntrez la borne inf�rieure : ");
        scanf("%f", &borne_inf);


        //Borne sup
        float borne_sup;
        printf("\nEntrez la borne sup�rieur : ");
        scanf("%f", &borne_sup);


        printf("\n");
    }

    return 0;
}

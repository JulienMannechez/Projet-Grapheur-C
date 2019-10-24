#include "lexical.h"

int main() {

    //Tableau de jeton (lexem, valeur)
    typejeton t[50];
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
        valeur_retour = lexical(str, t);
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

        //On demande nos bornes pour l'affichage du graphe
        //Borne inf
        float borne_inf;
        printf("\nEntrez la borne inférieure : ");
        scanf("%f", &borne_inf);


        //Borne sup
        float borne_sup;
        printf("\nEntrez la borne supérieur : ");
        scanf("%f", &borne_sup);

        
        printf("\n");
    }

    return 0;
}
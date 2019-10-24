#include "lexical.h"

int main() {

    //Tableau de jeton (lexem, valeur)
    typejeton t[50];
    //On récupère notre valeur de retour pour la fonction lexical
    typeerreur valeur_retour;

    char str[50];
    while(strcmp(str, "quit") != 0){
        printf("Entrez une formule (quit pour arreter) : ");
        scanf("%s", str);
        if(strcmp(str, "quit") == 0) {
            printf("\naurevoir. \n");
            continue;
        }
        printf("\n");
        valeur_retour = lexical(str, t);
        if(valeur_retour == SYNTAX_ERROR){
            printf("Fonction inconnue.\n");
            continue;
        } 

        //On demande nos bornes pour l'affichage du graphe
        //Borne inf
        int borne_inf;
        printf("\nEntrez la borne inférieure : ");
        scanf("%d", &borne_inf);

        //Borne sup
        int borne_sup;
        printf("\nEntrez la borne supérieur : ");
        scanf("%d", &borne_sup);
        
        printf("\n");
    }

    return 0;
}
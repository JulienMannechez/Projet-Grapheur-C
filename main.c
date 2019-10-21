#include "lexical.h"

int main() {

    //Tableau de jeton (lexem, valeur)
    typejeton t[50];

    //On récupère notre valeur de retour pour la fonction lexical
    //Si diférent de 1, c'est qu'il y a eu une erreur
    int valeur_retour = 0;

    char str[50];
    while(valeur_retour != 1){
        printf("Entrez une formule : ");
        scanf("%s", str);
        printf("\n");
        valeur_retour = lexical(str, t);
    }

    //for(int i = 0; i < sizeof(t); i++) {

    //}

    //On demande nos bornes pour l'affichage du graphe

    //Borne inf
    int borne_inf;
    printf("Entrez la borne inférieure : ");
    scanf("%d", &borne_inf);
    printf("\n");

    //Borne sup
    int borne_sup;
    printf("Entrez la borne supérieur : ");
    scanf("%d", &borne_sup);
    printf("\n");

    return 0;
}
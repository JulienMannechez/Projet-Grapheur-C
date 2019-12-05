#ifndef EVALUATEUR_H
#define EVALUATEUR_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "jeton.h"



/* Effectue le calcul de la valeur de x par la fonction définie dans l'arbre A */
float evaluer(Arbre A, float val_x);
/* Prend en argument un arbre et la valeur de la variable x */
/* Retourne un float avec le résultat */

/* Fonction qui retourne l'absolu d'un float */
/* Nécessaire car la fonction absolu de math.h retourne un double */
float absolu(float f);

/* Affiche le tableau de couples passé en argument*/
void affiche_tab_couple(Couple tab[], int taille_tab);

/* remplis le tableauremplis_tab_couple de couples x,f(x)*/
void remplis_tab_couple(float min_x, float max_x, int nbr_valeur, Arbre Arbre, Couple tableau[], float* y_min, float* ymax);
/* Prend en arguments le min et le max de x, 
    le nombre de valeurs (précision), l'arbre de la fonction 
    le tableau à remplir 
    et l'adresse du x et du y max que l'on souhaite retourner */

#endif

#ifndef EVAL_H
#define EVAL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "jeton.h"

/* Effectue de calcul de la valeur de x par la fonction définie dans l'arbre A */
float evaluer(Arbre A, float val_x);
/* Prend en argument un arbre et la valeur de la variable x */
/* Retourne un float avec le résultat */

/* Fonction qui retourne l'absolu d'un float */
/* Nécessaire car la fonction absolu de math.h retourne un double */
float absolu(float f);

/* Affiche le tableau de couples passé en argument*/
void affiche_tab_couple(Couple tab[], int taille_tab);

/* remplis le tableau de couples x,f(x)
    prend en arguments le min et le max de x, le nombre de valeurs (précision), l'arbre de la fonction et le tableau à remplir */
void remplis_tab_couple(float min, float max, int nbe_valeur, Arbre Arbre, Couple tableau[]);

#endif
#ifndef EVALUATEUR_H
#define EVALUATEUR_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "jeton.h"



/* Effectue de calcul de la valeur de x par la fonction d�finie dans l'arbre A */
float evaluer(Arbre A, float val_x);
/* Prend en argument un arbre et la valeur de la variable x */
/* Retourne un float avec le r�sultat */

/* Fonction qui retourne l'absolu d'un float */
/* N�cessaire car la fonction absolu de math.h retourne un double */
float absolu(float f);

/* Affiche le tableau de couples pass� en argument*/
void affiche_tab_couple(Couple tab[], int taille_tab);

/* remplis le tableauremplis_tab_couple de couples x,f(x)
    prend en arguments le min et le max de x, le nombre de valeurs (pr�cision), l'arbre de la fonction et le tableau � remplir */
void remplis_tab_couple(float min_x, float max_x, int nbr_valeur, Arbre Arbre, Couple tableau[]);

#endif

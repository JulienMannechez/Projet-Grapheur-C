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

/* fonction qui retourne l'absolu d'un float */
/* nécessaire car la fonction absolu de math.h retourne un double */
float absolu(float f);

#endif
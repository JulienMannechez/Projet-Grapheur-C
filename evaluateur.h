#ifndef EVALUATEUR_H
#define EVALUATEUR_H
/*#####################################################################
                      Partie 3 - Evaluateur
                Evaluation de l'arbre fourni par la partie 2

                        Julien TISSIER
#####################################################################*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "jeton.h"

/* Effectue le calcul de la valeur de x, par la fonction définie dans l'arbre A */
float evaluer(Arbre A, float val_x);
/* Prend en argument un arbre et la valeur à évaluer */
/* Retourne un float avec le résultat */

/* Fonction qui retourne l'absolu d'un float */
float absolu(float f);
/* Nécessaire car la fonction absolu de math.h retourne un double */

/* Affiche le tableau de couples passé en argument*/
void affiche_tab_couple(Couple tab[], int taille_tab);
/* Nécessaire pour l'avancement du projet, en attendant la partie 4 */

/* Remplis le tableau de couples x,f(x) qui sera fourni à la partie 4*/
void remplis_tab_couple(float min_x, float max_x, int nbr_valeur, Arbre Arbre, Couple tableau[], float* y_min, float* ymax);
/* Prend en arguments le min et le max de x, 
    le nombre de valeurs à évaluer (précision), 
    l'arbre de la fonction 
    le tableau de couples à remplir 
    et l'adresse du x et du y max que l'on souhaite récupérer */
#endif

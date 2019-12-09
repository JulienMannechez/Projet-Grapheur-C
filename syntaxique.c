#include <stdio.h>
#include <stdlib.h>
#include "syntaxique.h"

//Fonction qui créer un arbre (noeud ou feuille) 
Arbre createArbre(typejeton tj, Arbre A, Arbre B){
    Arbre resultat = (Arbre)malloc(sizeof(struct Node));
    resultat->jeton.lexem=tj.lexem;
    if (tj.lexem==REEL)
    {   
        resultat->jeton.valeur=tj.valeur;
        resultat->jeton.valeur.reel=tj.valeur.reel; //Pour les réels il faut préciser .valeur.reel

    }else
    {
        resultat->jeton.valeur=tj.valeur;
    }
    resultat->pjeton_preced=A;
    resultat->pjeton_suiv=B;
    return(resultat);
}

//Fonction qui analyse et traverse un tableau placé en parametre pour créer un arbre binaire correspondant
Arbre syntaxe(typejeton* tab , int* i){
    Arbre A, temp, newA;
    A = (Arbre)malloc(sizeof(struct Node));
    temp = (Arbre)malloc(sizeof(struct Node));
    newA = (Arbre)malloc(sizeof(struct Node));
    int compteur_par_ouv = 1;
    int indice_tab;
    while (tab[*i].lexem != FIN){
        switch (tab[*i].lexem){
	    //On traite le cas où tab[*i] est un reel	
            case REEL:
                    newA = createArbre(tab[*i], NULL, NULL);
                    *i = *i + 1;

                break;

            //On traite le cas où tab[*i] est une variable (x)
            case VARIABLE:
                    newA = createArbre(tab[*i], NULL, NULL);
                    *i = *i +1;
                break;
	    //On traite le cas où tab[*i] est un opérateur
            case OPERATEUR:
                    indice_tab = (*i)+1;
                    temp = syntaxe(tab, &indice_tab);//On crée un arbre temporaire que l'on va placer dans l'arbre à la suite de la fonction avec le pointeur suivant
                    newA = createArbre(tab[*i],newA,temp);//On recreer l'arbre pour placer l'operateur au bon endroit dans l'arbre 
                    if(tab[*i+3].lexem == PAR_FERM){
                        *i = *i + 3;
                    }else{
                        *i = *i+2;
                    }
                break;
	    //On traite le cas où tab[*i] est une fonction
            case FONCTION:
                {
                    int*  j = (int*)malloc(sizeof(int));
                    *j = *i + 1;
                    temp = syntaxe(tab, j);//On crée un arbre temporaire que l'on va placer dans l'arbre à la suite de la fonction avec le pointeur precedent
                    newA = createArbre(tab[*i], temp, NULL);//On recreer l'arbre pour placer la fonction au bon endroit dans l'arbre 
                    int k = *j+1;

                    if(tab[k].lexem == FONCTION){   
                        while(tab[k].lexem != PAR_FERM && compteur_par_ouv!=1){
                            k++;
                            if(tab[k].lexem == PAR_OUV){ 
                                compteur_par_ouv++; //On compte le nombre de parentheses ouvrante pour arreter la fonction au bon moment
                            }
                            if(tab[k].lexem == PAR_FERM && compteur_par_ouv > 1){
                                compteur_par_ouv--;//On compte le nombre de parentheses ouvrante pour arreter la fonction au bon moment
                            }
                        }
                        *i = k;//*i = k pour que la fonction reprenne au bon endroit
                    }
                    if(tab[*i+5].lexem == PAR_FERM){
                        *i=*i+6;
                    }else if(tab[*i+3].lexem == PAR_FERM){
                        *i=*i+4;
                    }
                }
                break;
	    //On traite le cas où tab[*i] est une parenthese ouverte
            case PAR_OUV:
                    *i = *i +1;

                break;
            //On traite le cas où tab[*i] est une parenthese fermante
            case PAR_FERM:
                    *i = *i +1;
                break;

            default:
                    *i = *i +1;

                break;
        }

    }
    return newA;

}



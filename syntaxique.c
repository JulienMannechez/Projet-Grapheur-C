#include <stdio.h>
#include <stdlib.h>
#include "syntaxique.h"

Arbre createArbre(typejeton tj, Arbre A, Arbre B){
    Arbre resultat = (Arbre)malloc(sizeof(struct Node));
    resultat->jeton.lexem=tj.lexem;
    resultat->jeton.valeur=tj.valeur;
    resultat->pjeton_preced=A;
    resultat->pjeton_suiv=B;
    return(resultat);
    ////printf("test");
}


Arbre syntaxe(typejeton* tab , int* i){
    ////printf("%d",*i);
    Arbre A, temp, newA;
    A = (Arbre)malloc(sizeof(struct Node));
    temp = (Arbre)malloc(sizeof(struct Node));
    newA = (Arbre)malloc(sizeof(struct Node));
    int indice_tab;
    ////printf("%d", *i);
    while (tab[*i].lexem != FIN){
        switch (tab[*i].lexem){

            case REEL:
                /*if(tab[*i+1].lexem != OPERATEUR && tab[*i+1].lexem!=PAR_FERM){
                    typejeton* tj = (typejeton*)malloc(sizeof(typejeton));
                    tj->lexem=ERREUR;
                    tj->valeur.reel=202;
                    A = createArbre(*tj,NULL,NULL);
                    //printf("REELa %d \n",*i);
                    *i = *i +1;

                }else{*/
                    newA = createArbre(tab[*i], NULL, NULL);
                    //printf("REEL %d \n",*i);
                     if(tab[*i+1].lexem!= PAR_FERM){
                        *i = *i +1;
                    }else{
                        *i = *i +2;
                    }

               // }
                break;

            case VARIABLE:
                /*if(tab[*i+1].lexem!=OPERATEUR && tab[*i+1].lexem!=PAR_FERM){
                    typejeton* tj = (typejeton*)malloc(sizeof(typejeton));
                    tj->lexem=ERREUR;
                    tj->valeur.reel=203;
                    A = createArbre(*tj,NULL,NULL);
                    //printf("VAR %d\n",*i);
                    *i = *i +1;

                }else{*/
                    newA = createArbre(tab[*i], NULL, NULL);
                    //printf("VAR %d\n",*i);
                    if(tab[*i+1].lexem!= PAR_FERM){
                        *i = *i +1;
                    }else{
                        *i = *i +2;
                    }


                //}
                break;

            case OPERATEUR:
                /*if(tab[*i+1].lexem!=REEL && tab[*i+1].lexem!=VARIABLE){
                    typejeton* tj = (typejeton*)malloc(sizeof(typejeton));
                    tj->lexem=ERREUR;
                    tj->valeur.reel=200;
                    A=createArbre(*tj,NULL,NULL);
                    *i = *i +1;

                }else if(tab[*i+2].lexem!=PAR_FERM){
                    typejeton* tj = (typejeton*)malloc(sizeof(typejeton));
                    tj->lexem=ERREUR;
                    tj->valeur.reel=201;
                    A=createArbre(*tj,NULL,NULL);
                    *i = *i +1;

                }else{*/
                    ////printf("%d\n",indice_tab);
                    indice_tab = (*i)+1;
                    temp = syntaxe(tab, &indice_tab);
                    newA = createArbre(tab[*i],A,temp);
                    //printf("OPE %d\n",*i);
                    *i= *i+2;

                //}
                break;

            case FONCTION:
                if(tab[*i+1].lexem != PAR_OUV){
                    typejeton* tj = (typejeton*)malloc(sizeof(typejeton));
                    tj->lexem=ERREUR;
                    tj->valeur.reel=204;
                    newA=createArbre(*tj,NULL,NULL);
                    *i = *i +1;

                }else{
                    int* j = (int*)malloc(sizeof(int));
                    *j = *i + 1;
                    ////printf("%d",*i);
                    temp = syntaxe(tab, j);
                    newA = createArbre(tab[*i], temp, NULL);
                    //printf("FONC %d\n",*i);
                    *i = *i+6;
                }
                break;

            case PAR_OUV:
                    //printf("par_ouv %d\n", *i);
                    *i = *i +1;

                break;

            case PAR_FERM:
                    //printf("par_fer %d\n", *i);
                    *i = *i +1;
                break;

            default:
                    *i = *i +1;

                break;
        }

    }
    return A;

}



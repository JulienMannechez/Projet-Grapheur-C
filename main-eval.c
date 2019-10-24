#include "eval.h"

int main() {
    printf("### MAIN - debut de programme ###\n");
    /* code temporaire pour tester pendant mon travail */
    float x = 33;
    float y = 0;
    
    /* début de la génération de l'arbre de test */
    /* equation exemple  : f(x)=abs(sin(x+2))
       donc arbre : abs -> sin -> + -> x
                                    -> 2
    */
    Arbre Arb2 = (Arbre)malloc(sizeof(struct Node));//reservation de l'espace
    Arb2->pjeton_preced=NULL;
    Arb2->pjeton_suiv=NULL;
    Arb2->jeton.lexem=REEL;
    Arb2->jeton.valeur.reel=2;

    Arbre Arbx = (Arbre)malloc(sizeof(struct Node));//reservation de l'espace;
    Arbx->pjeton_preced=NULL;
    Arbx->pjeton_suiv=NULL;
    Arbx->jeton.lexem=VARIABLE;
    Arbx->jeton.valeur.reel=x;

    Arbre Arbplus = (Arbre)malloc(sizeof(struct Node));//reservation de l'espace;;
    Arbplus->pjeton_preced=Arb2;
    Arbplus->pjeton_suiv=Arbx;
    Arbplus->jeton.lexem=OPERATEUR;
    Arbplus->jeton.valeur.operateur=FOIS;

    Arbre Arbfonction = (Arbre)malloc(sizeof(struct Node));//reservation de l'espace;;
    Arbfonction->pjeton_preced=Arbplus;
    Arbfonction->pjeton_suiv=NULL;
    Arbfonction->jeton.lexem=FONCTION;
    Arbfonction->jeton.valeur.fonction=ABS;

    Arbre Arbabs = (Arbre)malloc(sizeof(struct Node));//reservation de l'espace;;
    Arbabs->pjeton_preced=Arbfonction;
    Arbabs->pjeton_suiv=NULL;
    Arbabs->jeton.lexem=FONCTION;
    Arbabs->jeton.valeur.fonction=ABS;

    /* Fin de la génération de l'arbre de test */
    /* Lancement de la fonction evaluer présente dans le fichier eval.c */
    printf("###Test de la fonction Evaluer\n");
    y = evaluer(Arbabs, x);//lancement de la fonction evaluer (Julien T) pour tester
    printf("voila la valeur y : %f\n\n\n",y);//affichage du résultat

    printf("###Test de remplissage d'un tableau\n");
    /* valeurs qui peuvent changer */ 
    
    float min=0, max=10;
    int nbe_valeur=5;

    Couple tab[nbe_valeur];//tableau de nbe valeur couples
    
    /* remplissage du tableau */
    remplis_tab_couple(min, max, nbe_valeur, Arbabs, tab);


    /* affichage du tableau */
    affiche_tab_couple(tab,nbe_valeur);

    printf("### MAIN - fin de programme ###\n\n");//sortie du programme
    return 0;
}
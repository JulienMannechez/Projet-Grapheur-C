#ifndef JETON_H
#define JETON_H
/*Jeton .h donné pour le projet */
/*#####################################################################
                      JETON.H commun à toutes les parties

#####################################################################*/

//énumération des différents types de lexems existants
typedef enum{
    REEL,OPERATEUR,FONCTION,ERREUR,FIN,PAR_OUV,PAR_FERM,VARIABLE,BAR_OUV,BAR_FERM,ABSOLU
}typelexem;

//énumération des différents types d'opérateurs existants
typedef enum{
    PLUS,MOINS,FOIS,DIV,PUIS
}typeoperateur;

//énumération des différents types de fonctions existantes
typedef enum{
    ABS,SIN,SQRT,LOG,COS,TAN,EXP,ENTIER,VAL_NEG,SINC
}typefonction;

//énumération des différents types typeerreur de type ENUM
typedef enum {
    RAS, FONC_INCONNUE, PARA_ERROR, OPERATEUR_ERROR, VARIABLE_ERROR,
}typeerreur;

//Construction du type typevaleur
typedef union{
    float reel;
    typefonction fonction;
    typeoperateur operateur;
    typeerreur erreur;
}typevaleur;

//Construction de la structure jeton
typedef struct{
    typelexem lexem;
    typevaleur valeur;
}typejeton;

//Construction de la structure des noeuds de l'arbre
typedef struct Node{
    typejeton jeton;
    struct Node *pjeton_preced;
    struct Node *pjeton_suiv;
} Node;

//Définition de l'arbre, qui est un pointeur vers un noeud
typedef Node *Arbre;

//Construction de la structure couple, pour stocker les couples x et y=f(x)
typedef struct {
    float x;
    float y;
} Couple;

#endif
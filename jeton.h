#ifndef JETON_H
#define JETON_H

//�num�ration des diff�rents types de lexems existants
typedef enum{
    REEL,OPERATEUR,FONCTION,ERREUR,FIN,PAR_OUV,PAR_FERM,VARIABLE,BAR_OUV,BAR_FERM,ABSOLU
}typelexem;

//�num�ration des diff�rents types d'op�rateur existants
typedef enum{
    PLUS,MOINS,FOIS,DIV,PUIS
}typeoperateur;

//�num�ration des diff�rents types de fonctions existantes
typedef enum{
    ABS,SIN,SQRT,LOG,COS,TAN,EXP,ENTIER,VAL_NEG,SINC
}typefonction;

//Ajout la strucutre typeerreur de type ENUM
typedef enum {
    RAS, FONC_INCONNUE, PARA_ERROR, OPERATEUR_ERROR, VARIABLE_ERROR,
}typeerreur;

//�num�ration des diff�rents types de valeurs existantes
typedef union{
    float reel;
    typefonction fonction;
    typeoperateur operateur;
    typeerreur erreur;
}typevaleur;

//�num�ration des diff�rents types de jetons existants
typedef struct{
    typelexem lexem;
    typevaleur valeur;
}typejeton;

//d�claration de l'arbre
typedef struct Node{
    typejeton jeton;
    struct Node *pjeton_preced;
    struct Node *pjeton_suiv;
} Node;

typedef Node *Arbre;

// Rajout de ligne de Julien T pour stocker les couples x et y=f(x)
typedef struct {
    float x;
    float y;
} Couple;

#endif
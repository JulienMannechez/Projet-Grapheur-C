/*Jeton .h donné dans le cours */
typedef enum{
    REEL,OPERATEUR,FONCTION,ERREUR,FIN,PAR_OUV,PAR_FERM,VARIABLE,BAR_OUV,BAR_FERM,ABSOLU
}typelexem;

typedef enum{
    PLUS,MOINS,FOIS,DIV,PUIS
}typeoperateur;

typedef enum{
    ABS,SIN,SQRT,LOG,COS,TAN,EXP,ENTIER,VAL_NEG,SINC
}typefonction;

/* Ajout la strucutre typeerreur de type ENUM */
typedef enum {
    RAS, FONC_INCONNUE, SYNTAX_ERROR,
}typeerreur;

typedef union{
    float reel;
    typefonction fonction;
    typeoperateur operateur;
    typeerreur erreur;
}typevaleur;

typedef struct{
    typelexem lexem;
    typevaleur valeur;
}typejeton;

typedef struct Node{
    typejeton jeton;
    struct Node *pjeton_preced;
    struct Node *pjeton_suiv;  
} Node;

typedef Node *Arbre;

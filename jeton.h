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

/*Rajout de ligne de Julien T pour prendre en compte type erreur
qui n'est pas defini de base, le type erreur est un entier */
typedef struct {
    int num_erreur;/* le code erreur de retour */
}typeerreur;
/*Fin des lignes ajoutées par Julien T*/

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

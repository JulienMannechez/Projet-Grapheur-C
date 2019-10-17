/*Jeton .h donné dans le cours */

//énumération des différents types de lexems existants
typedef enum{
    REEL,OPERATEUR,FONCTION,ERREUR,FIN,PAR_OUV,PAR_FERM,VARIABLE,BAR_OUV,BAR_FERM,ABSOLU
}typelexem;

//énumération des différents types d'opérateur existants
typedef enum{
    PLUS,MOINS,FOIS,DIV,PUIS
}typeoperateur;

//énumération des différents types de fonctions existantes
typedef enum{
    ABS,SIN,SQRT,LOG,COS,TAN,EXP,ENTIER,VAL_NEG,SINC
}typefonction;

/*Rajout de ligne de Julien T pour prendre en compte type erreur
qui n'est pas defini de base, le type erreur est un entier */
typedef struct {
    int num_erreur;/* le code erreur de retour */
}typeerreur;
/*Fin des lignes ajoutées par Julien T*/

//énumération des différents types de valeurs existantes
typedef union{
    float reel;
    typefonction fonction;
    typeoperateur operateur;
    typeerreur erreur;
}typevaleur;

//énumération des différents types de jetons existants
typedef struct{
    typelexem lexem;
    typevaleur valeur;
}typejeton;

//déclaration de l'arbre
typedef struct Node{
    typejeton jeton;
    struct Node *pjeton_preced;
    struct Node *pjeton_suiv;  
} Node;

typedef Node *Arbre;

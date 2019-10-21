#include "eval.h"

/* ### fonction qui retourne l'absolu d'un float ### */
/* nécessaire car la fonction absolu de math.h retourne un double */
float absolu(float f){
    if(f<0){
        return -f;
    }
    else{
        return f;
    }
}

/* ### Fonction evaluer ### */
/* Son rôle est de traiter le code postfixé produit en sortie par l'analyseur syntaxique
 (ou parcourir l’arbre) et de permettre la production des couples (x,f(x)) à destination du grapheur */

/* Effectue de calcul de la valeur de x par la fonction définie dans l'arbre A */
float evaluer(Arbre A, float val_x){
    printf("#Entrée dans la fonction evaluer \n");
    
    /* variables locales x et y pour calcul des valeurs et des valeurs enfants */
    float y;
    float z;
    
    /* on commence par étudier le cas du jeton en cours de traitement */
    switch (A->jeton.lexem)
    {
    case REEL:/* si c'est on reel on renvoie directement la valeur du reel */
        printf("#Cas lexem reel \n");
        printf("#float : %f\n",A->jeton.valeur.reel);
        return A->jeton.valeur.reel;
        break;
    
    case VARIABLE:/* si c'est une variable on renvoie directement la valeur de x passée en argument */
        printf("#Cas lexem variable \n");
        printf("#float : %f\n",val_x);
        return val_x;
        break;
    
    case FONCTION:/* si c'est une fonction, on calcule le contenu de l'enfant de la fonction et on applique la fontion au résultat obtenu */
        
        printf("#Cas fonction \n");
        y = evaluer(A->pjeton_preced,val_x);//on calcule le contenu de la fonction 
        switch (A->jeton.valeur.fonction)//selon la fonction on fait le calcul correspondant
        {//fonctions à traiter : SIN,COS,ABS,SQRT,LOG,TAN,EXP,ENTIER,VAL_NEG,SINC
        case SIN:
            printf("#Cas fonction SINUS \n");
            printf("#valeur = %f\n",sin(y));
            return sin(y);
            break;
        case COS:
            printf("#Cas fonction COSINUS \n");
            printf("#valeur y avant cos = %f\n",y);
            printf("#valeur = %f\n",cos(y));
            return cos(y);
            break;
        case ABS:
            printf("#Cas fonction ABSOLU \n");
            printf("#valeur avant abs = %f\n",y);
            return absolu(y);
            break;
        case SQRT:
            printf("#Cas fonction SQRT (racine caree) \n");
            printf("#valeur avant sqrt = %f\n",y);
            return sqrtf(y);//On utilise la fonction sqrtf afin de traiter avec des float
            break;
        case LOG:/* fonction log népérien */
            printf("#Cas fonction LOG \n");
            printf("#valeur avant ln = %f\n",y);
            /* Il faudra vérifier que y est supérieur à 0, sinon c'est code erreur */
            if (y<=0){
               printf("ERR demande ln d'un nombre <= 0 \n");
            }
            return log(y);
            break;
        case TAN:
            printf("#Cas fonction TAN \n");
            printf("#valeur y avant tan = %f\n",y);
            return tanf(y);/* On utilise la fonction tanf afin de traiter avec des float */
            break;
        case EXP:/* fonction exponentielle de y */
            printf("#Cas fonction EXP \n");
            printf("#valeur y avant exp = %f\n",y);
            return exp(y);/* On utilise la fonction exp2f afin de traiter avec des float */
            break;
        case ENTIER:/* fonction qui retourne la partie entière de y */
            /* a noter la definition de la partie entiere : 
            "le plus grand entier inférieur ou égal à un nombre donné" */
            printf("#Cas fonction partie entiere \n");
            printf("#valeur y avant partie entière = %f\n",y);
            return floorf(y);
            break;
        case VAL_NEG:/* fonction qui retourne la valeur négative de y */
            printf("#Cas fonction valeur neg \n");
            printf("#valeur y avant valeur neg = %f\n",y);
            return -absolu(y);
            break;
        case SINC:/* fonction qui retourne le sinus cardinal de y */
            /* a noter que sinc(x)=sin(x)/x */
            printf("#Cas fonction sinus cardinal \n");
            printf("#valeur y avant sinus cardinal = %f\n",y);
            /* Il faudra vérifier que y est différent de 0, sinon c'est code erreur */
            if (y==0){
                   printf("ERR DIVISION PAR 0 \n");
            }
            return sin(y)/y;
            break;

        default:
            printf("#Cas fonction non implementee \n");
            /* retourner un code d'erreur : fonction non implementee dans le code */
            break;
        }
        return y;//on retourne le résultat du calcul avec l'application de la fonction
        break;

    case OPERATEUR:/* si c'est un opérateur, on calcule le contenu des deux enfants de la fonction et on applique l'opération au résultat */
        printf("##Cas operateur \n");
        y = evaluer(A->pjeton_preced,val_x);//calcul de l'enfant 1
        z = evaluer(A->pjeton_suiv,val_x);//calcul de l'enfant 2
            switch (A->jeton.valeur.operateur)//selon l'opérateur on fait le calcul correspondant
            {//opérations à traiter : PLUS,MOINS,FOIS,DIV,PUIS
            case PLUS:
                printf("##Cas operateur PLUS \n");
                printf("##valeur y = %f\n",y);
                printf("##valeur z = %f\n",z);
                printf("##valeur addition = %f\n",y+z);
                return y+z;
                break;
            case MOINS:
                printf("##Cas operateur MOINS \n");
                printf("##valeur y = %f\n",y);
                printf("##valeur z = %f\n",z);
                printf("##valeur soustraction = %f\n",y-z);
                return y-z;
                break;
            case FOIS:
                printf("##Cas operateur FOIS \n");
                printf("##valeur y = %f\n",y);
                printf("##valeur z = %f\n",z);
                printf("##valeur multiplication = %f\n",y*z);
                return y*z;
                break;
            case DIV:
                printf("##Cas operateur DIV \n");
                printf("##valeur y = %f\n",y);
                printf("##valeur z = %f\n",z);
                /* Il faudra vérifier que z est différent de 0, sinon c'est code erreur */
                if (z==0){
                    printf("ERR DIVISION PAR 0 \n");
                }
                
                printf("##valeur division = %f\n",y/z);
                return y/z;
                break;
            case PUIS:
                printf("##Cas operateur PUIS \n");
                printf("##valeur y = %f\n",y);
                printf("##valeur z = %f\n",z);
                printf("##valeur puissance = %f\n",pow(y,z));
                return pow(y,z);
                break;
            default:
                break;
            }
        break;

    default:
        break;
    }

    printf("#sortie de la fonction evaluer \n");
    return y;//on en sortie retourne le résultat de l'arbre (A) appliqué à la valeur de x (val_x)
}

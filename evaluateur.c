/* Fonction Evaluer - Julien TISSIER - Pas de second membre de binôme */

#include "evaluateur.h"

/* ### Fonction absolu - Retourne l'absolu d'un float ### */
float absolu(float f){
    if(f<0){/* Si f est négatif on retourne -f*/
        return -f;
    }
    else{/* Sinon on retourne directement f*/
        return f;
    }
}/* nécessaire car la fonction absolu de math.h retourne un double */


/* ### Fonction evaluer - Retourne un float qui a pour valeur f(x) ### */
    /* Son rôle est de traiter le code postfixé produit en sortie par l'analyseur syntaxique
    (ou parcourir l’arbre) et de permettre la production des couples (x,f(x)) à destination du grapheur
    on lui passe en paramètres l'arbre créé par l'analyseur syntaxique et la valeur de x à évaluer */

/* Effectue le calcul de la valeur de x par la fonction définie dans l'arbre A, et retourne la valeur f(x) */
float evaluer(Arbre A, float val_x){
    short mode_debug=0;/* Mode debug - 1 pour actif */

    if (mode_debug==1){printf("#Entrée dans la fonction evaluer \n");}

    /* variables float locales x et y nécessaire pour le calcul des valeurs et des valeurs enfants */
    float y;
    float z;

    /* on commence par étudier le jeton en cours de traitement */
    switch (A->jeton.lexem)/* on regarde le lexem dans le jeton en cours de traitement */
    {
        case REEL:/* si le lexem est un reel, on renvoie directement la valeur du reel */
            if (mode_debug==1){
                printf("#Cas lexem reel \n");
                printf("#float : %f\n",A->jeton.valeur.reel);
            }
            return A->jeton.valeur.reel;
            break;

        case VARIABLE:/* si le lexem est une variable, on renvoie directement la valeur de x passée en argument */
            if (mode_debug==1){
                printf("#Cas lexem variable \n");
                printf("#float : %f\n",val_x);
            }
            return val_x;
            break;

        case FONCTION:/* si c'est une fonction, on calcule le contenu de l'enfant de la fonction et on applique la fontion au résultat obtenu */

            if (mode_debug==1){printf("#Cas fonction \n");}

            y = evaluer(A->pjeton_preced,val_x);//on calcule le contenu de l'enfant, on le stocke dans y, et on applique la fonction à y

            switch (A->jeton.valeur.fonction)//selon la fonction, on fait le calcul correspondant
            {//fonctions à traiter : SIN,COS,ABS,SQRT,LOG,TAN,EXP,ENTIER,VAL_NEG,SINC
                case SIN:
                    if (mode_debug==1){
                        printf("#Cas fonction SINUS \n");
                        printf("#valeur = %f\n",sin(y));
                    }
                    return sin(y);
                    break;
                case COS:
                    if (mode_debug==1){
                        printf("#Cas fonction COSINUS \n");
                        printf("#valeur y avant cos = %f\n",y);
                        printf("#valeur = %f\n",cos(y));
                    }
                    return cos(y);
                    break;
                case ABS:
                    if (mode_debug==1){
                        printf("#Cas fonction ABSOLU \n");
                        printf("#valeur avant abs = %f\n",y);
                    }
                    return absolu(y);
                    break;
                case SQRT:
                    if (mode_debug==1){
                        printf("#Cas fonction SQRT (racine caree) \n");
                        printf("#valeur avant sqrt = %f\n",y);
                        /* Vérif que y est supérieur ou égal à 0, sinon c'est indéfini */
                        if (y<0){
                        printf("ERR demande SQRT d'un nombre < 0 \n");
                        }
                    }
                    return sqrtf(y);/* On utilise la fonction sqrtf afin de traiter uniquement avec des types float */
                    break;
                case LOG:/* fonction log népérien */
                    if (mode_debug==1){
                        printf("#Cas fonction LOG \n");
                        printf("#valeur avant ln = %f\n",y);
                        /* Vérif que y est supérieur à 0, sinon c'est indéfini */
                        if (y<=0){
                        printf("ERR demande ln d'un nombre <= 0 \n");
                        }
                    }
                    return log(y);
                    break;
                case TAN:
                    if (mode_debug==1){
                        printf("#Cas fonction TAN \n");
                        printf("#valeur y avant tan = %f\n",y);
                    }
                    return tanf(y);/* On utilise la fonction tanf afin de traiter uniquement avec des types float */
                    break;
                case EXP:/* fonction exponentielle de y */
                    if (mode_debug==1){
                        printf("#Cas fonction EXP \n");
                        printf("#valeur y avant exp = %f\n",y);
                    }
                    return exp(y);
                    break;
                case ENTIER:/* fonction qui retourne la partie entière de y */
                    /* a noter la definition de la partie entiere : "le plus grand entier inférieur ou égal à un nombre donné" */
                    if (mode_debug==1){
                        printf("#Cas fonction partie entiere \n");
                        printf("#valeur y avant partie entière = %f\n",y);
                    }
                    return floorf(y);
                    break;
                case VAL_NEG:/* fonction qui retourne la valeur négative de y */
                    if (mode_debug==1){
                        printf("#Cas fonction valeur neg \n");
                        printf("#valeur y avant valeur neg = %f\n",y);
                    }
                    return -absolu(y);/* on retourne l'oposé de l'absolu de y */
                    break;
                case SINC:/* fonction qui retourne le sinus cardinal de y */
                    /* a noter que sinc(x)=sin(x)/x */
                    if (mode_debug==1){
                        printf("#Cas fonction sinus cardinal \n");
                        printf("#valeur y avant sinus cardinal = %f\n",y);

                        /* Vérifier que y est différent de 0, sinon c'est indéfini */
                        if (y==0){
                            printf("ERR Division par 0 dans le sinus cardinal (x=0) \n");
                        }
                    }
                    return sin(y)/y;
                    break;

                default:
                    if (mode_debug==1){
                        printf("#Cas fonction non implementee \n");
                    }
                    break;
            }
            return y;//on retourne le résultat de l'application de la fonction sur l'objet enfant
            break;

        case OPERATEUR:/* si c'est un opérateur, on calcule le contenu des deux enfants de la fonction et on applique l'opération au résultat */
            if (mode_debug==1){printf("##Cas operateur \n");}
            y = evaluer(A->pjeton_preced,val_x);//calcul de l'enfant 1
            z = evaluer(A->pjeton_suiv,val_x);//calcul de l'enfant 2
                switch (A->jeton.valeur.operateur)//selon l'opérateur on fait le calcul correspondant
                {//opérations à traiter : PLUS,MOINS,FOIS,DIV,PUIS
                    case PLUS:
                        if (mode_debug==1){
                            printf("##Cas operateur PLUS \n");
                            printf("##valeur y = %f\n",y);
                            printf("##valeur z = %f\n",z);
                            printf("##valeur addition = %f\n",y+z);
                        }
                        return y+z;
                        break;
                    case MOINS:
                        if (mode_debug==1){
                            printf("##Cas operateur MOINS \n");
                            printf("##valeur y = %f\n",y);
                            printf("##valeur z = %f\n",z);
                            printf("##valeur soustraction = %f\n",y-z);
                        }
                        return y-z;
                        break;
                    case FOIS:
                        if (mode_debug==1){
                            printf("##Cas operateur FOIS \n");
                            printf("##valeur y = %f\n",y);
                            printf("##valeur z = %f\n",z);
                            printf("##valeur multiplication = %f\n",y*z);
                        }
                        return y*z;
                        break;
                    case DIV:
                        if (mode_debug==1){
                            printf("##Cas operateur DIV \n");
                            printf("##valeur y = %f\n",y);
                            printf("##valeur z = %f\n",z);

                            /* Vérifier que z est différent de 0, sinon c'est indéfini */
                            if (z==0){
                                printf("ERR DIVISION PAR 0 \n");
                            }


                            printf("##valeur division = %f\n",y/z);
                        }
                        return y/z;
                        break;
                    case PUIS:
                        if (mode_debug==1){
                            printf("##Cas operateur PUIS \n");
                            printf("##valeur y = %f\n",y);
                            printf("##valeur z = %f\n",z);
                            printf("##valeur puissance = %f\n",pow(y,z));
                        }
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

/* Affiche le tableau de couples passé en argument*/
void affiche_tab_couple(Couple tab[], int taille_tab){
    printf("#Fonction d'affichage du tableau de couples \n");
    int i;
    for (i = 0; i <= taille_tab; i++)
    {
        printf("x=%f | y=%f\n",tab[i].x,tab[i].y);
    }
    printf("\n\n");
}

/* remplis le tableau de couples x,f(x)
    prend en arguments le min et le max de x, le nombre de valeurs (précision), l'arbre de la fonction et le tableau à remplir */
void remplis_tab_couple(float min, float max, int nbr_valeur, Arbre Arbre, Couple tableau[]){
    printf("#Fonction de remplissage du tableau de couples \n");
    int j=0;/* sert pour l'indice du tableau */

    /*#### ajout code pour avoir min et max de y (si les groupe grapheur en a besoin)*/
    float miny,maxy;
    miny = evaluer(Arbre,min);//on stocke la première valeur au départ
    maxy = evaluer(Arbre,min);
    /*#### fin ajout code pour avoir min et max de y (si les groupe grapheur en a besoin)*/
    float i;
    for (i = min; i <= max; i=i+((max-min)/nbr_valeur))/* On parcours l'axe des x du min au max en utilisant le pas calculé automatiquement */
    {
        //printf("j=%d - x=%f - y=%f\n",j,i,i);/* affichage pour debug */
        tableau[j].x=i;
        tableau[j].y=evaluer(Arbre,i);

        /*#### ajout code pour avoir min et max de y (si les groupe grapheur en a besoin)*/
        if (evaluer(Arbre,i)<miny)
        {
            miny=evaluer(Arbre,i);
        }
        if (evaluer(Arbre,i)>maxy)
        {
            maxy=evaluer(Arbre,i);
        }
        /*#### fin ajout code pour avoir min et max de y (si les groupe grapheur en a besoin)*/

        j++;/* on passe à la case suivante du tableau */
    }

    /*#### ajout code pour avoir min et max de y (si les groupe grapheur en a besoin)*/
    printf("min en y : %f - max en y : %f\n",miny,maxy);
    /*#### fin ajout code pour avoir min et max de y (si les groupe grapheur en a besoin)*/

    printf("#Fin de fonction de remplissage du tableau de couples \n\n");
}

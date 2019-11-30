/* Fonction Evaluer - Julien TISSIER - Pas de second membre de bin�me */

#include "evaluateur.h"

/* ### Fonction absolu - Retourne l'absolu d'un float ### */
float absolu(float f){
    if(f<0){/* Si f est n�gatif on retourne -f*/
        return -f;
    }
    else{/* Sinon on retourne directement f*/
        return f;
    }
}/* n�cessaire car la fonction absolu de math.h retourne un double */


/* ### Fonction evaluer - Retourne un float qui a pour valeur f(x) ### */
    /* Son r�le est de traiter le code postfix� produit en sortie par l'analyseur syntaxique
    (ou parcourir l�arbre) et de permettre la production des couples (x,f(x)) � destination du grapheur
    on lui passe en param�tres l'arbre cr�� par l'analyseur syntaxique et la valeur de x � �valuer */

/* Effectue le calcul de la valeur de x par la fonction d�finie dans l'arbre A, et retourne la valeur f(x) */
float evaluer(Arbre A, float val_x){
    short mode_debug=0;/* Mode debug - 1 pour actif */

    if (mode_debug==1){printf("#Entrée dans la fonction evaluer \n");}

    if (mode_debug==1){// teste du arbre null, ou affiche le numéro du lexem en cours
        if (A == NULL){
            printf("#L'arbre passé est NULL\n");
        }
        else
        {
            printf("#Voici le numéro du lexem en cours d'evaluation: %d  \n",A->jeton.lexem);
        }
    }

    /* variables float locales x et y n�cessaire pour le calcul des valeurs et des valeurs enfants */
    float y;
    float z;

    /* on commence par �tudier le jeton en cours de traitement */
    switch (A->jeton.lexem)/* on regarde le lexem dans le jeton en cours de traitement */
    {
        case REEL:/* si le lexem est un reel, on renvoie directement la valeur du reel */
            if (mode_debug==1){
                printf("#Cas lexem reel \n");
                printf("#float : %f\n",A->jeton.valeur.reel);
            }
            return A->jeton.valeur.reel;
            break;

        case VARIABLE:/* si le lexem est une variable, on renvoie directement la valeur de x pass�e en argument */
            if (mode_debug==1){
                printf("#Cas lexem variable \n");
                printf("#float : %f\n",val_x);
            }
            return val_x;
            break;

        case FONCTION:/* si c'est une fonction, on calcule le contenu de l'enfant de la fonction et on applique la fontion au r�sultat obtenu */

            if (mode_debug==1){printf("#Cas fonction \n");}

            y = evaluer(A->pjeton_preced,val_x);//on calcule le contenu de l'enfant, on le stocke dans y, et on applique la fonction � y

            switch (A->jeton.valeur.fonction)//selon la fonction, on fait le calcul correspondant
            {//fonctions � traiter : SIN,COS,ABS,SQRT,LOG,TAN,EXP,ENTIER,VAL_NEG,SINC
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
                        /* V�rif que y est sup�rieur ou �gal � 0, sinon c'est ind�fini */
                        if (y<0){
                        printf("ERR demande SQRT d'un nombre < 0 \n");
                        }
                    }
                    return sqrtf(y);/* On utilise la fonction sqrtf afin de traiter uniquement avec des types float */
                    break;
                case LOG:/* fonction log n�p�rien */
                    if (mode_debug==1){
                        printf("#Cas fonction LOG \n");
                        printf("#valeur avant ln = %f\n",y);
                        /* V�rif que y est sup�rieur � 0, sinon c'est ind�fini */
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
                case ENTIER:/* fonction qui retourne la partie enti�re de y */
                    /* a noter la definition de la partie entiere : "le plus grand entier inf�rieur ou �gal � un nombre donn�" */
                    if (mode_debug==1){
                        printf("#Cas fonction partie entiere \n");
                        printf("#valeur y avant partie enti�re = %f\n",y);
                    }
                    return floorf(y);
                    break;
                case VAL_NEG:/* fonction qui retourne la valeur n�gative de y */
                    if (mode_debug==1){
                        printf("#Cas fonction valeur neg \n");
                        printf("#valeur y avant valeur neg = %f\n",y);
                    }
                    return -absolu(y);/* on retourne l'opos� de l'absolu de y */
                    break;
                case SINC:/* fonction qui retourne le sinus cardinal de y */
                    /* a noter que sinc(x)=sin(x)/x */
                    if (mode_debug==1){
                        printf("#Cas fonction sinus cardinal \n");
                        printf("#valeur y avant sinus cardinal = %f\n",y);

                        /* V�rifier que y est diff�rent de 0, sinon c'est ind�fini */
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
            return y;//on retourne le r�sultat de l'application de la fonction sur l'objet enfant
            break;

        case OPERATEUR:/* si c'est un op�rateur, on calcule le contenu des deux enfants de la fonction et on applique l'op�ration au r�sultat */
            if (mode_debug==1){printf("##Cas operateur \n");}
            y = evaluer(A->pjeton_preced,val_x);//calcul de l'enfant 1
            z = evaluer(A->pjeton_suiv,val_x);//calcul de l'enfant 2
                switch (A->jeton.valeur.operateur)//selon l'op�rateur on fait le calcul correspondant
                {//op�rations � traiter : PLUS,MOINS,FOIS,DIV,PUIS
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

                            /* V�rifier que z est diff�rent de 0, sinon c'est ind�fini */
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
    return y;//on en sortie retourne le r�sultat de l'arbre (A) appliqu� � la valeur de x (val_x)
}

/* Affiche le tableau de couples pass� en argument*/
void affiche_tab_couple(Couple tab[], int taille_tab){
    printf("#Fonction d'affichage du tableau de couples \n");
    for (int i = 0; i <= taille_tab; i++)
    {
        printf("x=%f | y=%f\n",tab[i].x,tab[i].y);
    }
    printf("\n\n");
}

/* remplis le tableau de couples x,f(x)
    prend en arguments le min et le max de x, le nombre de valeurs (pr�cision), l'arbre de la fonction et le tableau � remplir */
void remplis_tab_couple(float min_x, float max_x, int nbr_valeur, Arbre Arbre, Couple tableau[]){
    short mode_debug=1;

    if (mode_debug==1){
        printf("#Fonction de remplissage du tableau de couples \n");
        printf("#borne min entrée : %f\n",min_x);
        printf("#borne max entrée : %f\n",max_x);
        printf("#nombre de valeurs demandées : %d\n",nbr_valeur);
    }

    int j=0;/* sert pour l'indice du tableau */

    /*#### ajout code pour avoir min et max de y (si les groupe grapheur en a besoin)*/
    float min_y,max_y;
    min_y = evaluer(Arbre,min_x);//on stocke la premi�re valeur au d�part
    if (mode_debug==1){printf("#minimum de départ = %f\n",min_y);}
    max_y = evaluer(Arbre,min_x);
    if (mode_debug==1){printf("#max de départ = %f\n",max_y);}
    /*#### fin ajout code pour avoir min et max de y (si les groupe grapheur en a besoin)*/
    float i;
    for (i = min_x; i <= max_x; i=i+((max_x-min_x)/nbr_valeur))/* On parcours l'axe des x du min au max en utilisant le pas calcul� automatiquement */
    {
        if (mode_debug==1){printf("j=%d - x=%f - y=%f\n",j,i,evaluer(Arbre,i));}/* affichage pour debug */
        tableau[j].x=i;
        tableau[j].y=evaluer(Arbre,i);

        /*#### ajout code pour avoir min et max de y (si les groupe grapheur en a besoin)*/
        if (evaluer(Arbre,i)<min_y)
        {
            min_y=evaluer(Arbre,i);
        }
        if (evaluer(Arbre,i)>max_y)
        {
            max_y=evaluer(Arbre,i);
        }
        /*#### fin ajout code pour avoir min et max de y (si les groupe grapheur en a besoin)*/

        j++;/* on passe � la case suivante du tableau */
    }

    /*#### ajout code pour avoir min et max de y (si les groupe grapheur en a besoin)*/
    if (mode_debug==1){printf("min en y : %f - max en y : %f\n",min_y,max_y);}
    /*#### fin ajout code pour avoir min et max de y (si les groupe grapheur en a besoin)*/

    if (mode_debug==1){printf("#Fin de fonction de remplissage du tableau de couples \n\n");}
}

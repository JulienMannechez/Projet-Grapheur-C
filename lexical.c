#include "lexical.h"

typeerreur lexical(char str[], typejeton* tab){

    //D�claratabions etab initialisation des variables
    typeerreur valeur_retour;
    valeur_retour = RAS;
    int i = 0;
    int j = 0;
    int k = 0;
    int x = 0;
    char str_fonction[10];
    str_fonction[0] = '\0';
    char str_reel[5];
    int chaine_trouvee = 0;
    int mon_reel = 0;
    int compteur_para = 0;

    //printf("str entr�e : %s \n\n",str);

    //Parcours de la chaine de caract�re qu'on re�oit
    while(str[i] != '\0'){

        switch(str[i]) {
            //V�rification des caract�res que l'on re�oit
            case '(' :
                tab[x].lexem = PAR_OUV;
                x++;
                compteur_para++;
                break;
            case ')' :
                tab[x].lexem = PAR_FERM;
                x++;
                compteur_para++;

                break;
            case '+' :
                tab[x].lexem = OPERATEUR;
                tab[x].valeur.operateur = PLUS;
                x++;
                break;
            case '-' :
                tab[x].lexem = OPERATEUR;
                tab[x].valeur.operateur = MOINS;
                x++;
                break;
            case '*' :
                tab[x].lexem = OPERATEUR;
                tab[x].valeur.operateur = FOIS;
                x++;
                break;
            case '/' :
                tab[x].lexem = OPERATEUR;
                tab[x].valeur.operateur = DIV;
                x++;
                break;
            case '^' :
                tab[x].lexem = OPERATEUR;
                tab[x].valeur.operateur = PUIS;
                x++;
                break;
            case 'x' :
                tab[x].lexem = VARIABLE;
                x++;
                break;

            //On test la FONCTION

            default :
                //Si la chaine est entre A et Z ou a et z ou _
                if(((((int)str[i] >= 65) && ((int)str[i] <= 90)) || ( ((int)str[i] >= 97) && ((int)str[i] <= 122)) ) || ((int)str[i] == 95) ) {
                    str_fonction[j] = toupper(str[i]);
                    j++;
                    str_fonction[j] = '\0';
                    chaine_trouvee = 0;
                }
                if(chaine_trouvee == 0 && strcmp(str_fonction,"ABS") == 0){
                    j = 0;
                    tab[x].lexem = FONCTION;
                    tab[x].valeur.fonction = ABS;
                    chaine_trouvee++;
                    x++;
                }
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"SIN") == 0){
                    j = 0;
                    tab[x].lexem = FONCTION;
                    tab[x].valeur.fonction = SIN;
                    chaine_trouvee++;
                    x++;
                }
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"SQRT") == 0){
                    j = 0;
                    tab[x].lexem = FONCTION;
                    tab[x].valeur.fonction = SQRT;
                    chaine_trouvee++;
                    x++;
                }
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"LOG") == 0){
                    j = 0;
                    tab[x].lexem = FONCTION;
                    tab[x].valeur.fonction = LOG;
                    chaine_trouvee++;
                    x++;
                }
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"COS") == 0){
                    j = 0;
                    tab[x].lexem = FONCTION;
                    tab[x].valeur.fonction = COS;
                    chaine_trouvee++;
                    x++;
                }
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"TAN") == 0){
                    j = 0;
                    tab[x].lexem = FONCTION;
                    tab[x].valeur.fonction = TAN;
                    chaine_trouvee++;
                    x++;
                }
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"EXP") == 0){
                    j = 0;
                    tab[x].lexem = FONCTION;
                    tab[x].valeur.fonction = EXP;
                    chaine_trouvee++;
                    x++;
                }
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"ENTIER") == 0){
                    j = 0;
                    tab[x].lexem = FONCTION;
                    tab[x].valeur.fonction = ENTIER;
                    chaine_trouvee++;
                    x++;
                }
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"VAL_NE") == 0){
                    j = 0;
                    tab[x].lexem = FONCTION;
                    tab[x].valeur.fonction = VAL_NEG;
                    chaine_trouvee++;
                    x++;
                }
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"SINC") == 0){
                    j = 0;
                    tab[x].lexem = FONCTION;
                    tab[x].valeur.fonction = SINC;
                    chaine_trouvee++;
                    x++;
                }

        }

        //On remplit notre variable reel qui va contenir une chaine de notre valeur
        //Si la chaine est entre 9 et 0 ou �gal � .
        if( ( (int)str[i] >=
         48 && (int)str[i] <= 57 ) || (int)str[i] == 46 ) {
    
            str_reel[k] = str[i];
            k = k + 1;
            str_reel[k] = '\0';
            mon_reel = 1;
        }
        //Si on a un reel de minimum 1 caract�re et que le carac suivant n'est plus un ENTIER ou un point...
        //on remplit notre typejeton
        if(mon_reel == 1 && 
        ( (int)str[i+1] < 48 || (int)str[i+1] > 57 ) && (int)str[i+1] != 46 ) {
    
            mon_reel = 0;
            tab[x].lexem = REEL;
            tab[x].valeur.reel = atof(str_reel);
            x++;
            k = 0;
        }

        i++;
    }

    //Ajout du FIN a notre tab typejeton a la fin du parcours de la chaine
    tab[x].lexem = FIN;

    i = 0;
    while(tab[i].lexem != FIN){
        // s'il y a bien deux op�randes autour d'un op�rateur
        if(tab[i].lexem == OPERATEUR && tab[i].valeur.operateur != MOINS && (tab[i+1].lexem != FONCTION && tab[i+1].lexem != REEL && tab[i+1].lexem != VARIABLE || tab[i-1].lexem != PAR_FERM && tab[i-1].lexem != REEL && tab[i-1].lexem != VARIABLE)) {
            valeur_retour = OPERATEUR_ERROR;
        }
        // s'il n'y a pas deux variables a la suite
        if(tab[i].lexem == VARIABLE && tab[i+1].lexem == VARIABLE) {
            valeur_retour = VARIABLE_ERROR;
        }
        i++;
    }
    //S'il n'y a pas un nombre de paire de paranth�ses, PARA ERROR
    if((compteur_para % 2) != 0) {
        valeur_retour = PARA_ERROR;
    }
    //S'il y a une erreur de syntaxe dans la fonction entr�, on retourne FONC_INCONNUE
    if(strlen(str_fonction) > 1 && chaine_trouvee == 0) {
        valeur_retour = FONC_INCONNUE;
    }
    /*
    //Sinon, on affiche nos donn�es
    else if(valeur_retour == RAS) {
        i = 0;
        //Affichage des donn�es par num�ro de la valeur (position dans la structure)
        while(tab[i].lexem != FIN){
            if(tab[i].lexem == OPERATEUR) {
                printf("OPERATEUR position : %d \n", tab[i].valeur.operateur);
            }
            else if(tab[i].lexem == FONCTION) {
                printf("FONCTION position : %d \n", tab[i].valeur.fonction);
            }
            else if(tab[i].lexem == REEL) {
                printf("r�el : %f \n",tab[i].valeur.reel);
            }
            else{
                printf("lexem position : %d \n", tab[i].lexem);
            }
            i++;
        }
        if(tab[i].lexem == FIN) {
            printf("FIN\n");
        }
    }
*/
    return valeur_retour;
}


void affichage_tableau_lexical(typejeton t[]) {

    int i = 0;
    while(t[i].lexem != FIN){
        if(t[i].lexem == OPERATEUR) {
            printf("operateur position : %d \n", t[i].valeur.operateur);
        } 
        else if(t[i].lexem == FONCTION) {
            printf("fonction position : %d \n", t[i].valeur.fonction);
        } 
        else if(t[i].lexem == REEL) {
            printf("réel : %f \n",t[i].valeur.reel);
        } 
        else{
            printf("lexem position : %d \n", t[i].lexem);
        }
        i++;  
    }
    if(t[i].lexem == FIN) {
        printf("FIN\n");
    }
    
}
#include "lexical.h"

typeerreur lexical(char str[], typejeton t[]){

    //Déclarations et initialisation des variables
    typeerreur valeur_retour;
    valeur_retour = RAS;
    int i = 0;
    int j = 0;
    int k = 0;
    int x = 0;
    char str_fonction[10];
    char str_reel[5];
    int chaine_trouvee = 0;
    int mon_reel = 0;            
    char monZero[1];
    int compteur_para = 0;

    printf("str entrée : %s \n\n",str); 

    //Parcours de la chaine de caractère qu'on reçoit
    while(str[i] != '\0'){

        switch(str[i]) {
            //Vérification des caractères que l'on reçoit
            case '(' :
                t[x].lexem = PAR_OUV;
                x++;
                compteur_para++;
                break;
            case ')' :
                t[x].lexem = PAR_FERM;
                x++;
                compteur_para++;
                break;
            case '+' :
                t[x].lexem = OPERATEUR;
                t[x].valeur.operateur = PLUS;
                x++;
                break;
            case '-' :
                t[x].lexem = OPERATEUR;
                t[x].valeur.operateur = MOINS;
                x++;
                break;
            case '*' :
                t[x].lexem = OPERATEUR;
                t[x].valeur.operateur = FOIS;
                x++;
                break;
            case '/' :
                t[x].lexem = OPERATEUR;
                t[x].valeur.operateur = DIV;
                x++;
                break;
            case '^' :
                t[x].lexem = OPERATEUR;
                t[x].valeur.operateur = PUIS;
                x++;
                break;
            case 'x' :
                t[x].lexem = VARIABLE;
                x++;
                break;
            
            //On test la FONCTION
            
            default :
                //Si la chaine est entre A et Z ou a et z ou _
                if((( ((int)str[i] >= 65) && ((int)str[i] <= 90)) || ( ((int)str[i] >= 97) && ((int)str[i] <= 122)) ) || ((int)str[i] == 95) ) {
                    str_fonction[j] = toupper(str[i]);
                    j++;
                    str_fonction[j] = '\0';
                }
                if(chaine_trouvee == 0 && strcmp(str_fonction,"ABS") == 0){
                    j = 0;
                    t[x].lexem = FONCTION;
                    t[x].valeur.fonction = ABS;
                    chaine_trouvee = 1;
                    x++;
                } 
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"SIN") == 0){
                    j = 0;
                    t[x].lexem = FONCTION;
                    t[x].valeur.fonction = SIN;
                    chaine_trouvee = 1;
                    x++;
                } 
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"SQRT") == 0){
                    j = 0;
                    t[x].lexem = FONCTION;
                    t[x].valeur.fonction = SQRT;
                    chaine_trouvee = 1;
                    x++;
                } 
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"LOG") == 0){
                    j = 0;
                    t[x].lexem = FONCTION;
                    t[x].valeur.fonction = LOG;
                    chaine_trouvee = 1;
                    x++;
                } 
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"COS") == 0){
                    j = 0;
                    t[x].lexem = FONCTION;
                    t[x].valeur.fonction = COS;
                    chaine_trouvee = 1;
                    x++;
                } 
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"TAN") == 0){
                    j = 0;
                    t[x].lexem = FONCTION;
                    t[x].valeur.fonction = TAN;
                    chaine_trouvee = 1;
                    x++;
                } 
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"EXP") == 0){
                    j = 0;
                    t[x].lexem = FONCTION;
                    t[x].valeur.fonction = EXP;
                    chaine_trouvee = 1;
                    x++;
                } 
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"ENTIER") == 0){
                    j = 0;
                    t[x].lexem = FONCTION;
                    t[x].valeur.fonction = ENTIER;
                    chaine_trouvee = 1;
                    x++;
                } 
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"VAL_NE") == 0){
                    j = 0;
                    t[x].lexem = FONCTION;
                    t[x].valeur.fonction = VAL_NEG;
                    chaine_trouvee = 1;
                    x++;
                } 
                else if(chaine_trouvee == 0 && strcmp(str_fonction,"SINC") == 0){
                    j = 0;
                    t[x].lexem = FONCTION;
                    t[x].valeur.fonction = SINC;
                    chaine_trouvee = 1;
                    x++;
                } 
                
        }

        //On remplit notre variable reel qui va contenir une chaine de notre valeur
        //Si la chaine est entre 9 et 0 ou égal à .
        if( ( (int)str[i] >= 48 && (int)str[i] <= 57 ) || (int)str[i] == 46 ) {
            str_reel[k] = str[i];
            k = k + 1;
            str_reel[k] = '\0';
            mon_reel = 1;
        }
        //Si on a un reel de minimum 1 caractère et que le carac suivant n'est plus un entier ou un point...
        //on remplit notre typejeton
        if(mon_reel == 1 && ( (int)str[i+1] < 48 || (int)str[i+1] > 57 ) && (int)str[i+1] != 46 ) {
            mon_reel = 0;
            t[x].lexem = REEL;
            t[x].valeur.reel = atof(str_reel);
            x++;
            k = 0;
        }

        i++;
    }

    //Ajout du FIN a notre tab typejeton a la fin du parcours de la chaine
    t[x].lexem = FIN;

    i = 0;
    while(t[i].lexem != FIN){
        //Test s'il y a bien deux opérandes autour d'un opérateur
        if(t[i].lexem == OPERATEUR && t[i].valeur.operateur != MOINS && (t[i+1].lexem != REEL && t[i+1].lexem != VARIABLE || t[i-1].lexem != REEL && t[i-1].lexem != VARIABLE)) {
            valeur_retour = OPERATEUR_ERROR;
        } 
        //Test s'il n'y a pas deux variables a la suite
        if(t[i].lexem == VARIABLE && t[i+1].lexem == VARIABLE) {
            valeur_retour = VARIABLE_ERROR;
        }
        i++;  
    }
    //S'il n'y a pas un nombre de paire de paranthèses, PARA ERROR
    if((compteur_para % 2) != 0) {
        valeur_retour = PARA_ERROR;
    }
    //S'il y a une erreur de syntaxe dans la fonction entré, on retourne FONC_INCONNUE
    else if(strlen(str_fonction) > 1 && chaine_trouvee == 0) {
        valeur_retour = FONC_INCONNUE;
    }
    //Sinon, on affiche nos données 
    else if(valeur_retour == RAS) {
        i = 0;
        //Affichage des données par numéro de la valeur (position dans la structure)
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

    return valeur_retour;
}
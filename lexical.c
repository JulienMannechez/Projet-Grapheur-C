#include "lexical.h"

int lexical(char str[], typejeton t[]){

    int valeur_retour = 1;

    //Parcours de la chaine de caractère qu'on reçoit
    int i = 0;
    int j = 0;
    int k = 0;
    char str_fonction[10];
    char str_reel[5];
    while(str[i] != '\0'){
        switch(str[i]) {
            //Vérification des caractères que l'on reçoit
            case '(' :
                t[i].lexem = PAR_OUV;
            break;
            case ')' :
                t[i].lexem = PAR_FERM;
            break;
            case '+' :
                t[i].lexem = OPERATEUR;
                t[i].valeur.operateur = PLUS;
            case '-' :
                t[i].lexem = OPERATEUR;
                t[i].valeur.operateur = MOINS;
            break;
            case '*' :
                t[i].lexem = OPERATEUR;
                t[i].valeur.operateur = FOIS;
            break;
            case '/' :
                t[i].lexem = OPERATEUR;
                t[i].valeur.operateur = DIV;
            break;
            case '^' :
                t[i].lexem = OPERATEUR;
                t[i].valeur.operateur = PUIS;
            break;
            break;
            case 'x' :
                t[i].lexem = VARIABLE;
            break;

            //Ajouter code ERREUR
                //Si il y a plusieurs operateur sans opérandes
                //Si fonction non trouvée
            
            //retrouver la FONCTION
            
            default :
                if((( ((int)str[i] >= 65) && ((int)str[i] <= 90)) || ( ((int)str[i] >= 97) && ((int)str[i] <= 122)) ) || (strcmp(str[i],'_') == 0) ) {
                    //strcpy(ma_fonction, str[i]);
                    str_fonction[j] = (str[i]);
                    toupper(str_fonction[i]);
                    j = j + 1;
                }
                if(strcmp(str_fonction,'ABS') == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = ABS;
                } 
                if(strcmp(str_fonction,'SIN') == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = SIN;
                } 
                if(strcmp(str_fonction,'SQRT') == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = SQRT;
                } 
                if(strcmp(str_fonction,'LOG') == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = LOG;
                } 
                if(strcmp(str_fonction,'COS') == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = COS;
                } 
                if(strcmp(str_fonction,'TAN') == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = TAN;
                } 
                if(strcmp(str_fonction,'EXP') == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = EXP;
                } 
                if(strcmp(str_fonction,'ENTIER') == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = ENTIER;
                } 
                if(strcmp(str_fonction,'VAL_NEG') == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = VAL_NEG;
                } 
                if(strcmp(str_fonction,'SINC') == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = SINC;
                } 

        }

        //On remplit notre variable reel qui va contenir une chaine de notre valeur
        if ( str[i] < '9' && str[i] > '0' || str[i] == '.' ){
            str_reel[k] = str[i];
            k = k + 1;
        }
        //On peut donc envoyer ensuite notre chaine avec le réel complet
        t[i].lexem = REEL;
        t[i].valeur.reel = atof(str_reel); 

    }

    t[i+1].lexem = FIN;


    return valeur_retour;
}
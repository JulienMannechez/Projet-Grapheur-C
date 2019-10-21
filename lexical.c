#include "lexical.h"

int lexical(char str[], typejeton t[]){

    //initialisation des variables
    int valeur_retour = 1;
    int i = 0;
    int j = 0;
    int k = 0;
    char str_fonction[10];
    char str_reel[5];

    printf("str : %s \n",str);

    //Parcours de la chaine de caractère qu'on reçoit
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
                break;
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
            case 'x' :
                t[i].lexem = VARIABLE;
                break;

            //Ajouter code ERREUR
                //Si il y a plusieurs operateur sans opérandes
                //Si fonction non trouvée
            
            //retrouver la FONCTION
            
            default :
                if((( ((int)str[i] >= 65) && ((int)str[i] <= 90)) || ( ((int)str[i] >= 97) && ((int)str[i] <= 122)) ) || ((int)str[i] == 95) ) {
                    //strcpy(ma_fonction, str[i]);
                    str_fonction[j] = toupper(str[i]);
                    j++;
                    str_fonction[j] = '\0';
                }
                
                if(strcmp(str_fonction,"ABS") == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = ABS;
                } 
                else if(strcmp(str_fonction,"SIN") == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = SIN;
                } 
                else if(strcmp(str_fonction,"SQRT") == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = SQRT;
                } 
                else if(strcmp(str_fonction,"LOG") == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = LOG;
                } 
                else if(strcmp(str_fonction,"COS") == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = COS;
                } 
                else if(strcmp(str_fonction,"TAN") == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = TAN;
                } 
                else if(strcmp(str_fonction,"EXP") == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = EXP;
                } 
                else if(strcmp(str_fonction,"ENTIER") == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = ENTIER;
                } 
                else if(strcmp(str_fonction,"VAL_NE") == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = VAL_NEG;
                } 
                else if(strcmp(str_fonction,"SINC") == 0){
                    t[i].lexem = FONCTION;
                    t[i].valeur.fonction = SINC;
                } 

        }

        //On remplit notre variable reel qui va contenir une chaine de notre valeur
        /*if ( str[i] < '9' && str[i] > '0' || str[i] == "." ){
            str_reel[k] = str[i];
            k = k + 1;
        }
        //On peut donc envoyer ensuite notre chaine avec le réel complet
        t[i].lexem = REEL;
        t[i].valeur.reel = atof(str_reel); */
        i++;
    }

    t[i+1].lexem = FIN;

    i = 0;
    while(t[i].lexem != FIN){
        if(t[i].lexem == OPERATEUR) {
            printf("operateur %d -> lexem position : %d \n",t[i].lexem ,t[i].valeur.operateur);
        } 
        else if(t[i].lexem == FONCTION) {
            printf("fonction %d -> lexem position : %d \n",t[i].lexem, t[i].valeur.fonction);
        } 
        else {
            printf("lexem position : %d \n", t[i].lexem);
        }
        i++;  
    }
 
    return valeur_retour;
}
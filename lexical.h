#ifndef LEXICAL_FILE
#define LEXICAL_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jeton.h"

typeerreur lexical(char str[], typejeton* tab);

void affichage_tableau_lexical(typejeton t[]);

#endif

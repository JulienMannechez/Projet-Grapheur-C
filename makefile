#à faire de sorte à ce que toutes les dépendances s'installent seules et expliquer aussi en toute lettres comment faire si le makefile ne marche pas

# Projet Grapheur sans partie 4
#grapheur : lexical.c syntaxique.c evaluateur.c main.c 
#	gcc -o grapheur lexical.c syntaxique.c evaluateur.c main.c -lm

# Projet Grapheur global avec partie 4
grapheur : lexical.c syntaxique.c evaluateur.c grapheur.c main.c 
	gcc -o grapheur lexical.c syntaxique.c evaluateur.c grapheur.c main.c -lm -lglut -lGLU -lGL

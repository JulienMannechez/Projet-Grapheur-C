#à faire de sorte à ce que toutes les dépendances s'installent seules et expliquer aussi en toute lettres comment faire si le makefile ne marche pas
grapheur : lexical.c syntaxique.c evaluateur.c main.c 
	gcc -o grapheur lexical.c syntaxique.c evaluateur.c grapheur.c main.c -lm -xc++ -lstdc++ -shared-libgcc -lGL -lGLEW -lglut -lGLU

#grapheur : lexical.c syntaxique.c evaluateur.c grapheur.c main.c 
#	gcc -o grapheur lexical.c syntaxique.c evaluateur.c grapheur.c main.c -lm

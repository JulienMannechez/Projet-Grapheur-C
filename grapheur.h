#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "jeton.h"

/**
* @file grapheur.h
*
* Il contient la déclaration des procèdures disponibles pour ouvrir une fenêtre
* et y dessiner des figures. Les coordonnées des points dans la fenêtre sont
* définies sur l'intervalle [-1;1], (-1,-1) étant le coin inférieur gauche de
* la fenêtre et (1,1) le coin supérieur droit.
* 
*/

/**
* InitGraph
*
* Procédure d'initialisation de la fenêtre et de l'environnement OpenGL 
*
* @param ac nombre de paramètres
* @param av tableau contenant les paramètres 
* @param WinName le nom (titre) de la fenêtre d'affichage
* @param w la largeur de la fenêtre
* @param h la hauteur de la fenêtre
* @param Draw fonction qui affiche le graphique dans la fenêtre
* @param Key fonction appelée lors de l'appui sur une touche c du clavier,
*	 c désignant le code ascii de la touche
*
*/
void InitGraph(int ac, char *av[], const char *WinName,const int w, const int h, void (*Draw)(void),void (*Key)(int c));
/**
* line
*
* Cette procédure permet de tracer une ligne entre deux points (x0, y0) et
* (x1,y1) 
*
* @param x0 abscisse du 1er point
* @param y0 ordonnée du 1er point
* @param x0 abscisse du 2ème point
* @param y0 ordonnée du 2ème point
*
*/
void line(const float x0, const float y0, const float x1, const float y1);

/**
* setcolor
*
* Cette procédure permet de définir la couleur utilisée pour tracer les lignes.
* La couleur par les valeurs des composantes rouge, verte et bleue.
*
* @param r composante rouge
* @param v composante vertee
* @param b composante bleue
*
*/
void setcolor(const float r, const float v, const float b);

/**
* beginlines
*
* Cette procédure permet de commencer le tracé d'une ligne brisée composée
* de n segments de droite définis par (n+1) points.
*
* @param x0 l'abscisse du premier point de la ligne brisée
* @param y0 l'ordonnée du premier point de la ligne brisée
*
*/
void beginlines(const float x0, const float y0);

/**
* lineto
*
* Cette procédure permet d'ajouter un point à la ligne brisée en cours. Le
* dernier point défini et le nouveau point delimitent un nouveau segment de
* droite dans la ligne brisée.
*
* @param x l'abscisse du nouveau point de la ligne brisée
* @param y l'ordonnée du nouveau point de la ligne brisée
*
*/
void lineto(const float x, const float y);

/**
* finishlines
*
* Cette procédure permet de terminer le tracé de la ligne brisée en cours.
*
*/
void finishlines(void);
/**
* bar
*
* Cette procédure permet de tracer un rectangle défini par son coin supérieur
* gauche et son coin inférieur droit.
*
* @param x0 abscisse du coin supérieur gauche du rectangle
* @param y0 ordonnée du coin argvst float y0, const float x1, const float y1);

/**
* outtextxy
*
* Cette procèdure permet d'écrire une chaîne de caractères dans une zone de
* texte définie par les coordonnées x et y
*
* @param x abscisse de l'origine (coin gauche supérieur) de la zone de texte
* @param y ordonnée de l'origine (coin gauche supérieur) de la zone de texte
* @param s chaîne de caractères contenant le texte à afficher
*
*/
void outtextxy(const float x, const float y, const char *s);


//déclaration des variables globales
extern Couple tab_valeur[2000];
extern float offset;
extern float scale;
extern float Translate_x;
extern float Translate_y;
//en-tête des fonctions
void Dessin();
void Cle(int c);

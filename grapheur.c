#include "grapheur.h"

/**
* @file grapheur.c
* Traçage,zoom et position de la courbe
*/

static int WindowNumber;
static int Width, Height;
static void (*AppliDraw)();
static void (*AppliKey)(int);

/**
* GlutReshape
*
* Cette procèdure permet de gérer la taille de la fenêtre quand redimensionnée
*
* @parma w largeur de la fenetre gl
* @parma h hauteur de la fenetre gl
*/

static void GlutReshape(const int w, const int h)
{
  Width = w;
  Height = h;
  glViewport(0, 0, Width, Height);
}

static void GlutIdle(void)
{
  //  glutPostRedisplay();
}

static void GlutKey(const unsigned char c, const int x, const int y)
{
  switch (c)
  {
  default:
    if (AppliKey)
      (*AppliKey)(c);
    break;
  }
  glutPostRedisplay();
}

static void Begin2DDisplay(void)
{
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(-1, 1, -1.0, 1.0, 0.5, 1.5);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(0.0F, 0.0F, -1.0F);
}

static void End2DDisplay(void)
{
  /* Fin du tracé, retour aux paramètres normaux */
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
}

static void InitDisplay(void)
{
  glDisable(GL_LIGHTING);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);
  glClearColor(0.0F, 0.0F, 0.0F, 0.0F);
}

static void GlutDraw(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  Begin2DDisplay();
  if (AppliDraw)
    (*AppliDraw)();
  End2DDisplay();
  glutSwapBuffers();
}

/**
* InitGraph
*
* Procédure d'initialisation de la fenêtre et de l'environement OpenGL 
* L'initialisation de GLUT se trouve dans la procédure
* principale, elle nécessite l'emploi des arguments de
* la ligne de commande 
*
* @parma ac
* @parma av[]
* @parma WinName definit le nom (titre) de la fenêtre d'affichage
* @parma w définit la largeur de la fenêtre
* @parma h definit la hauteur de la fenêtre
* @parma Draw définit une méthode de traçage 
* @parma Key définit une méthode permettant la détection des touches du clavier 
* @parma c entier désignant le code ascii d'une touche
*
*/
void InitGraph(int ac, char *av[],const char *WinName, const int w, const int h, void (*Draw)(void), void (*Key)(int))
{
  glutInit(&ac, av);
  Width = w;
  Height = h;
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(Width, Height);
  WindowNumber = glutCreateWindow(WinName);
  glutReshapeFunc(GlutReshape); /* fonction appelée quand la fenêtre est redimensionnée */
  glutIdleFunc(GlutIdle);       /* fonction appelée en boucle */
  AppliKey = Key;
  glutKeyboardFunc(GlutKey);
  AppliDraw = Draw;
  glutDisplayFunc(GlutDraw);
  InitDisplay();
  glutMainLoop();
}

/**
* setcolor
*
* Cette procédure permet de définir une couleur par ces trois composantes   
*
* @parma r composante du plan rouge
* @parma v composante du plan vert
* @parma b composante du plan bleu
*
*/
void setcolor(const float r, const float v, const float b)
{
  glColor3f(r, v, b);
}

/**
* line
*
* Cette procédure permet de tracer une ligne entre deux points (x0, y0) et (x1,y1) 
*
* @parma x0 abscisse 1er point
* @parma y0 ordonnée 1er point
* @parma x0 abscisse 2ème point
* @parma y0 ordonnée 2ème point
*
*/
void line(const float x0, const float y0, const float x1, const float y1)
{
  glBegin(GL_LINES);
  glVertex2f(x0, y0);
  glVertex2f(x1, y1);
  glEnd();
}

/**
* beginlines
*
* @parma x0
* @parma y0
*
*/
void beginlines(const float x0, const float y0)
{
  glBegin(GL_LINE_STRIP);
  glVertex2f(x0, y0);
}

void lineto(const float x, const float y)
{
  glVertex2f(x, y);
}

void finishlines(void)
{
  glEnd();
}

void bar(const float x0, const float y0, const float x1, const float y1)
{
  glBegin(GL_QUADS);
  glVertex2f(x0, y0);
  glVertex2f(x0, y1);
  glVertex2f(x1, y1);
  glVertex2f(x1, y0);
  glEnd();
}

/**
* outtextxy
*
* Cette procédure permet d'écrire une chaîne de caractère dans une zone de texte d�finie par les coordonnées x et y
*
* @parma x abscisse du point (coint gauche supérieur) de la zone de texte 
* @parma y ordonnée du point (coint gauche supérieur) de la zone de texte 
* @parma s tableau de caractères 
*
*/
void outtextxy(const float x, const float y, const char *str)
{
  const char *s = str;

  glRasterPos2f(x, y);
  while (*s != '\0')
  {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *s++);
  }
}

void Cle(int c)//Fonction qui gère les entrées clavier (réglage zoom, offset et position)
{
  switch (c)
  {
  //réglage de l'offest
  case 'q':
    offset -= 0.001;
    break;
  case 'd':
    offset += 0.001;
    break;
  //réglage du zoom
  case 'z':
    scale *= 1.01;
    break;
  case 's':
    scale /= 1.01;
    break;
  //réglage de la position axe horizontal
  case 'j':
    Translate_x += 0.3;
    break;
  case 'l':
    Translate_x -= 0.3;
    break;
  //réglage de la position axe vertical
  case 'k':
    Translate_y += 0.3;
    break;
  case 'i':
    Translate_y -= 0.3;
    break;
  }
}

void Dessin()//Fonction qui dessine la courbe
{

  glPushMatrix(); /* GL_MODELVIEW is default */
  //réglage du zoom et de l'offset
  glScalef(scale, offset, 1.0);
  //réglage de la position
  glTranslatef(-Translate_x, -Translate_y, 0.0);
  glColor3f(0.0, 0.0, 0.0); //Colorise les axes en noir
  glClearColor(1.0, 1.0, 1.0, 0.0); //Colorise le fond en blanc
  glClear(GL_COLOR_BUFFER_BIT);
  //trace la courbe
  
  /*Ajout Julien T pour tracer les axes X et Y */
  glBegin(GL_LINES);//permet de commencer à tracer des lignes
          /* Axe des X */
          glVertex2d(-1000,0);
          glVertex2d(1000,0);      
          /* Axe des Y */
          glVertex2d(0,-1000);
          glVertex2d(0,1000);
  glEnd();
  /*Ajout Julien T pour tracer les axes X et Y */


  glBegin(GL_LINE_STRIP);
  glColor3f(1.0, 0.0, 0.0); //Colorise la courbe en rouge
  //parcours des couples x,y
  for (int i = 0; i < (sizeof(tab_valeur) / 8)-1; i++)
  {
    //relie entre eux les differents points de la courbe
    line(tab_valeur[i].x, tab_valeur[i].y, tab_valeur[i + 1].x, tab_valeur[i + 1].y);
  }
  glEnd(); 
  // Fin du tracé*/
}
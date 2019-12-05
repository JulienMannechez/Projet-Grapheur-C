#include "grapheur.h"

/**
* @file Graph.cpp
*
* @brief pr�sente les quelques fonctionnalit�s n�cessaires dans le cadre de ce projet
* Il contient la d�finition des m�thodes utilis�es
*
*/

static int WindowNumber;
static int Width, Height;
static void (*AppliDraw)();
static void (*AppliKey)(int);

/**
* GlutReshape
*
* Cette proc�dure permet de gerer la taille de la fenetre quand (redimensionn�e)
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
  /* Fin du trace, retour au parametres normaux */
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
* Procedure d'initialisation de la fenetre et de l'environement OpenGL 
* L'initialisation de GLUT se trouve dans la procedure
* principale, elle necessite l'emploie des argument de
* la ligne de commande 
*
* @parma ac
* @parma av[]
* @parma WinName definit le nom (titre) de la fentre d'affichage
* @parma w definit la largeur de la fenetre
* @parma h definit la hauteur de la fenetre
* @parma Draw d�finit une m�thode de tra�age 
* @parma Key d�finit une m�thode permettant la d�tection des touche du clavier 
* @parma c entier designant le code ascii d'une touche
*
*/
void InitGraph(int ac, char *av[],const char *WinName, const int w, const int h, void (*Draw)(Couple *tab), void (*Key)(int))
{
  glutInit(&ac, av);
  Width = w;
  Height = h;
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(Width, Height);
  WindowNumber = glutCreateWindow(WinName);
  glutReshapeFunc(GlutReshape); /* fonction appelee qd fenetre redimensionnee */
  glutIdleFunc(GlutIdle);       /* fonction appelee en boucle */
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
* Cette proc�dure permet de definire une couleur par ces trois composantes   
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
* Cette proc�dure permet de tracher une ligne entre deux points (x0, y0) et (x1,y1) 
*
* @parma x0 abscisse 1er point
* @parma y0 ordonn�e 1er point
* @parma x0 abscisse 2eme point
* @parma y0 ordonn�e 2eme point
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
* Cette proc�dure permet 
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
* Cette proc�dure permet d'ecrit une chaine de charact�re s dans une zone de texte d�finie par les coordonn�es x et y
*
* @parma x abscisse du point (coint gauche superieur) de la zone de texte 
* @parma y ordonn�e du point (coint gauche superieur) de la zone de texte 
* @parma s tableau de charct�res 
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

float offset_x /*= 1.0 / (Ymax - Ymin)*/;
float scale_x /*= 1.0 / (Xmax - Xmin)*/;
float Translate_x /*= -Xmin*/;
float Translate_y /*= -Ymin*/;

void Cle(int c)
{
  switch (c)
  {
  case 'q':
    offset_x -= 0.1;
    break;
  case 'd':
    offset_x += 0.1;
    break;
  case 'z':
    scale_x *= 1.5;
    break;
  case 's':
    scale_x /= 1.5;
    break;
  /*case 'r':
    offset_x = 1.0 / (Ymax - Ymin);
    scale_x = 1.0 / (Xmax - Xmin);
    break;*/
  case 'j':
    Translate_x += 0.1;
    break;
  case 'l':
    Translate_x -= 0.1;
    break;
  case 'i':
    Translate_y += 0.1;
    break;
  case 'k':
    Translate_y -= 0.1;
    break;
  }
}

void Dessin()
{
  glPushMatrix(); /* GL_MODELVIEW is default */
  glScalef(scale_x, offset_x, 1.0);
  glTranslatef(-Translate_x, -Translate_y, 0.0);
  glColor3f(1.0, 0.0, 0.0);
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_STRIP);
  for (int i = 0; i < sizeof(tab) / 8 - 1; i++)
  {
    line(tab[i].x, tab[i].y, tab[i + 1].x, tab[i + 1].y);
  }
  /*setcolor(1.0F,1.0F,1.0F);
	line(-1.0,-1.0,1.0,1.0);
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
	setcolor(1.0F,1.0F,0.0F);
	outtextxy(0.0,0.0,"Text");
  if (bascule) {
		setcolor(1.0F,0.0F,0.0F);
		bar(-0.5F,-0.5F,0.5F,0.5F);
	}
	setcolor(1.0F,1.0F,1.0F);*/

  /*//Cadre
	line(-0.90,-0.90,0.90,-0.90);
	//setcolor(1.0F,1.0F,1.0F);
	line(-0.90,-0.90,-0.90,0.90);
	line(-0.90,0.90,0.90,0.90);
	line(0.90,0.90,0.90,-0.90);

	//Croix centrale
	line(0.0,0.90,0.0,-0.90);
	line(0.90,0.0,-0.90,0.0);*/

  /*glBegin(GL_LINES);      // On trace les 3 axes dans des couleurs différentes
 
        glColor3ub(255, 0, 0);    // Axe X en rouge
        glVertex3i(0,0, 0);
        glVertex3i(1,0, 0);
 
        glColor3ub(0, 255, 0);    // Axe Y en vert
        glVertex3i(0, 0, 0);
        glVertex3i(0, 1, 0);
  glEnd(); // Fin du tracé*/
}

/*void Graphe(couple tab[],float minX, float minY,float maxX,float maxY) {
	boucle i=1{
			line(tab[i].x,tab[i].y,$j,tab[i+1].x,tab[i+1].y);
			i+1;
	}
}*/

#include "grapheur.h"

Couple tab[2000];

int main(int argc, char *argv[])
{
    // On recois tableau [j].x et tableau[j].y
    Couple tab[2000];
    float j = 0;
    int i = 0;
    for (i = 0; i < sizeof(tab) / 8; i++)
    {
        tab[i].x = j;
        tab[i].y = cos(j);
        j += 0.1;
    }
	int Xmin = 0;
	int Xmax = (sizeof(tab) / 8) * 0.1;
	int Ymin = 0;
	int Ymax = 1;
	offset_x= 1.0 / (Ymax - Ymin);
	scale_x= 1.0 / (Xmax - Xmin);
	Translate_x= -Xmin;
	Translate_y= -Ymin;
    InitGraph(argc, argv, "Grapheur", 1280, 720, Dessin(tab), Cle, tab);
    return 0;
}

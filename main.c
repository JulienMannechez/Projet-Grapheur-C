#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "entete.h"
#include "Graph.h"
#include "Graph.cpp"

int bascule=0;

void laCle(int c) {
	switch(c) {
		case 'a':
			bascule^=1;
			break;
	}
}

void leTrace(void) {
	//test
	//setcolor(1.0F,1.0F,1.0F);
	//line(-1.0,-1.0,1.0,1.0);
	//if (bascule) {
	//	setcolor(1.0F,0.0F,0.0F);
	//	bar(-0.5F,-0.5F,0.5F,0.5F);
	//}
	//setcolor(1.0F,1.0F,0.0F);
	//outtextxy(0.0,0.0,"Pistache Team TM");

	//setcolor(1.0F,1.0F,1.0F);

	//Cadre
	line(-0.90,-0.90,0.90,-0.90);
	//setcolor(1.0F,1.0F,1.0F);
	line(-0.90,-0.90,-0.90,0.90);
	line(-0.90,0.90,0.90,0.90);
	line(0.90,0.90,0.90,-0.90);

	//Croix centrale
	line(0.0,0.90,0.0,-0.90);
	line(0.90,0.0,-0.90,0.0);

}

int main(int ac,char *av[]) {
	// On recois tableau [j].x et tableau[j].y
	
	InitGraph(ac,av,"Grapheur",1280,720,leTrace,laCle);
	return 0;
}

void Graphe(couple tab[],float minX, float minY,float maxX,float maxY) {
	boucle i=1{
			line(tab[i].x,tab[i]y,$j,tab[i+1].x,tab[i+1].y);
			i+1;
	}
}
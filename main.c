#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "entete.h"
#include "Graph.h"

int bascule=0;

void laCle(int c) {
	switch(c) {
		case 'a':
			bascule^=1;
			break;
	}
}

void leTrace(void) {
	setcolor(1.0F,1.0F,1.0F);
	line(-1.0,-1.0,1.0,1.0);
	if (bascule) {
		setcolor(1.0F,0.0F,0.0F);
		bar(-0.5F,-0.5F,0.5F,0.5F);
	}
	setcolor(1.0F,1.0F,0.0F);
	outtextxy(0.0,0.0,"Pistache Team TM");
}

int main(int ac,char *av[]) {
	// On recois tableau [j].x et tableau[j].y
	
	InitGraph(ac,av,"Grapheur",1280,720,leTrace,laCle);
	return 0;
}
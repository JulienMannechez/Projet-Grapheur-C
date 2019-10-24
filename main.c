#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>

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
	outtexty(0.0,0.0,"Pistache Team TM");
}

void main(int argc,char* argv) {
	// On recois tableau [j].x et tableau[j].y
	
	glutInit(ac,ac,"Grapheur",1280,720,leTrace,laCle);
}
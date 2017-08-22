

#include <math.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "const.h"
#include "types.h"


GLuint createPreyDL() {
	GLuint preyDL,loopDL;
	
	preyDL = glGenLists(1);
	loopDL = glGenLists(1);
	
	glNewList(preyDL,GL_COMPILE);
	drawPrey();
	glEndList();
	
	glNewList(loopDL,GL_COMPILE);
	for(int i = -3; i < 3; i++)
		for(int j=-3; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i*10.0,0,j * 10.0);
			glCallList(preyDL);
			glPopMatrix();
		}
	glEndList();
	
	return(loopDL);
}

void drawPrey() {
	
	glColor3f(1.0f, 1.0f, 1.0f);
	
	// Draw Body	
	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(0.75f,20,20);

}

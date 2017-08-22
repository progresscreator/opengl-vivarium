
#include <math.h>
#include <GLUT/glut.h>
#include <OpenGl/gl.h>
#include <OpenGL/glu.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcs.h"
#include "const.h"
#include "types.h"

void initializePredatorAnimations(){
	
	predatorObject = createPredatorObject();
	
	createPredator0();
	createPredator1();
	createPredator2();
	createPredator3();
	createPredator4();
	createPredator5();
	
}

predatorType* createPredatorObject(){
	

	predatorType *p;
	p = calloc(sizeof(predatorType),1);
	p->frameNumber = 0;
	p->currentAngle = 0;
	p->localAnimation = PRED1;
	p->fps = 0;
	
	p->predPositionX = 0;
	p->predPositionY = 0;
	p->predPositionZ = 0;

	return (p);
	
}

// Every 50 frames, updates local animaion
// of predator
void updateLocalPredatorAnimation(){
	
	int interval = 50;
	float spin = 0.025;
	float FPS = predatorObject->fps;
	
	if(FPS>800){
		interval = 50;
		spin = 0.025;
	}
	else if (FPS<=800 && FPS>300){
		interval = 35;
		spin = 0.075;
	}
	else if (FPS<=300){
		interval = 15;
		spin = 0.125;
	}
	
	glNewList(PREDOUT,GL_COMPILE);
	glPushMatrix();
	
	predatorObject->frameNumber++;
	predatorObject->currentAngle = predatorObject->currentAngle + spin;
	
	glRotatef(predatorObject->currentAngle, 0, 1, 0);
	
	if(predatorObject->frameNumber >= (interval*5))
		predatorObject->frameNumber = 0;

	if(predatorObject->frameNumber < (interval))
		glCallList(PRED1);
	if(predatorObject->frameNumber < (interval*2) && predatorObject->frameNumber >= (interval))
		glCallList(PRED2);
	if(predatorObject->frameNumber < (interval*3) && predatorObject->frameNumber >= (interval*2))
		glCallList(PRED3);
	if(predatorObject->frameNumber < (interval*4) && predatorObject->frameNumber >= (interval*3))
		glCallList(PRED4);
	if(predatorObject->frameNumber < (interval*5) && predatorObject->frameNumber >= (interval*4))
		glCallList(PRED5);
	
	
	
	glPopMatrix();
	glEndList();
	
	predatorObject->localAnimation = PREDOUT;
	
}

GLint createPredator2()
{
	
	glNewList(PRED2,GL_COMPILE);
	
	glPushMatrix();
	glCallList(PRED1);
	glPopMatrix();
	
	// Lazer Beam
	glPushMatrix();
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glColor4f(1.0f, 1.0f, 0, 1.0);
	glRotatef(90,1,0,0);
	glScalef(0.2, 0.2, 0.1);
	glTranslatef(0,0,5);
	glutSolidTorus(1, 3, 5, 50);
	glDisable(GL_BLEND);
	glPopMatrix();
	
	glEndList();
	
	return(PRED2);
}


GLint createPredator3()
{
	
	glNewList(PRED3,GL_COMPILE);
	
	glPushMatrix();
	glCallList(PRED1);
	glPopMatrix();
	
	// Lazer Beam
	glPushMatrix();
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glColor4f(1.0f, 1.0f, 0, 0.6);
	glRotatef(90,1,0,0);
	glScalef(0.2, 0.2, 0.1);
	glTranslatef(0,0,5);
	glutSolidTorus(1, 3, 5, 50);
	glDisable(GL_BLEND);
	glPopMatrix();
	
	
	// Lazer Beam
	glPushMatrix();
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glColor4f(1.0f, 1.0f, 0, 1.0);
	glRotatef(90,1,0,0);
	glScalef(0.2, 0.2, 0.1);
	glTranslatef(0,0,7);
	glutSolidTorus(1, 3, 5, 50);
	glDisable(GL_BLEND);
	glPopMatrix();
	
	glEndList();
	
	return(PRED3);
}

GLint createPredator4()
{
	
	glNewList(PRED4,GL_COMPILE);
	
	glPushMatrix();
	glCallList(PRED1);
	glPopMatrix();
	
	// Lazer Beam
	glPushMatrix();
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glColor4f(1.0f, 1.0f, 0, 0.0);
	glRotatef(90,1,0,0);
	glScalef(0.2, 0.2, 0.1);
	glTranslatef(0,0,5);
	glutSolidTorus(1, 3, 5, 50);
	glDisable(GL_BLEND);
	glPopMatrix();
	
	
	// Lazer Beam
	glPushMatrix();
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glColor4f(1.0f, 1.0f, 0, 0.6);
	glRotatef(90,1,0,0);
	glScalef(0.2, 0.2, 0.1);
	glTranslatef(0,0,7);
	glutSolidTorus(1, 3, 5, 50);
	glDisable(GL_BLEND);
	glPopMatrix();
	
	// Lazer Beam
	glPushMatrix();
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glColor4f(1.0f, 1.0f, 0, 1.0);
	glRotatef(90,1,0,0);
	glScalef(0.2, 0.2, 0.1);
	glTranslatef(0,0,9);
	glutSolidTorus(1, 3.5, 5, 50);
	glDisable(GL_BLEND);
	glPopMatrix();
	
	glEndList();
	
	return(PRED4);
}

GLint createPredator5()
{
	
	glNewList(PRED5,GL_COMPILE);
	
	glPushMatrix();
	glCallList(PRED1);
	glPopMatrix();
	
	// Lazer Beam
	glPushMatrix();
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glColor4f(1.0f, 1.0f, 0, 0.0);
	glRotatef(90,1,0,0);
	glScalef(0.2, 0.2, 0.1);
	glTranslatef(0,0,5);
	glutSolidTorus(1, 3, 5, 50);
	glDisable(GL_BLEND);
	glPopMatrix();
	
	
	// Lazer Beam
	glPushMatrix();
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glColor4f(1.0f, 1.0f, 0, 0.0);
	glRotatef(90,1,0,0);
	glScalef(0.2, 0.2, 0.1);
	glTranslatef(0,0,7);
	glutSolidTorus(1, 3, 5, 50);
	glDisable(GL_BLEND);
	glPopMatrix();
	
	// Lazer Beam
	glPushMatrix();
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glColor4f(1.0f, 1.0f, 0, 0.8);
	glRotatef(90,1,0,0);
	glScalef(0.2, 0.2, 0.1);
	glTranslatef(0,0,9);
	glutSolidTorus(1, 3.5, 5, 50);
	glDisable(GL_BLEND);
	glPopMatrix();
	
	// Lazer Beam
	glPushMatrix();
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glColor4f(1.0f, 1.0f, 0, 1.0);
	glRotatef(90,1,0,0);
	glScalef(0.2, 0.2, 0.1);
	glTranslatef(0,0,11);
	glutSolidTorus(1, 4, 5, 50);
	glDisable(GL_BLEND);
	glPopMatrix();
	
	glEndList();
	
	return(PRED5);
}

GLint createPredator1()
{
	
	glNewList(PRED1,GL_COMPILE);
	
	glPushMatrix();
	glCallList(PRED0);
	glPopMatrix();
	
	// Lazer Beam
	glPushMatrix();
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glColor4f(1.0f, 1.0f, 0, 0);
	glRotatef(90,1,0,0);
	glScalef(0.2, 0.2, 0.1);
	glTranslatef(0,0,-5);
	glutSolidTorus(1, 3, 5, 50);
	glDisable(GL_BLEND);
	glPopMatrix();
	
	glEndList();
	
	return(PRED1);

}
/* create the Predator geometry */
GLint createPredator0()
{
	
	glNewList(PRED0,GL_COMPILE);
	
	
	// Cockpit
	glPushMatrix();
	glColor3f(0.0,1,1.0);
	glScalef(0.5, 0.5, 0.5);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();
	
	// Red Hull
	glPushMatrix();
	glColor3f(1.0,0,0);
	glRotatef(90,1,0,0);
	glScalef(0.5, 0.5, 0.2);
	glutSolidTorus(1, 2, 5, 20);
	glPopMatrix();
	
	// Yellow Lazer
	glPushMatrix();
	glColor3f(1.0,1.0,0);
	glRotatef(90,1,0,0);
	glScalef(0.2, 0.2, 0.25);
	glTranslatef(0,0,1);
	glutSolidTorus(1, 2, 5, 20);
	glPopMatrix();
	
	// Shield Bulb
	glPushMatrix();
	glColor3f(0,1,0);
	glScalef(0.07, 0.07, 0.07);
	glTranslatef(19,1,0);
	glutSolidDodecahedron();
	glPopMatrix();
	
	// Shield Bulb
	glPushMatrix();
	glColor3f(0,1,0);
	glScalef(0.07, 0.07, 0.07);
	glTranslatef(-19,1,0);
	glutSolidDodecahedron();
	glPopMatrix();
	
	// Shield Bulb
	glPushMatrix();
	glColor3f(0,1,0);
	glScalef(0.07, 0.07, 0.07);
	glTranslatef(0,1,19);
	glutSolidDodecahedron();
	glPopMatrix();
	
	// Shield Bulb
	glPushMatrix();
	glColor3f(0,1,0);
	glScalef(0.07, 0.07, 0.07);
	glTranslatef(0,1,-19);
	glutSolidDodecahedron();
	glPopMatrix();
	
	
	glEndList();
	
	return(PRED0);
}

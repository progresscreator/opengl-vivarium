
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


void initializePreyAnimations(){
	
	preyObject = createPreyObject();
	
	createPrey1();
	createPrey2();
	createPrey3();
	createPrey4();
	createPrey5();
	createPrey6();
	
}

// Every 500 frames, updates local animations
// of each prey
void updateLocalPreyAnimations(){
	
	int interval = 50;
	float FPS = preyObject->fps;
	
	if(FPS>800)
		interval = 500;
	else if (FPS<=800 && FPS>300)
		interval = 250;
	else if (FPS<=300)
		interval = 100;
	
	int i;
	
	// Update frameNumber
	preyObject->frameNumber++;
	
	// Every 500 frames...
	if(preyObject->frameNumber % (interval) == 0)
	{
		// Reset frame counter
		preyObject->frameNumber = 1;
		
		// For every prey...
		for(i=0; i<MAXPREY; i++){
			
			// if prey is alive
			if(preyObject->isAlive[i]==1){
				
				// Get current animation step id
				int currentID = preyObject->localAnimation[i];
				
				// Increment steps accordingly
				if(currentID == PREY1)
					preyObject->localAnimation[i] = PREY2;
				
				if(currentID == PREY2)
					preyObject->localAnimation[i] = PREY3;
				
				if(currentID == PREY3)
					preyObject->localAnimation[i] = PREY4;
				
				if(currentID == PREY4)
					preyObject->localAnimation[i] = PREY5;
				
				if(currentID == PREY5)
					preyObject->localAnimation[i] = PREY6;
				
				if(currentID == PREY6)
					preyObject->localAnimation[i] = PREY2;
				
			}
			
			// if prey is dead, reset to default animation step
			else if (preyObject->isAlive[i]==0)
				preyObject->localAnimation[i] = PREY1;
			
		}
	}
	
}

preyType* createPreyObject(){
	
	int i;
	
	preyType *p;
	p = calloc(sizeof(preyType),1);
	
	p->numberOfAlivePrey = 0;
	
	for(i=0; i<MAXPREY; i++)
		p->isAlive[i] = 0;
	
	for(i=0; i<MAXPREY; i++)
		p->localAnimation[i] = PREY1;
	
	for(i=0; i<MAXPREY; i++)
		p->preyPositionX[i] = p->preyPositionY[i] = p->preyPositionZ[i] = 0;
	
	for(i=0; i<MAXPREY; i++)
		p->currentAngle[i] = 0;
	
	return (p);
	
}

GLint createPrey6()
{
	
	glNewList(PREY6,GL_COMPILE);
	
	// Head
	glPushMatrix();
    glColor3f(0.82, 0.71, 0.55);
	glRotatef(90,0,1,0);
	glScalef(0.5, 0.5, 1);
	glTranslatef(0,0,-1);
	glScalef(0.75, 0.75, 0.75);
	glutSolidOctahedron();
	glPopMatrix();
	
	// Ear 1
	glPushMatrix();
    glColor3f(0.55, 0.27, 0.075);
	glRotatef(90,1,0,0);
	glScalef(0.5, 0.5, 2);
	glTranslatef(-2.2,0.3,-0.1);
	glScalef(0.18, 0.18, 0.18);
	glutSolidOctahedron();
	glPopMatrix();
	
	
	// Ear 2
	glPushMatrix();
    glColor3f(0.55, 0.27, 0.075);
	glRotatef(90,1,0,0);
	glScalef(0.5, 0.5, 2);
	glTranslatef(-2.2,-0.3,-0.1);
	glScalef(0.18, 0.18, 0.18);
	glutSolidOctahedron();
	glPopMatrix();
	
	// Eye 1
	glPushMatrix();
    glColor3f(0.0,1,1.0);
	glScalef(0.05, 0.05, 0.05);
	glTranslatef(-27, 2, 2);
	glutSolidDodecahedron();
	glPopMatrix();
	
	// Eye 2
	glPushMatrix();
    glColor3f(0.0,1,1.0);
	glScalef(0.05, 0.05, 0.05);
	glTranslatef(-27, 2, -2);
	glutSolidDodecahedron();
	glPopMatrix();
	
	// Body
	glPushMatrix();
	GLUquadric *meta = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, -0.7);
	gluCylinder(meta, 0.4, 0.4, 2, 20, 20);
	glPopMatrix();
	
	// Neck Disk
	glPushMatrix();
	GLUquadric *meta1 = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glTranslatef(-0.7, 0, 0);
	glRotatef(90, 0, 1, 0);
	gluDisk(meta1, 0, 0.4, 50, 20);
	glPopMatrix();
	
	// Rear Disk
	glPushMatrix();
	GLUquadric *meta2 = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glTranslatef(1.3, 0, 0);
	glRotatef(90, 0, 1, 0);
	gluDisk(meta2, 0, 0.4, 50, 20);
	glPopMatrix();
	
	// Tail
	glPushMatrix();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(1.5, -0.1, 0);
	glRotatef(-60, 0, 0, 1);
	glScalef(4, 0.25, 0.25);
	glutSolidCube(0.25);
	glPopMatrix();
	
	// Front Left Leg - BACK
	glPushMatrix();
	GLUquadric *meta3 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(-0.4, 0, 0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(30, 0, 1, 0);
	glRotatef(-25, 1, 0, 0);
	gluCylinder(meta3, 0.25, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Front Right Leg - FORWARD
	glPushMatrix();
	GLUquadric *meta4 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(-0.4, 0, -0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-30, 0, 1, 0);
	glRotatef(25, 1, 0, 0);
	gluCylinder(meta4, 0.25, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Back Left Leg - BACK
	glPushMatrix();
	GLUquadric *meta5 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(0.85, 0, 0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(30, 0, 1, 0);
	glRotatef(-25, 1, 0, 0);
	gluCylinder(meta5, 0.27, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Back Right Leg - FORWARD
	glPushMatrix();
	GLUquadric *meta6 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(0.85, 0, -0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-30, 0, 1, 0);
	glRotatef(25, 1, 0, 0);
	gluCylinder(meta6, 0.27, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	glEndList();
	
	return(PREY6);
}

GLint createPrey5()
{
	
	glNewList(PREY5,GL_COMPILE);
	
	// Head
	glPushMatrix();
    glColor3f(0.82, 0.71, 0.55);
	glRotatef(90,0,1,0);
	glScalef(0.5, 0.5, 1);
	glTranslatef(0,0,-1);
	glScalef(0.75, 0.75, 0.75);
	glutSolidOctahedron();
	glPopMatrix();
	
	// Ear 1
	glPushMatrix();
    glColor3f(0.55, 0.27, 0.075);
	glRotatef(90,1,0,0);
	glScalef(0.5, 0.5, 2);
	glTranslatef(-2.2,0.3,-0.1);
	glScalef(0.18, 0.18, 0.18);
	glutSolidOctahedron();
	glPopMatrix();
	
	
	// Ear 2
	glPushMatrix();
    glColor3f(0.55, 0.27, 0.075);
	glRotatef(90,1,0,0);
	glScalef(0.5, 0.5, 2);
	glTranslatef(-2.2,-0.3,-0.1);
	glScalef(0.18, 0.18, 0.18);
	glutSolidOctahedron();
	glPopMatrix();
	
	// Eye 1
	glPushMatrix();
    glColor3f(0.0,1,1.0);
	glScalef(0.05, 0.05, 0.05);
	glTranslatef(-27, 2, 2);
	glutSolidDodecahedron();
	glPopMatrix();
	
	// Eye 2
	glPushMatrix();
    glColor3f(0.0,1,1.0);
	glScalef(0.05, 0.05, 0.05);
	glTranslatef(-27, 2, -2);
	glutSolidDodecahedron();
	glPopMatrix();
	
	// Body
	glPushMatrix();
	GLUquadric *meta = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, -0.7);
	gluCylinder(meta, 0.4, 0.4, 2, 20, 20);
	glPopMatrix();
	
	// Neck Disk
	glPushMatrix();
	GLUquadric *meta1 = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glTranslatef(-0.7, 0, 0);
	glRotatef(90, 0, 1, 0);
	gluDisk(meta1, 0, 0.4, 50, 20);
	glPopMatrix();
	
	// Rear Disk
	glPushMatrix();
	GLUquadric *meta2 = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glTranslatef(1.3, 0, 0);
	glRotatef(90, 0, 1, 0);
	gluDisk(meta2, 0, 0.4, 50, 20);
	glPopMatrix();
	
	// Tail
	glPushMatrix();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(1.5, -0.1, 0);
	glRotatef(-60, 0, 0, 1);
	glScalef(4, 0.25, 0.25);
	glutSolidCube(0.25);
	glPopMatrix();
	
	// Front Left Leg
	glPushMatrix();
	GLUquadric *meta3 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(-0.4, 0, 0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-25, 1, 0, 0);
	gluCylinder(meta3, 0.25, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Front Right Leg - FORWARD
	glPushMatrix();
	GLUquadric *meta4 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(-0.4, 0, -0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-30, 0, 1, 0);
	glRotatef(25, 1, 0, 0);
	gluCylinder(meta4, 0.25, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Back Left Leg
	glPushMatrix();
	GLUquadric *meta5 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(0.85, 0, 0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-25, 1, 0, 0);
	gluCylinder(meta5, 0.27, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Back Right Leg - FORWARD
	glPushMatrix();
	GLUquadric *meta6 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(0.85, 0, -0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-30, 0, 1, 0);
	glRotatef(25, 1, 0, 0);
	gluCylinder(meta6, 0.27, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	glEndList();
	
	return(PREY5);
}

GLint createPrey4(){
	
	glNewList(PREY4,GL_COMPILE);
	
	// Head
	glPushMatrix();
    glColor3f(0.82, 0.71, 0.55);
	glRotatef(90,0,1,0);
	glScalef(0.5, 0.5, 1);
	glTranslatef(0,0,-1);
	glScalef(0.75, 0.75, 0.75);
	glutSolidOctahedron();
	glPopMatrix();
	
	// Ear 1
	glPushMatrix();
    glColor3f(0.55, 0.27, 0.075);
	glRotatef(90,1,0,0);
	glScalef(0.5, 0.5, 2);
	glTranslatef(-2.2,0.3,-0.1);
	glScalef(0.18, 0.18, 0.18);
	glutSolidOctahedron();
	glPopMatrix();
	
	
	// Ear 2
	glPushMatrix();
    glColor3f(0.55, 0.27, 0.075);
	glRotatef(90,1,0,0);
	glScalef(0.5, 0.5, 2);
	glTranslatef(-2.2,-0.3,-0.1);
	glScalef(0.18, 0.18, 0.18);
	glutSolidOctahedron();
	glPopMatrix();
	
	// Eye 1
	glPushMatrix();
    glColor3f(0.0,1,1.0);
	glScalef(0.05, 0.05, 0.05);
	glTranslatef(-27, 2, 2);
	glutSolidDodecahedron();
	glPopMatrix();
	
	// Eye 2
	glPushMatrix();
    glColor3f(0.0,1,1.0);
	glScalef(0.05, 0.05, 0.05);
	glTranslatef(-27, 2, -2);
	glutSolidDodecahedron();
	glPopMatrix();
	
	// Body
	glPushMatrix();
	GLUquadric *meta = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, -0.7);
	gluCylinder(meta, 0.4, 0.4, 2, 20, 20);
	glPopMatrix();
	
	// Neck Disk
	glPushMatrix();
	GLUquadric *meta1 = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glTranslatef(-0.7, 0, 0);
	glRotatef(90, 0, 1, 0);
	gluDisk(meta1, 0, 0.4, 50, 20);
	glPopMatrix();
	
	// Rear Disk
	glPushMatrix();
	GLUquadric *meta2 = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glTranslatef(1.3, 0, 0);
	glRotatef(90, 0, 1, 0);
	gluDisk(meta2, 0, 0.4, 50, 20);
	glPopMatrix();
	
	// Tail
	glPushMatrix();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(1.5, -0.1, 0);
	glRotatef(-60, 0, 0, 1);
	glScalef(4, 0.25, 0.25);
	glutSolidCube(0.25);
	glPopMatrix();
	
	// Front Left Leg
	glPushMatrix();
	GLUquadric *meta3 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(-0.4, 0, 0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-25, 1, 0, 0);
	gluCylinder(meta3, 0.25, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Front Right Leg
	glPushMatrix();
	GLUquadric *meta4 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(-0.4, 0, -0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(25, 1, 0, 0);
	gluCylinder(meta4, 0.25, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Back Left Leg
	glPushMatrix();
	GLUquadric *meta5 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(0.85, 0, 0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-25, 1, 0, 0);
	gluCylinder(meta5, 0.27, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Back Right Leg
	glPushMatrix();
	GLUquadric *meta6 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(0.85, 0, -0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(25, 1, 0, 0);
	gluCylinder(meta6, 0.27, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	glEndList();
	
	return(PREY4);
	
}

GLint createPrey3()
{
	
	glNewList(PREY3,GL_COMPILE);
	
	// Head
	glPushMatrix();
    glColor3f(0.82, 0.71, 0.55);
	glRotatef(90,0,1,0);
	glScalef(0.5, 0.5, 1);
	glTranslatef(0,0,-1);
	glScalef(0.75, 0.75, 0.75);
	glutSolidOctahedron();
	glPopMatrix();
	
	// Ear 1
	glPushMatrix();
    glColor3f(0.55, 0.27, 0.075);
	glRotatef(90,1,0,0);
	glScalef(0.5, 0.5, 2);
	glTranslatef(-2.2,0.3,-0.1);
	glScalef(0.18, 0.18, 0.18);
	glutSolidOctahedron();
	glPopMatrix();
	
	
	// Ear 2
	glPushMatrix();
    glColor3f(0.55, 0.27, 0.075);
	glRotatef(90,1,0,0);
	glScalef(0.5, 0.5, 2);
	glTranslatef(-2.2,-0.3,-0.1);
	glScalef(0.18, 0.18, 0.18);
	glutSolidOctahedron();
	glPopMatrix();
	
	// Eye 1
	glPushMatrix();
    glColor3f(0.0,1,1.0);
	glScalef(0.05, 0.05, 0.05);
	glTranslatef(-27, 2, 2);
	glutSolidDodecahedron();
	glPopMatrix();
	
	// Eye 2
	glPushMatrix();
    glColor3f(0.0,1,1.0);
	glScalef(0.05, 0.05, 0.05);
	glTranslatef(-27, 2, -2);
	glutSolidDodecahedron();
	glPopMatrix();
	
	// Body
	glPushMatrix();
	GLUquadric *meta = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, -0.7);
	gluCylinder(meta, 0.4, 0.4, 2, 20, 20);
	glPopMatrix();
	
	// Neck Disk
	glPushMatrix();
	GLUquadric *meta1 = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glTranslatef(-0.7, 0, 0);
	glRotatef(90, 0, 1, 0);
	gluDisk(meta1, 0, 0.4, 50, 20);
	glPopMatrix();
	
	// Rear Disk
	glPushMatrix();
	GLUquadric *meta2 = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glTranslatef(1.3, 0, 0);
	glRotatef(90, 0, 1, 0);
	gluDisk(meta2, 0, 0.4, 50, 20);
	glPopMatrix();
	
	// Tail
	glPushMatrix();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(1.5, -0.1, 0);
	glRotatef(-60, 0, 0, 1);
	glScalef(4, 0.25, 0.25);
	glutSolidCube(0.25);
	glPopMatrix();
	
	// Front Left Leg - FORWARD
	glPushMatrix();
	GLUquadric *meta3 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(-0.4, 0, 0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-30, 0, 1, 0);
	glRotatef(-25, 1, 0, 0);
	gluCylinder(meta3, 0.25, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Front Right Leg - BACK
	glPushMatrix();
	GLUquadric *meta4 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(-0.4, 0, -0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(30, 0, 1, 0);
	glRotatef(25, 1, 0, 0);
	gluCylinder(meta4, 0.25, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Back Left Leg - FORWARD
	glPushMatrix();
	GLUquadric *meta5 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(0.85, 0, 0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-30, 0, 1, 0);
	glRotatef(-25, 1, 0, 0);
	gluCylinder(meta5, 0.27, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Back Right Leg - BACK
	glPushMatrix();
	GLUquadric *meta6 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(0.85, 0, -0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(
			  30, 0, 1, 0);
	glRotatef(25, 1, 0, 0);
	gluCylinder(meta6, 0.27, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	glEndList();
	
	return(PREY3);
}

GLint createPrey2()
{
	
	glNewList(PREY2,GL_COMPILE);
	
	// Head
	glPushMatrix();
    glColor3f(0.82, 0.71, 0.55);
	glRotatef(90,0,1,0);
	glScalef(0.5, 0.5, 1);
	glTranslatef(0,0,-1);
	glScalef(0.75, 0.75, 0.75);
	glutSolidOctahedron();
	glPopMatrix();
	
	// Ear 1
	glPushMatrix();
    glColor3f(0.55, 0.27, 0.075);
	glRotatef(90,1,0,0);
	glScalef(0.5, 0.5, 2);
	glTranslatef(-2.2,0.3,-0.1);
	glScalef(0.18, 0.18, 0.18);
	glutSolidOctahedron();
	glPopMatrix();
	
	
	// Ear 2
	glPushMatrix();
    glColor3f(0.55, 0.27, 0.075);
	glRotatef(90,1,0,0);
	glScalef(0.5, 0.5, 2);
	glTranslatef(-2.2,-0.3,-0.1);
	glScalef(0.18, 0.18, 0.18);
	glutSolidOctahedron();
	glPopMatrix();
	
	// Eye 1
	glPushMatrix();
    glColor3f(0.0,1,1.0);
	glScalef(0.05, 0.05, 0.05);
	glTranslatef(-27, 2, 2);
	glutSolidDodecahedron();
	glPopMatrix();
	
	// Eye 2
	glPushMatrix();
    glColor3f(0.0,1,1.0);
	glScalef(0.05, 0.05, 0.05);
	glTranslatef(-27, 2, -2);
	glutSolidDodecahedron();
	glPopMatrix();
	
	// Body
	glPushMatrix();
	GLUquadric *meta = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, -0.7);
	gluCylinder(meta, 0.4, 0.4, 2, 20, 20);
	glPopMatrix();
	
	// Neck Disk
	glPushMatrix();
	GLUquadric *meta1 = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glTranslatef(-0.7, 0, 0);
	glRotatef(90, 0, 1, 0);
	gluDisk(meta1, 0, 0.4, 50, 20);
	glPopMatrix();
	
	// Rear Disk
	glPushMatrix();
	GLUquadric *meta2 = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glTranslatef(1.3, 0, 0);
	glRotatef(90, 0, 1, 0);
	gluDisk(meta2, 0, 0.4, 50, 20);
	glPopMatrix();
	
	// Tail
	glPushMatrix();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(1.5, -0.1, 0);
	glRotatef(-60, 0, 0, 1);
	glScalef(4, 0.25, 0.25);
	glutSolidCube(0.25);
	glPopMatrix();
	
	// Front Left Leg - FORWARD
	glPushMatrix();
	GLUquadric *meta3 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(-0.4, 0, 0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-30, 0, 1, 0);
	glRotatef(-25, 1, 0, 0);
	gluCylinder(meta3, 0.25, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Front Right Leg
	glPushMatrix();
	GLUquadric *meta4 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(-0.4, 0, -0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(25, 1, 0, 0);
	gluCylinder(meta4, 0.25, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Back Left Leg - FORWARD
	glPushMatrix();
	GLUquadric *meta5 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(0.85, 0, 0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-30, 0, 1, 0);
	glRotatef(-25, 1, 0, 0);
	gluCylinder(meta5, 0.27, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Back Right Leg
	glPushMatrix();
	GLUquadric *meta6 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(0.85, 0, -0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(25, 1, 0, 0);
	gluCylinder(meta6, 0.27, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	glEndList();
	
	return(PREY2);
}

GLint createPrey1()
{
	
	glNewList(PREY1,GL_COMPILE);
	
	// Head
	glPushMatrix();
    glColor3f(0.82, 0.71, 0.55);
	glRotatef(90,0,1,0);
	glScalef(0.5, 0.5, 1);
	glTranslatef(0,0,-1);
	glScalef(0.75, 0.75, 0.75);
	glutSolidOctahedron();
	glPopMatrix();
	
	// Ear 1
	glPushMatrix();
    glColor3f(0.55, 0.27, 0.075);
	glRotatef(90,1,0,0);
	glScalef(0.5, 0.5, 2);
	glTranslatef(-2.2,0.3,-0.1);
	glScalef(0.18, 0.18, 0.18);
	glutSolidOctahedron();
	glPopMatrix();
	
	
	// Ear 2
	glPushMatrix();
    glColor3f(0.55, 0.27, 0.075);
	glRotatef(90,1,0,0);
	glScalef(0.5, 0.5, 2);
	glTranslatef(-2.2,-0.3,-0.1);
	glScalef(0.18, 0.18, 0.18);
	glutSolidOctahedron();
	glPopMatrix();
	
	// Eye 1
	glPushMatrix();
    glColor3f(0.0,1,1.0);
	glScalef(0.05, 0.05, 0.05);
	glTranslatef(-27, 2, 2);
	glutSolidDodecahedron();
	glPopMatrix();
	
	// Eye 2
	glPushMatrix();
    glColor3f(0.0,1,1.0);
	glScalef(0.05, 0.05, 0.05);
	glTranslatef(-27, 2, -2);
	glutSolidDodecahedron();
	glPopMatrix();
	
	// Body
	glPushMatrix();
	GLUquadric *meta = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, -0.7);
	gluCylinder(meta, 0.4, 0.4, 2, 20, 20);
	glPopMatrix();
	
	// Neck Disk
	glPushMatrix();
	GLUquadric *meta1 = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glTranslatef(-0.7, 0, 0);
	glRotatef(90, 0, 1, 0);
	gluDisk(meta1, 0, 0.4, 50, 20);
	glPopMatrix();
	
	// Rear Disk
	glPushMatrix();
	GLUquadric *meta2 = gluNewQuadric();
	glColor3f(0.82, 0.71, 0.55);
	glTranslatef(1.3, 0, 0);
	glRotatef(90, 0, 1, 0);
	gluDisk(meta2, 0, 0.4, 50, 20);
	glPopMatrix();
	
	// Tail
	glPushMatrix();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(1.5, -0.1, 0);
	glRotatef(-60, 0, 0, 1);
	glScalef(4, 0.25, 0.25);
	glutSolidCube(0.25);
	glPopMatrix();
	
	// Front Left Leg
	glPushMatrix();
	GLUquadric *meta3 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(-0.4, 0, 0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-25, 1, 0, 0);
	gluCylinder(meta3, 0.25, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Front Right Leg
	glPushMatrix();
	GLUquadric *meta4 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(-0.4, 0, -0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(25, 1, 0, 0);
	gluCylinder(meta4, 0.25, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Back Left Leg
	glPushMatrix();
	GLUquadric *meta5 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(0.85, 0, 0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-25, 1, 0, 0);
	gluCylinder(meta5, 0.27, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	// Back Right Leg
	glPushMatrix();
	GLUquadric *meta6 = gluNewQuadric();
	glColor3f(0.55, 0.27, 0.075);
	glTranslatef(0.85, 0, -0.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(25, 1, 0, 0);
	gluCylinder(meta6, 0.27, 0.1, 1.35, 20, 20);
	glPopMatrix();
	
	glEndList();
	
	return(PREY1);
}




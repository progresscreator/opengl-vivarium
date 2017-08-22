
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
#include <time.h>

void drawWorld(){
	
	// Arbitrarily writing object information to screen
	
	// Draw vivarium
	glCallList(VIVAR);
	
	// Draw Predator
	drawPredator();
	
	// Draw Prey
	int i;
	for(i=0; i< MAXPREY; i++){
		
		// for each living prey...
		if(preyObject->isAlive[i]){
			
			float x = preyObject->preyPositionX[i];
			float y = preyObject->preyPositionY[i];
			float z = preyObject->preyPositionZ[i];
			
			float rotation = preyObject->currentAngle[i];
			int AnimationID = preyObject->localAnimation[i];
			
			drawPrey(AnimationID, rotation, x, y, z);
			
		}
	}

}

void drawPredator(){
	
	glPushMatrix();
	
	// Scale UFO
	glScalef(0.3, 0.3, 0.3);
	
	// Place UFO at current position
	glTranslatef(predatorObject->predPositionX,predatorObject->predPositionY,predatorObject->predPositionZ);

	// Draw with local animation
	glCallList(PREDOUT);
	
	glPopMatrix();
	
}

void drawPrey(int AnimationID, float rotation, float x, float y, float z){
	
	glPushMatrix();
	
	// Scale Cow
	glScalef(0.16, 0.16, 0.16);
	
	// Place Cow at current position
	glTranslatef(x,y,z);
	
	// Rotate Cow
	glRotatef(rotation,0,1,0);
	
	// Draw with local animation
	glCallList(AnimationID);
	
	glPopMatrix();
	
}

void genTestCases(){
	
	int i=0;
	
	for(i=0; i<4; i++){
		
		srand( i*i);
		
		preyObject->isAlive[i] = 1;
		
		preyObject->preyPositionX[i] = rand() % 15;
		preyObject->preyPositionY[i] = -11;
		preyObject->preyPositionZ[i] = -rand() % 15;
		
		preyObject->currentAngle[i] = rand() % 360;
		
	}
	
	predatorObject->predPositionY = -3;
	
}

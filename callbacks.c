/*******************************************************************
   Example Callback Subroutines for CS480 Spinning Teapot Example 
********************************************************************
    Author: Stan Sclaroff
      Date: October 22, 2004
  Comments: Subroutines to support GLUT library callbacks.
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GLUT/glut.h>
#include "const.h"
#include "types.h"
#include "funcs.h"

static float viewing_quaternion[4] = {1,0,0,0};

int frame,time,timebase = 0;
char s[30];

/* window size change */
void reshape(int width, int height)
{
  double ratio;

  /* Prevent a divide by zero, when window is too short
     (you cant make a window of zero width). */
  if(height == 0)
    height = 1;

  ratio = 1.0f * width / height;

  /* Reset the coordinate system before modifying */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  /* Set the viewport to be the entire window */
  glViewport(0, 0, width, height);
  
  /* Set the clipping volume */
  gluPerspective(25,ratio,0.1,100);

  /* Camera positioned at (0,0,6), look at point (0,0,0), Up Vector (0,1,0) */
  gluLookAt(0,0,12,0,0,0,0,1,0);

  glMatrixMode(GL_MODELVIEW);
}

/* redisplaying graphics */
void display(void)
{
  /* matrix for rotation converted from quaternion */
  float M[4][4]; 

  /* clear the display */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  quaternion_to_matrix(viewing_quaternion,M);
  glMultMatrixf(&M[0][0]);
	
  /* Update Local Animations */
  updateLocalPredatorAnimation();
  updateLocalPreyAnimations();

  /* rotate the world and then call world display list object */
  drawWorld();
	
	
	// Print FPS
	frame++;
	time=glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s,"FPS:%4.2f",frame*1000.0/(time-timebase));
		predatorObject->fps = frame*1000.0/(time-timebase);
		preyObject->fps = frame*1000.0/(time-timebase);
		glutSetWindowTitle(s);
		timebase = time;		
		frame = 0;
	}
	
	
  /* swap the double buffers*/
  glutSwapBuffers();  
}

void idle(void)
{
  glutPostRedisplay();
}

/* handles input from the keyboard */
void keyboard(unsigned char key, int x, int y)
{
	
  switch(key){
  case 'q':
  case 'Q':
  case 27:  
    /* Esc, q, or Q key = Quit */
    exit(0);
    break;

  case 'R':
  case 'r':
    /* reset the viewing quaternion = 0 rotation */
    viewing_quaternion[0] = 1;
    viewing_quaternion[1] = viewing_quaternion[2] = viewing_quaternion[3] = 0.0;
    glutPostRedisplay();
    break;

  default:
    break;
  }
}

/* 
mouse press/motion handler
  
   left button: rotate the scene by increment about axis 
*/

static int last_x,last_y;
static int currentButton;

void mouseButton(int button, int state, int x, int y)
{

  currentButton = button;
  if (button == GLUT_LEFT_BUTTON){  
    switch (state) {      
    case GLUT_DOWN:
      last_x = x;
      last_y = y;
      break;
    }
  }    

  /* update display not needed */
  /* glutPostRedisplay();  */
}

/* mouse motion callback */
void mouseMotion(int x, int y)
{
  float dx,dy;
  float rotation_axis[3], mag, q[4];
  float viewing_delta = PI/360.0;  /* 0.5 degrees */
  float s,c;

  switch(currentButton)
    {
    case(GLUT_LEFT_BUTTON):

      /* vector in direction of mouse motion */
      dx = x - last_x;
      dy = y - last_y;

      /* spin around axis by small delta */
      mag = sqrt(dx*dx+dy*dy);
      rotation_axis[0]=dy/mag;
      rotation_axis[1]=dx/mag;
      rotation_axis[2]=0.0;
      
      /* calculate the appropriate quaternion */
      s = sin(0.5*viewing_delta);
      c = cos(0.5*viewing_delta);

      q[0] = c;
      q[1] = s*rotation_axis[0];
      q[2] = s*rotation_axis[1];
      q[3] = s*rotation_axis[2];
      
      quaternion_multiply(viewing_quaternion,q,viewing_quaternion);

      /* normalize, to counteract accumulating round-off error */
      quaternion_normalize(viewing_quaternion); 

      /* save current x,y as last x,y */
      last_x = x;
      last_y = y;
      break;
    }
  /* redisplay */
  glutPostRedisplay();
}

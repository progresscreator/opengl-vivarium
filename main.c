/*******************************************************************
       Example Main Program for CS480 Programming Assignment 3
********************************************************************
    Author: Stan Sclaroff
            Boston University Computer Science Dept.
            October 22, 2004
********************************************************************
Description: This is a simple example program that demonstrates 
             a teapot spinning in a tank. 

	     The following keys control the program:

             Q,q, <escape>: quit
             R: reset viewing angle

             Left mouse click + drag motion: rotate the tank view

********************************************************************
Comments: This program uses the GLUT library. This library has it's
	    own event loop handler which passes control back to your
	    program's callback routines.  Links to WWW pages for GLUT
	    and OpenGL are provided on the course web page.
********************************************************************/

#include <stdlib.h>
#include <GLUT/glut.h>
#include "const.h"
#include "types.h"
#include "funcs.h"

void initShading();

int main(int argc, char **argv)
{
  GLint windW=DEFAULT_WINDOW_WIDTH, windH=DEFAULT_WINDOW_HEIGHT;

  glutInit(&argc, argv);

  /* display modes: 24 BIT, double buffer mode */
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(windW,windH);
  glutCreateWindow("CS480/CS680: David House");

  /*  register callbacks for window redisplay 
      and reshape event callbacks */
  glutDisplayFunc(display);
  glutReshapeFunc(reshape); 
  glutIdleFunc(idle);

  /* setup keyboard handler callback */
  glutKeyboardFunc(keyboard);

  /* setup mouse handler callbacks */
  glutMotionFunc(mouseMotion);
  glutMouseFunc(mouseButton);

  initShading();
	
  // Perform custom setup
  initializePredatorAnimations();
  initializePreyAnimations();
  initializeVivarium();
	
	// DEBUG
	genTestCases();

  /* turn over control to GLUT */
  glutMainLoop();

  return 0;             
}

void initShading()
{
  /* set up for shaded display of the tree */
  GLfloat light0_position[] = {1,1,1,0};
  GLfloat light0_ambient_color[] = {0.25,0.25,0.25,1};
  GLfloat light0_diffuse_color[] = {1,1,1,1};

  glPolygonMode(GL_FRONT,GL_FILL);
  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

  glClearColor(0.0,0.0,0.0,0.0);
  glShadeModel(GL_SMOOTH);
  
  /* set up the light source */
 
  glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient_color);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse_color);

  /* turn lighting and depth buffering on */
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
}

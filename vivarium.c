/*******************************************************************
     Support Routines for a Simple Vivarium Tank + Teapot 
********************************************************************
    Author: Stan Sclaroff
      Date: October 22, 2004
  Comments: This is just meant for demonstration.  PLEASE plan
            out your own vivarium creatures, display list hierarchy, 
            data structures, etc.  No teapots allowed ;)
********************************************************************/

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


// load a 256x256 RGB .RAW file as a texture
GLuint LoadGrassTexture(int wrap)
{
	GLuint texture;
    int width, height;
    GLubyte * data;
    FILE * file;
	
	// source: nullterminator.net
    // open texture data
    file = fopen( "grass.raw", "rb" );
	
    // allocate buffer
    width = 256;
    height = 256;
    data = malloc( width * height * 3 );
	
    // read texture data
    fread( data, width * height * 3, 1, file );
    fclose( file );
	
    // allocate a texture name
    glGenTextures( 1, &texture );
	
    // select our current texture
    glBindTexture( GL_TEXTURE_2D, texture );
	
    // select modulate to mix texture with color for shading
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	
    // if wrap is true, the texture wraps over at the edges (repeat)
    //       ... false, the texture ends at the edges (clamp)
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
					wrap ? GL_REPEAT : GL_CLAMP );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
					wrap ? GL_REPEAT : GL_CLAMP );
	
    // build our texture mipmaps
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,
					  GL_RGB, GL_UNSIGNED_BYTE, data );
	
    // free buffer
    free( data );
	
	return(texture);
	
}

/* Create the vivarium tank, with texture mapped floor */
GLint createTankObject(float w, float h, float d)
{

  GLuint tank;
  LoadGrassTexture(1);
  tank = glGenLists(1);
  
  glNewList(tank,GL_COMPILE);
  glBegin(GL_LINE_STRIP);
  glVertex3f(w/2,h/2,d/2);
  glVertex3f(-w/2,h/2,d/2);
  glVertex3f(-w/2,-h/2,d/2);
  glVertex3f(w/2,-h/2,d/2);
  glVertex3f(w/2,h/2,d/2);
  glVertex3f(w/2,h/2,-d/2);
  glVertex3f(-w/2,h/2,-d/2);
  glVertex3f(-w/2,-h/2,-d/2);
  glVertex3f(w/2,-h/2,-d/2);
  glVertex3f(w/2,h/2,-d/2);
  glEnd();
  glBegin(GL_LINES);
  glVertex3f(-w/2,-h/2,d/2);
  glVertex3f(-w/2,-h/2,-d/2);
  glVertex3f(-w/2,h/2,d/2);
  glVertex3f(-w/2,h/2,-d/2);
  glVertex3f(w/2,-h/2,d/2);
  glVertex3f(w/2,-h/2,-d/2);
  glEnd();
  glEnable(GL_TEXTURE_2D);
  glBegin(GL_QUADS);
  glTexCoord2f(1.0,1.0);
  glVertex3f(w/2,-h/2,d/2);
  glTexCoord2f(1.0,0.0);
  glVertex3f(w/2,-h/2,-d/2);
  glTexCoord2f(0.0,0.0);
  glVertex3f(-w/2,-h/2,-d/2);
  glTexCoord2f(0.0,1.0);
  glVertex3f(-w/2,-h/2,d/2);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  glEndList();  
  
  return(tank);
}

/* update the vivarium object */
void initializeVivarium()
{
  static GLint tank_object;
	
  if(!tank_object)
    tank_object = createTankObject(4.0,4.0,4.0);

  glNewList(VIVAR,GL_COMPILE);
	
  glPushMatrix();
  glColor3f(1, 1, 1);
  glCallList(tank_object);
  glPopMatrix();
	
  glEndList();
	
}



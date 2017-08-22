/*******************************************************************
		     Support Routines for Quaternions
********************************************************************
    Author: Stan Sclaroff
      Date: October 22, 2004
  Comments: These are a few functions written for handling quaternions.
********************************************************************/

#include <math.h>
#include "const.h"

#define CROSS_PRODUCT(O,A,B) {(O)[0] = (A)[1]*(B)[2]-(A)[2]*(B)[1]; \
                              (O)[1] = (A)[2]*(B)[0]-(A)[0]*(B)[2]; \
                              (O)[2] = (A)[0]*(B)[1]-(A)[1]*(B)[0];}

/* Multiply two quaternions */
/* Use Eq. A-79 on p. 806 of Hearn and Baker */
void quaternion_multiply(float *out_q, float *q1, float *q2)
{

  float q[4];
  int i;

  // s = s1*s2 - v1.v2

  q[0] = q1[0]*q2[0]-q1[1]*q2[1]-q1[2]*q2[2]-q1[3]*q2[3];

  // v = s1 v2 + s2 v2 + v1 x v2

  CROSS_PRODUCT(&q[1],&q1[1],&q2[1]);

  for(i=1;i<4;++i)
    q[i] += q1[0]*q2[i]+q2[0]*q1[i];

  // copy result to output vector

  for(i=0;i<4;++i)
    out_q[i] = q[i];
}

/* Use Eq. 5-107 on p. 273 of Hearn and Baker */
/* be aware that OpenGL uses transpose of the matrix */
void quaternion_to_matrix(float q[4], float M[4][4])
{
  float a,b,c,s;

  s = q[0];
  a = q[1];
  b = q[2];
  c = q[3];
 
  M[0][0] = 1 - 2*b*b - 2*c*c;
  M[1][0] = 2*a*b - 2*s*c;
  M[2][0] = 2*a*c + 2*s*b;
  
  M[0][1] = 2*a*b + 2*s*c;
  M[1][1] = 1 - 2*a*a - 2*c*c;
  M[2][1] = 2*b*c - 2*s*a;
  
  M[0][2] = 2*a*c - 2*s*b;
  M[1][2] = 2*b*c + 2*s*a;
  M[2][2] = 1 - 2*a*a - 2*b*b;
  
  M[0][3] = M[1][3] = M[2][3] = 0.0;
  M[3][0] = M[3][1] = M[3][2] = 0.0;
  M[3][3] = 1.0;
}

/* due to accumulating round-off error, it may be necessary to normalize */
/* this will ensure that the quaternion is truly unit */
void quaternion_normalize(float q[4])
{
  float mag=0;
  int i;
  
  for(i=0;i<4;++i)
    mag+=q[i]*q[i];

  mag = sqrt(mag);
  
  if(mag > EPSILON)
    for(i=0;i<4;++i)
      q[i] /= mag;
}
  
  

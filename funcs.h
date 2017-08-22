/*******************************************************************
	      Function Prototypes for CS480 Teapot Example
********************************************************************
    Author: Stan Sclaroff
      Date: October 22, 2004
  Comments: Feel free to modify this file for your assignment.
*********************************************************************/


/* types.h */
typedef struct _predatorType predatorType;
predatorType* createPredatorObject();
typedef struct _preyType preyType;
preyType* createPreyObject();

// Static Objects
predatorType *predatorObject;
preyType *preyObject;

/* world.c */
void drawWorld();
void drawPredator();
void drawPrey(int AnimationID, float rotation, float x, float y, float z);
void genTestCases();

/* prey.c */
GLint createPrey1();
GLint createPrey2();
GLint createPrey3();
GLint createPrey4();
GLint createPrey5();
GLint createPrey6();
void initializePreyAnimations();
void updateLocalPreyAnimations();
 
/* predator.c */
GLint createPredator1();
GLint createPredator2();
GLint createPredator3();
GLint createPredator4();
GLint createPredator5();
void initializePredatorAnimations();
void updateLocalPredatorAnimation();

/* callbacks.c */
void reshape(int width, int height);
void display(void);
void keyboard(unsigned char key, int x, int y);
void special(int k, int x, int y);
void mouseMotion(int x, int y);
void mouseButton(int button, int state, int x, int y);
void idle(void);

/* vivarium.c */
GLuint LoadGrassTexture(int wrap);
GLint createTankObject(float w, float h, float d);
void initializeVivarium();
void drawVivariumObject();

/* quaternion.c */
void quaternion_multiply(float *out_q, float *q1, float *q2);
void quaternion_to_matrix(float q[4],float M[4][4]);
void quaternion_normalize(float q[4]);

/* materials.c */
void changeGLMaterial(int i);
void setMaterialColor(int i, float r, float g, float b, float a);
void initMaterials(void);

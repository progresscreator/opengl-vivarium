/*******************************************************************
	      Basic Type Definitions for CS480 Teapot Example
********************************************************************
    Author: Stan Sclaroff
      Date: October 22, 2004
  Comments: This is just an example. Design your own structures
            for creatures in this assignment.
********************************************************************/

struct _predatorType{

	// Frame Count Information
	int frameNumber;
	
	// Rotation Angle Information
	float currentAngle;
	
	// Local Animation ID Information
	int localAnimation;
	
	// Location Information
	float predPositionX;
	float predPositionY;
	float predPositionZ;
	
	// Frames Per Second
	float fps;

};

struct _preyType{
	
	// Frame Count Information
	int frameNumber;
	
	// Living Prey Count
	int numberOfAlivePrey;
	
	// Prey Status Information
	int isAlive[MAXPREY];
	
	// Location Information for Each Prey
	// Indexed by numberOfAlivePrey
	float preyPositionX[MAXPREY];
	float preyPositionY[MAXPREY];
	float preyPositionZ[MAXPREY];
	
	// Local Animation ID Information for Each Prey
	int localAnimation[MAXPREY];
	
	// Rotation Angle Information for Each Prey
	float currentAngle[MAXPREY];
	
	// Frames Per Second
	float fps;
	
};
// MotionCapture.h

#ifndef _MOTIONCAPTURE_h
#define _MOTIONCAPTURE_h

#include <MPU6050.h>
#include <I2Cdev.h>
#include <Wire.h>
#include "DataCapture.h"

class MotionCapture 
{
 protected:

	 MPU6050 accelgyro;
 public:

	void initialize(void);
	void getAcceleration(float* x, float* y, float* z);
	float getAccelerationSVM();
	
};


#endif


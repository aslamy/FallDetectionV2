// 
// 
// 

#include "MotionCapture.h"



void MotionCapture::initialize(void)
{
	Wire.begin();
	accelgyro.initialize();
	accelgyro.setFullScaleAccelRange(MPU6050_ACCEL_FS_4);
	accelgyro.setAccelerometerPowerOnDelay(3);
	accelgyro.setIntZeroMotionEnabled(false);
	accelgyro.setIntMotionEnabled(true);
	//accelgyro.setDHPFMode(1);
	accelgyro.setMotionDetectionThreshold(60);
	accelgyro.setMotionDetectionDuration(40);

}


void MotionCapture::getAcceleration(float* x, float* y, float* z)
{
	int16_t ax, ay, az;
	accelgyro.getAcceleration(&ax, &ay, &az);
	*x = ax / 8192.;
	*y = ay / 8192.;
	*z = az / 8192.;
}

float MotionCapture::getAccelerationSVM()
{
	float ax, ay, az;
	getAcceleration(&ax, &ay, &az);
	return sqrt(float(pow(ax, 2) + pow(ay, 2) + pow(az, 2)));
};
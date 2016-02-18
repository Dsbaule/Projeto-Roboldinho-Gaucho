/*
 * LightSensor.h
 *
 * Created: 18-Feb-16 2:51:23 PM
 *  Author: Dsbaule
 */ 


#ifndef LIGHTSENSOR_H_
#define LIGHTSENSOR_H_

#include "LS/LS_defines.h"
#include "LS/LS_ATmega328.h"
#include <util/atomic.h>

#define LIGHT_SENSOR_PIN ADC5

int LightSensorValue;

void lightSensorCfg();
void getLightSensorValue();


#endif /* LIGHTSENSOR_H_ */
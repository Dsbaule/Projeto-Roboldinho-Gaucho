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

#define LIGHT_SENSOR_BORDER 1100

int LightSensorValue;

void lightSensorCfg();
int getLightSensorValue();
int getLightSensorColor();

ISR(ADC_vect);

#endif /* LIGHTSENSOR_H_ */
/*
 * LightSensor.c
 *
 * Created: 18-Feb-16 2:51:40 PM
 *  Author: Dsbaule
 */ 

#include "LightSensor.h"

void lightSensorCfg()
{
	// Configuração do Timer1
	timer1CTCMode();
	timer1ClockPrescaller1024();
	timer1SetCompareAValue(124);
	timer1SetCompareBValue(124);
	timer1DeactivateOverflowInterrupt();
	timer1DeactivateCompareAInterrupt();
	timer1DeactivateCompareBInterrupt();
	
	// Configuração do ADC
	adcReferenceInternal();
	adcClockPrescaler128();
	adcEnableAutomaticMode();
	adcTriggerTimer1CompareMatchB();
	adcSelectChannel(ADC5);
	adcActivateInterrupt();
	adcResultLeftAdjust();
	adcEnable();
	
	LightSensorValue = 0;
}

int getLightSensorValue()
{
	return LightSensorValue;
}

int getLightSensorColor()
{
	if(LightSensorValue > LIGHT_SENSOR_BORDER)
		return 0;
	else
		return 1;
}


ISR(ADC_vect)
{
	LightSensorValue = ADC;
	
	timer1ClearCompareBInterruptRequest();
	adcClearInterruptRequest();
}

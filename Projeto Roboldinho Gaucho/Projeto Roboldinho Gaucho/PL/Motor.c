/*
 * CFile1.c
 *
 * Created: 17/12/2015 14:16:35
 *  Author: Aluno
 */ 

#include "Motor.h"

void motorCtrlCfg(volatile uint8 *motorDDR, volatile uint8 *motorPort, uint8 motorSentido1, uint8 motorPWM1, uint8 motorSentido2, uint8 motorPWM2)
{
	setBit(*motorDDR, motorPWM1);
	setBit(*motorDDR, motorPWM2);
	setBit(*motorDDR, motorSentido1);
	setBit(*motorDDR, motorSentido2);
	
	clrBit(*motorPort, motorPWM1);
	clrBit(*motorPort, motorPWM2);
	clrBit(*motorPort, motorSentido1);
	clrBit(*motorPort, motorSentido2);
}

void motorDataCfg(volatile uint8 *motorDDR, volatile uint8 *motorPort,uint8 motor1Encoder0,uint8 motor1Encoder1,uint8 motor2Encoder0,uint8 motor2Encoder2)
{
	clrBit(*motorDDR, motor1Encoder0);
	clrBit(*motorDDR, motor1Encoder1);
	clrBit(*motorDDR, motor2Encoder0);
	clrBit(*motorDDR, motor2Encoder2);
	
	clrBit(*motorPort, motor1Encoder0);
	clrBit(*motorPort, motor1Encoder1);
	clrBit(*motorPort, motor2Encoder0);
	clrBit(*motorPort, motor2Encoder2);
}
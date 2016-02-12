/*
 * CFile1.c
 *
 * Created: 17/12/2015 14:16:35
 *  Author: Aluno
 */ 

#include "Motor.h"

void motorCfg()
{
	// Configuração dos motores
	motorCtrlCfg();
	motorDataCfg();
	
	// Configuração do Timer0 - ~1kHz
	timer0FastPWMMaxMode();
	timer0ClockPrescaller64();
	timer0OC0ANonInvertedMode();
	timer0OC0BNonInvertedMode();
	timer0SetCompareAValue(0);
	timer0SetCompareBValue(0);
	timer0DeactivateCompareAInterrupt();
	timer0DeactivateCompareBInterrupt();
	timer0ActivateOverflowInterrupt();
	
	
	//timeSinceStart = 0;
	motor1Info.timeSinceRead = 0;
	motor2Info.timeSinceRead = 0;
	
	motor1Info.anguloAtual = 0;
	motor2Info.anguloAtual = 0;
	
}

void motorCtrlCfg()
{
	setBit(MOTOR_CONTROL_DDR, MOTOR1_CONTROL_PWM_PIN);
	setBit(MOTOR_CONTROL_DDR, MOTOR2_CONTROL_PWM_PIN);
	setBit(MOTOR_CONTROL_DDR, MOTOR1_CONTROL_SENTIDO_PIN);
	setBit(MOTOR_CONTROL_DDR, MOTOR2_CONTROL_SENTIDO_PIN);
	
	clrBit(MOTOR_CONTROL_PORT, MOTOR1_CONTROL_PWM_PIN);
	clrBit(MOTOR_CONTROL_PORT, MOTOR2_CONTROL_PWM_PIN);
	clrBit(MOTOR_CONTROL_PORT, MOTOR1_CONTROL_SENTIDO_PIN);
	clrBit(MOTOR_CONTROL_PORT, MOTOR2_CONTROL_SENTIDO_PIN);
}

void motorDataCfg()
{
	clrBit(MOTOR_DATA_DDR, MOTOR1_DATA_E0_PIN);
	clrBit(MOTOR_DATA_DDR, MOTOR1_DATA_E1_PIN);
	clrBit(MOTOR_DATA_DDR, MOTOR2_DATA_E0_PIN);
	clrBit(MOTOR_DATA_DDR, MOTOR2_DATA_E1_PIN);
	
	clrBit(MOTOR_DATA_PORT, MOTOR1_DATA_E0_PIN);
	clrBit(MOTOR_DATA_PORT, MOTOR1_DATA_E1_PIN);
	clrBit(MOTOR_DATA_PORT, MOTOR2_DATA_E0_PIN);
	clrBit(MOTOR_DATA_PORT, MOTOR2_DATA_E1_PIN);
}

void setMotor1Speed(int Speed)
{
	if((Speed >= 0) && (Speed <= 255))
	{
		clrBit(MOTOR_CONTROL_PORT, MOTOR1_CONTROL_SENTIDO_PIN);
		timer0SetCompareBValue(Speed);
	}
	
	if((Speed < 0) && (Speed >= -255))
	{
		setBit(MOTOR_CONTROL_PORT, MOTOR1_CONTROL_SENTIDO_PIN);
		timer0SetCompareBValue(255 + Speed);
	}
}

void setMotor2Speed(int Speed)
{
	if((Speed >= 0) && (Speed <= 255))
	{
		clrBit(MOTOR_CONTROL_PORT, MOTOR2_CONTROL_SENTIDO_PIN);
		timer0SetCompareAValue(Speed);
	}
	
	if((Speed < 0) && (Speed >= -255))
	{
		setBit(MOTOR_CONTROL_PORT, MOTOR2_CONTROL_SENTIDO_PIN);
		timer0SetCompareAValue(255 + Speed);
	}
}

void calcSpeedMotor1()
{		
	
}

void calcSpeedMotor2()
{
	
}

ISR(PCINT1_vect)
{
	if(motor1Info.enc0Atual != isBitSet(MOTOR_DATA_PIN, MOTOR1_DATA_E0_PIN))
	{
		motor1Info.enc0Anterior = motor1Info.enc0Atual;
		motor1Info.enc0Atual = isBitSet(MOTOR_DATA_PIN, MOTOR1_DATA_E0_PIN);
		
		calcSpeedMotor1();
	}
	
	if(motor1Info.enc1Atual != isBitSet(MOTOR_DATA_PIN, MOTOR1_DATA_E1_PIN))
	{
		motor1Info.enc1Anterior = motor1Info.enc1Atual;
		motor1Info.enc1Atual = isBitSet(MOTOR_DATA_PIN, MOTOR1_DATA_E1_PIN);
		
		calcSpeedMotor1();
	}
	
	if(motor2Info.enc0Atual != isBitSet(MOTOR_DATA_PIN, MOTOR2_DATA_E0_PIN))
	{
		motor2Info.enc0Anterior = motor2Info.enc0Atual;
		motor2Info.enc0Atual = isBitSet(MOTOR_DATA_PIN, MOTOR2_DATA_E0_PIN);
		
		calcSpeedMotor2();
	}
	
	if(motor2Info.enc1Atual != isBitSet(MOTOR_DATA_PIN, MOTOR2_DATA_E1_PIN))
	{
		motor2Info.enc1Anterior = motor2Info.enc1Atual;
		motor2Info.enc1Atual = isBitSet(MOTOR_DATA_PIN, MOTOR2_DATA_E1_PIN);
		
		calcSpeedMotor2();
	}
}


ISR(TIMER0_OVF_vect)
{
	timeSinceStart++;
}
/*
 * Motor.h
 *
 * Created: 17/12/2015 14:16:22
 * Author: 	Daniel de Souza, Daniel Scariot Guterres & Pedro Ruschel Bressan
 * Projeto:	Biblioteca para utilização de Motores no projeto Roboldinho Gaucho
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#include "LS/LS_defines.h"
#include "LS/LS_ATmega328.h"


// Definições para os Motores
#define	MOTOR_CONTROL_DDR	DDRD
#define	MOTOR_CONTROL_PORT	PORTD
#define	MOTOR_CONTROL_PIN	PIND

#define MOTOR1_CONTROL_SENTIDO_PIN	PD3
#define MOTOR2_CONTROL_SENTIDO_PIN	PD4
#define MOTOR1_CONTROL_PWM_PIN	PD5
#define MOTOR2_CONTROL_PWM_PIN	PD6

#define	MOTOR_DATA_DDR	DDRC
#define	MOTOR_DATA_PORT	PORTC
#define	MOTOR_DATA_PIN	PINC

#define MOTOR1_DATA_E0_PIN	PC0
#define MOTOR1_DATA_E1_PIN	PC1
#define MOTOR2_DATA_E0_PIN	PC2
#define MOTOR2_DATA_E1_PIN	PC4


typedef struct motorInfo
{
	uint16	anguloAtual;
	
	uint8	enc0Anterior;
	uint8	enc0Atual;
	uint8	enc1Anterior;
	uint8	enc1Atual;
	
	uint8	direcao;
	uint8	velocidade;

	unsigned long timeSinceRead;
}motorInfo;

struct motorInfo motor1Info;
struct motorInfo motor2Info;

volatile int timeSinceStart;

// FUNÇÕES

void motorCfg();
void motorCtrlCfg();
void motorDataCfg();

void setMotor1Speed(int Speed);
void setMotor2Speed(int Speed);

void calcSpeedMotor1();
void calcSpeedMotor2();

ISR(PCINT1_vect);
ISR(TIMER0_OVF_vect);

#endif /* INCFILE1_H_ */
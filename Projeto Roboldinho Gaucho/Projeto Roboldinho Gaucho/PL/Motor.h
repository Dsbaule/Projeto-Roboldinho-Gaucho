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


typedef struct motorInfo
{
	uint16	anguloAtual;
	
	uint8	enc0Anterior;
	uint8	enc0Atual;
	uint8	enc1Anterior;
	uint8	enc1Atual;
	
	uint8	direcao;
	uint8	velocidade;		
}motorInfo;

void motorCtrlCfg(volatile uint8 *motorDDR, volatile uint8 *motorPort, uint8 motorSentido1, uint8 motorPWM1, uint8 motorSentido2, uint8 motorPWM2);
void motorDataCfg(volatile uint8 *motorDDR, volatile uint8 *motorPort,uint8 motor1Encoder0,uint8 motor1Encoder1,uint8 motor2Encoder0,uint8 motor2Encoder2);



#endif /* INCFILE1_H_ */
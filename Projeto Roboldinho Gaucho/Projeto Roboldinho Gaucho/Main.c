/*
 * Projeto_Roboldinho_Gaucho.c
 *
 * Created: 17/12/2015 13:59:54
 *  Author: Aluno
 */ 

// Inclusão das Bibliotecas LS
#include "PL/LS/LS_defines.h"
#include "PL/LS/LS_ATmega328.h"
#include "PL/LS/LS_HD44780.h"

// Inclusão das Bibliotecas do Projeto
#include "PL/Motor.h"

// Definições para o HC-SR04
#define	HCSR04_DDR	DDRD
#define	HCSR04_PORT	PORTD
#define	HCSR04_PIN	PIND

#define	HCSR04_TRIGGER_PIN	PD1
#define	HCSR04_ECHO_PIN		PD2

// Definições para o nRF24L01
#define	RF24_DDR	DDRD
#define	RF24_PORT	PORTD
#define	RF24_PIN	PIND

#define RF24_CE_PIN		PB2
#define RF24_MOSI_PIN	PB3
#define RF24_MISO_PIN	PB4
#define RF24_CLK_PIN	PB5

// Definições para os Motores
#define	MOTOR_CONTROL_DDR	DDRD
#define	MOTOR_CONTROL_PORT	PORTD
#define	MOTOR_CONTROL_PIN	PIND

#define MOTOR1_CONTROL_PWM_PIN	PD5
#define MOTOR2_CONTROL_PWM_PIN	PD6

#define	MOTOR_DATA_DDR	DDRC
#define	MOTOR_DATA_PORT	PORTC
#define	MOTOR_DATA_PIN	PINC

#define MOTOR1_DATA_E0_PIN	PC0
#define MOTOR1_DATA_E1_PIN	PC1
#define MOTOR2_DATA_E0_PIN	PC2
#define MOTOR2_DATA_E1_PIN	PC4

// Definições Gerais

// Definição das Variaveis Globais
struct motorInfo motor1Info;
struct motorInfo motor2Info;

int main(void)
{
	// Configuração dos motores
	motorCtrlCfg(MOTOR_CONTROL_DDR, MOTOR_CONTROL_PORT, MOTOR1_CONTROL_PWM_PIN, MOTOR2_CONTROL_PWM_PIN);
	motorDataCfg(MOTOR_CONTROL_DDR, MOTOR_CONTROL_PORT, MOTOR1_DATA_E0_PIN, MOTOR1_DATA_E1_PIN, MOTOR2_DATA_E0_PIN, MOTOR2_DATA_E1_PIN);
	
	// Configuração do Timer0 - 1kHz
	timer0FastPWMMaxMode();
	timer0SetCompareAValue(0);
	timer0SetCompareBValue(0);
	
	// Configuração do Timer1
	
	// Configuração do Timer2
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}
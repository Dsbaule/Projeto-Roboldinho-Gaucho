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

// Inclusão das Bibliotecas do ATMEGA
#include <avr/io.h>
#include <util/delay.h>
#include <util/atomic.h>

// Inclusão das Bibliotecas do Projeto
#include "PL/Motor.h"
#include "PL/LightSensor.h"

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


// Definições Gerais
//#define ADC_ADC4	0
//#define ADC_ADC5	1

// Definição das Variaveis Globais
struct motorInfo motor1Info;
struct motorInfo motor2Info;

//volatile uint8 curADC = ADC_ADC4;

//Variáveis para leitura dos potenciometros TESTE
volatile int VelocidadeX = 0;
volatile int VelocidadeY = 0;
volatile int Color = 0;


int speed = 0;

ISR(ADC_vect);

int main(void)
{
	// Configuração da comunicação USART
	usartEnableTransmitter();
	usartStdio();
	usartInit(9600);
	
	// Configuração das Interrupções
	sei();
	
	// Configuração dos motores
	motorCfg();
	
	// Configuração do sensor de luz
	lightSensorCfg();
	
    while(1)
	{
		
		while(getLightSensorColor() == 0)
		{
			setMotor1Speed(50);
			setMotor2Speed(-50);
			printf("Cor: %d - %d\n", getLightSensorColor(), getLightSensorValue());
			_delay_ms(100);
		}
		while(getLightSensorColor() == 1)
		{
			setMotor1Speed(255);
			setMotor2Speed(255);
			printf("Cor: %d - %d\n", getLightSensorColor(), getLightSensorValue());
			_delay_ms(100);
		}
		
		
		/*
		_delay_ms(100);
		setMotor1Speed(30);
		printf("Cor = %d\n", getLightSensorColor());
		*/
    }
}

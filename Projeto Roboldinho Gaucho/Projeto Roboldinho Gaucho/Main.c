/*
 * Projeto_Roboldinho_Gaucho.c
 *
 * Created: 17/12/2015 13:59:54
 *  Author: Aluno
 */ 

// Inclus�o das Bibliotecas LS
#include "PL/LS/LS_defines.h"
#include "PL/LS/LS_ATmega328.h"
#include "PL/LS/LS_HD44780.h"

// Inclus�o das Bibliotecas do ATMEGA
#include <avr/io.h>
#include <util/delay.h>
#include <util/atomic.h>

// Inclus�o das Bibliotecas do Projeto
#include "PL/Motor.h"

// Defini��es para o HC-SR04
#define	HCSR04_DDR	DDRD
#define	HCSR04_PORT	PORTD
#define	HCSR04_PIN	PIND

#define	HCSR04_TRIGGER_PIN	PD1
#define	HCSR04_ECHO_PIN		PD2

// Defini��es para o nRF24L01
#define	RF24_DDR	DDRD
#define	RF24_PORT	PORTD
#define	RF24_PIN	PIND

#define RF24_CE_PIN		PB2
#define RF24_MOSI_PIN	PB3
#define RF24_MISO_PIN	PB4
#define RF24_CLK_PIN	PB5


// Defini��es Gerais
#define ADC_ADC4	0
#define ADC_ADC5	1

// Defini��o das Variaveis Globais
struct motorInfo motor1Info;
struct motorInfo motor2Info;

volatile uint8 curADC = ADC_ADC4;

//Vari�veis para leitura dos potenciometros TESTE
volatile int VelocidadeX = 0;
volatile int VelocidadeY = 0;

int speed = 0;

ISR(ADC_vect);

int main(void)
{
	//EU QUE FIZ AE AE
	usartEnableTransmitter();
	usartStdio();
	usartInit(9600);
	
	// Configura��o dos motores
	motorCfg();
	
	//ADC CONFIG
	adcReferenceAvcc();
	adcClockPrescaler128();
	adcEnableAutomaticMode();
	adcTriggerTimer1Overflow();
	adcSelectChannel(ADC4);
	adcActivateInterrupt();
	adcEnable();
	
	adcDisableAutomaticMode();
	adcDeactivateInterrupt();
	adcDisable();
	
	// Configura��o do Timer1
	timer1CTCMode();
	timer1ClockPrescaller1024();
	timer1SetCompareAValue(135);
	timer1DeactivateCompareAInterrupt();
	timer1ActivateOverflowInterrupt();
	
	timer1DeactivateOverflowInterrupt();
	
	// Configura��o do Timer2
	
	sei();
	
    while(1)
	{
		//_delay_ms(1);
		setMotor1Speed(30);
		
		/*
		ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
		{
			printf("Velocidade1 = %d    -    Velocidade2 = %d   -   %d\r", motor1Info.direcao, motor2Info.direcao, timeSinceStart);
		}
		*/
		
    }
}

ISR(ADC_vect)
{
	VelocidadeX++;
	if(curADC == ADC_ADC4)
	{
		VelocidadeX = ADC;
		adcSelectChannel(ADC5);
		curADC = ADC_ADC5;
	}
	else if(curADC == ADC_ADC5)
	{
		VelocidadeX = ADC;	
		adcSelectChannel(ADC4);
		curADC = ADC_ADC4;
	}
	
	printf("FUDEU FUDEU FUDEU \r");
	
	timer1ClearOverflowInterruptRequest();
	adcClearInterruptRequest();
}


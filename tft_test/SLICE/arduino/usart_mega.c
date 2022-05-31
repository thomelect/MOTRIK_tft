/**
@file 		usart.c
@brief 		Librairie que permet de maitriser l'envoie et la réception de données à l'aide du protocole de communication USART. le baud rate et la taille du buffer de reception et de transmission sont réglable dans le fichier .h
@author 	Thomas Desrosiers
@version 	2.0
@date 		2019/11/28
*/
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "usart_mega.h"

// declaration des variables nécessaires à la transmission (txBuffer prend la taille de TX_BUFFER_SIZE, txBufferIn et txBufferOut)
volatile uint8_t txBuffer[TX_BUFFER_SIZE];
uint8_t txBufferIn = 0;
volatile uint8_t txBufferOut = 0;
// declaration des variables nécessaires à la reception (rxBuffer prend la taille de RX_BUFFER_SIZE, rxBufferIn et rxBufferOut)
volatile uint8_t rxBuffer[RX_BUFFER_SIZE];
uint8_t rxBufferIn = 0;
volatile uint8_t rxBufferOut = 0;


uint8_t compteur = 0;
uint8_t txCnt = 0;
uint8_t compteurDispo = 0;

/**
@brief fonction qui permet d'initialiser la communication usart en activant TXEN1 (TRANSMISSION) ET RXEN1 (RECEPTION) du registre UCSR1B
@param baudRate designe la vitesse de communication en baud
@param fcpu designe la fréquence du core
@return void
*/
void usartInit(uint32_t baudRate, uint32_t fcpu)
{
	UCSR1B = ((1<<RXEN1) | (1<<TXEN1)); // ACTIVE RX ET TX
	//UBRR0H = ((((fcpu >> 4) / baudRate) - 0.5) >> 8); //RÈGLE LA VITESSE À 500k BAUDS
	UBRR1H = (BAUD_PRESCALE(fcpu,baudRate) >> 8); //RÈGLE LA VITESSE À 500k BAUDS
	UBRR1L = ((fcpu >> 4) / baudRate - 0.5);
	UCSR1C = (1<<UCSZ10)|(1<<UCSZ11);
	sei();
	UCSR1B |= (1<<RXCIE1);
}

/**
@brief retire la plus ancienne donnée dans le buffer de reception et la retourne
@return rxData est la plus ancienne donnée
*/
uint8_t usartRemRxData()
{
	uint8_t rxData = 0;
	if (rxBufferIn != rxBufferOut)
	{
		compteurDispo--;
		rxData = rxBuffer[rxBufferOut++];
		if (rxBufferOut >= RX_BUFFER_SIZE)
		rxBufferOut = 0;
	}
	return rxData;
}

/**
@brief fonction qui retourne la valeur du compteur qui est incrémenté lorsqu'une donnée est placée dans le buffer de reception et décrémenté lorsqu'un octet en est retiré
@return uint8_t
*/
uint8_t usartRxAvailable()
{
	return compteurDispo;
}

/**
@brief fonction qui place un byte à la fois dans un buffer avant d'envoyer ce même byte se faire envoyé en interuption
@param byteSend
@return uint8_t 1 si le buffer était plein et 0 si tou ses bien déroulé.
*/
uint8_t usartSendByte(uint8_t byteSend)
{
	if(txCnt >= TX_BUFFER_SIZE)
	return 1;
	txCnt++;
	txBuffer[txBufferIn++] = byteSend;
	if(txBufferIn >= TX_BUFFER_SIZE)
	{
		txBufferIn = 0;
	}
	UCSR1B |= (1<<UDRIE1);
	return 0;
}

/**
@brief fonction qui envoie un tableau d'octet en envoyant un octet à la fois dans usartSendByte
@param tableIn tableau d'octect
@param size nombre de données du tableau à transmettre
@return uint8_t compteur indique le nombre de données transmise
*/
uint8_t usartSendBytes(const uint8_t * tableIn, uint8_t size)
{
	for(uint8_t i = 0; i < size; i++)
	{
		if(usartSendByte(tableIn[i]))
		return i;
	}
	return size;
}

/**
@brief fonction qui envoie une string
@param str chaine de caractère à envoyer
@return uint8_t compteur indique le nombre de caractère transmis
*/
uint8_t usartSendString(const char * str)
{
	compteur = 0;
	for(uint8_t i = 0; str[i]; i++)
	{
		if(usartSendByte(str[i]))
		return i;
		compteur++;
	}
	return compteur;
}

//interruption qui est active lorsque demandé par l'une des fonctions plus bas, afin de libérer le micro controlleur de la tâche que représente la transmission
ISR(USART_UDRE_vect)
{
	if(txBufferIn==txBufferOut)
	{
		UCSR1B &= ~(1<<UDRIE1);
	}
	else
	{
		txCnt--;
		UDR1 = txBuffer[txBufferOut++];
		if (txBufferOut >= TX_BUFFER_SIZE)
		{
			txBufferOut = 0;
		}
	}
}
//interruption qui est toujours active afin de déterminer si un caractère est reçu
ISR(USART_RX_vect)
{
	compteurDispo++;
	rxBuffer[rxBufferIn++] = UDR1;
	if (rxBufferIn >= RX_BUFFER_SIZE)
	rxBufferIn = 0;
}
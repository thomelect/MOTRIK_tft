/*
 * usart_uno.h
 *
 * Created: 29/déc./2019 16:56:33
 *  Author: Thomas
 */ 


#ifndef USART_MEGA_H_
#define USART_MEGA_H_

#define TX_BUFFER_SIZE 64
#define RX_BUFFER_SIZE 64
#define BAUD_PRESCALE(fcpu,br) ((fcpu / 16 / br) - 1)

/**
@brief fonction qui permet d'initialiser la communication usart en activant TXEN1 (TRANSMISSION) ET RXEN1 (RECEPTION) du registre UCSR1B
@param baudRate designe la vitesse de communication en baud
@param fcpu designe la fréquence du core
@return void
*/
void usartInit(uint32_t baudRate, uint32_t fcpu);

/**
@brief retire la plus ancienne donnée dans le buffer de reception et la retourne
@return rxData est la plus ancienne donnée
*/
uint8_t usartRemRxData();

/**
@brief fonction qui retourne la valeur du compteur qui est incrémenté lorsqu'une donnée est placée dans le buffer de reception et décrémenté lorsqu'un octet en est retiré
@return uint8_t
*/
uint8_t usartRxAvailable();

/**
@brief fonction qui place un byte à la fois dans un buffer avant d'envoyer ce même byte se faire envoyé en interuption
@param byteSend
@return uint8_t 1 si le buffer était plein et 0 si tou ses bien déroulé.
*/
uint8_t usartSendByte(uint8_t byteSend);

/**
@brief fonction qui envoie un tableau d'octet en envoyant un octet à la fois dans usartSendByte
@param tableIn tableau d'octect
@param size nombre de données du tableau à transmettre
@return uint8_t compteur indique le nombre de données transmise
*/
uint8_t usartSendBytes(const uint8_t * tableIn, uint8_t size);

/**
@brief fonction qui envoie une string
@param str chaine de caractère à envoyer
@return uint8_t compteur indique le nombre de caractère transmis
*/
uint8_t usartSendString(const char * str);

#endif /* USART_MEGA_H_ */
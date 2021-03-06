#include "DIO_interface.h"
#include "Std_Types.h"
#include "Macros.h"
#include "UART_interface.h"
#include <avr/io.h>

void UART_vidInit(void) {
	SET_BIT(UCSRB,4); //RxEN
	SET_BIT(UCSRB,3); //TxEN

	SET_BIT(UCSRC,2);
	SET_BIT(UCSRC,1);
	CLEAR_BIT(UCSRB,2);
	UBRRH = 0;
	UBRRL = 51;
}

void UART_vidSendByte(u8 u8byteCpy) {
	while(GET_BIT(UCSRA,5) == 0); //Data register empty
	UDR = u8byteCpy;
}

u8 UART_vidReceiveByte(void) {
	while(GET_BIT(UCSRA,7) == 0); //Checking the Receive Complete registe RxC bit
	return UDR;
}

void UART_vidSendString(u8 * u8stringCpy) {
	do {
		UART_vidSendByte(*u8stringCpy);
	}while(*u8stringCpy++ != '\0');
}

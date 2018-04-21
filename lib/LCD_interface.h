/*
 * Author: Mohamed Ahmed Abd Al-Fattah
 */

#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H

#define LCD_DATA_PORT DIO_PORTD
#define LCD_CTRL_PORT DIO_PORTA

#define LCD_D0 0
#define LCD_D1 1
#define LCD_D2 2
#define LCD_D3 3
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7

#define LCD_8MODE_2L 0x38
#define LCD_ON_NOCURSOR 0x0C
#define LCD_CLEAR_SCREEN 0b00000001
#define LCD_RETURN_HOME 0b00000010

#define LCD_ENTRY_MODE 0b00000110
#define LCD_DISPLAY_CONTROL 0b00001100
#define LCD_FUNCTION_SET 0b00111000


#define LCD_MOVE_CURSOR_LEFT 0x14

#define LCD_E 2
#define LCD_RW 1
#define LCD_RS 0

void LCD_vidInit(void);
void LCD_vidSendCommand(u8);
void LCD_vidWriteCharacter(u8);
void LCD_vidWriteString(s8*);
void LCD_vidBlinkString(s8*,u8);
void LCD_vidWriteSizedString(s8*,u8);
void LCD_vidGoToXY(s8,s8);
void LCD_vidWriteNumber(u16);
void LCD_vidCreateCustomChar(u8 *,u8);
void LCD_vidWriteCustomChar(u8);


/******Custom Characters*****/
#define LCD_CHAR_UPARROW {0x04,	0x0E, 0x1F, 0x04, 0x04,	0x04, 0x04, 0x04}
#define LCD_CHAR_DOWNARROW {0x04, 0x04, 0x04, 0x04, 0x04, 0x1F, 0x0E, 0x04}

#define LCD_CUSTOMCHAR_LOCATION_0 0
#define LCD_CUSTOMCHAR_LOCATION_1 1
#define LCD_CUSTOMCHAR_LOCATION_2 2
#define LCD_CUSTOMCHAR_LOCATION_3 3
#define LCD_CUSTOMCHAR_LOCATION_4 4
#define LCD_CUSTOMCHAR_LOCATION_5 5
#define LCD_CUSTOMCHAR_LOCATION_6 6
#define LCD_CUSTOMCHAR_LOCATION_7 7
#endif

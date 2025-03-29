#ifndef __LCD1602_H__
#define __LCD1602_H__

void LCD_setcursor(unsigned char x,unsigned char y);
void LCD_init();
void LCD_showchar(unsigned char x,unsigned char y,unsigned char val);
void LCD_showstring(unsigned char x,unsigned char y,unsigned char* val);
void LCD_shownum(unsigned char x,unsigned char y,unsigned int val,unsigned char len);
void LCD_showsignednum(unsigned char x,unsigned char y,int val,unsigned char len);
void LCD_showhex(unsigned char x,unsigned char y,unsigned char val);
	
#endif
#include <REGX52.H>
#include "MatrixLED.h"

unsigned char i;
unsigned char k;
unsigned char Animation[]={0xFF,0x10,0x10,0x10,0xFF,0x00,0x00,0x0E,0x15,0x15,0x0C,0x00,0x00,0x00,0xFF,0x01,
0x02,0x00,0x00,0xFF,0x01,0x02,0x00,0x00,0x0E,0x11,0x11,0x11,0x0E,0x00,0x00,0xFD};

void main()
{
	MatrixLED_init();
	for(i=1;i<=25;i++)
	{
		k=0;
		while(k<8)
		{
			MatrixLED_showcolumn(1,Animation[i-1]);
			MatrixLED_showcolumn(2,Animation[i]);
			MatrixLED_showcolumn(3,Animation[i+1]);
			MatrixLED_showcolumn(4,Animation[i+2]);
			MatrixLED_showcolumn(5,Animation[i+3]);
			MatrixLED_showcolumn(6,Animation[i+4]);
			MatrixLED_showcolumn(7,Animation[i+5]);
			MatrixLED_showcolumn(8,Animation[i+6]);
			k++;
		}
		if(i==25)
			i=0;
	}
}
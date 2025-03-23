#include "Nixie.h"
#include <REGX52.H>

unsigned char Nixienum[8];
unsigned char i=0;

void setbuf(unsigned char location,unsigned char number)
{
	Nixienum[location-1]=number;
}

void Nixie(unsigned char location,unsigned char number)
{
	switch(location)
	{
		case 1:P2_2=1;P2_3=1;P2_4=1;break;
		case 5:P2_2=1;P2_3=1;P2_4=0;break;
		case 3:P2_2=1;P2_3=0;P2_4=1;break;
		case 7:P2_2=1;P2_3=0;P2_4=0;break;
		case 2:P2_2=0;P2_3=1;P2_4=1;break;
		case 6:P2_2=0;P2_3=1;P2_4=0;break;
		case 4:P2_2=0;P2_3=0;P2_4=1;break;
		case 8:P2_2=0;P2_3=0;P2_4=0;break;
	}
	switch(number)
	{
		case 0:P0=0x3F;break;
		case 1:P0=0x06;break;
		case 2:P0=0x5B;break;
		case 3:P0=0x4F;break;
		case 4:P0=0x66;break;
		case 5:P0=0x6D;break;
		case 6:P0=0x7D;break;
		case 7:P0=0x07;break;
		case 8:P0=0x7F;break;
		case 9:P0=0x6F;break;
		case 11:P0=0x40;break;
	}
}

void Nixie_Loop()
{
	Nixie(i+1,Nixienum[i]);
	i++;
	if(i>7)i=0;
}
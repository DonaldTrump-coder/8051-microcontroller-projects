#include <REGX52.H>
#include "Key/Key.h"
#include "LCDtools/lcd1602.h"
#include "DS1302/DS1302.h"

unsigned char time[]={25,2,3,18,13,12,02};
unsigned char timegot[]={25,2,3,18,13,12,31};
bit Mode;

void Timeshow()//��ʾ��ǰʱ��
{
	Readtime(timegot);
	lcd1602_show_string(6,0,"20");
	lcd1602_show_unsigned_char_time(8,0,timegot[0]);
	lcd1602_show_string(10,0,"/");
	lcd1602_show_unsigned_char_time(11,0,timegot[2]);
	lcd1602_show_string(13,0,"/");
	lcd1602_show_unsigned_char_time(14,0,timegot[3]);
	lcd1602_show_unsigned_char_time(0,1,timegot[4]);
	lcd1602_show_string(2,1,":");
	lcd1602_show_unsigned_char_time(3,1,timegot[5]);
	lcd1602_show_string(5,1,":");
	lcd1602_show_unsigned_char_time(6,1,timegot[6]);
	if(timegot[1]==1)
		lcd1602_show_string(9,1,"Mon");
	if(timegot[1]==2)
		lcd1602_show_string(9,1,"Tues");
	if(timegot[1]==3)
		lcd1602_show_string(9,1,"Wed");
	if(timegot[1]==4)
		lcd1602_show_string(9,1,"THURS");
	if(timegot[1]==5)
		lcd1602_show_string(9,1,"FRI");
	if(timegot[1]==6)
		lcd1602_show_string(9,1,"SAT");
	if(timegot[1]==7)
		lcd1602_show_string(9,1,"SUN");
}

void staticTimeshow(unsigned char timeset,bit light)//��ʾʱ�䣬������ȡ��ֻ��ʾ��ǰtimegot�����е�����
{
	if(light==1||timeset!=5)//����˸������˸�Ŀɼ��׶�
	{
		lcd1602_show_string(6,0,"20");//��ݿ�ͷǰ��λ����
		lcd1602_show_unsigned_char_time(8,0,timegot[0]);//��ݵ������λ
	}
	lcd1602_show_string(10,0,"/");
	if(light==1||timeset!=4)
	{
		lcd1602_show_unsigned_char_time(11,0,timegot[2]);
	}
	lcd1602_show_string(13,0,"/");
	if(light==1||timeset!=3)
	{
		lcd1602_show_unsigned_char_time(14,0,timegot[3]);
	}
	if(light==1||timeset!=2)
	{
		lcd1602_show_unsigned_char_time(0,1,timegot[4]);
	}
	lcd1602_show_string(2,1,":");
	if(light==1||timeset!=1)
	{
		lcd1602_show_unsigned_char_time(3,1,timegot[5]);
	}
	lcd1602_show_string(5,1,":");
	if(light==1||timeset!=0)
	{
		lcd1602_show_unsigned_char_time(6,1,timegot[6]);
	}
	if(light==1||timeset!=6)
	{
		if(timegot[1]==1)
			lcd1602_show_string(9,1,"Mon");
		if(timegot[1]==2)
			lcd1602_show_string(9,1,"Tues");
		if(timegot[1]==3)
			lcd1602_show_string(9,1,"Wed");
		if(timegot[1]==4)
			lcd1602_show_string(9,1,"THURS");
		if(timegot[1]==5)
			lcd1602_show_string(9,1,"FRI");
		if(timegot[1]==6)
			lcd1602_show_string(9,1,"SAT");
		if(timegot[1]==7)
			lcd1602_show_string(9,1,"SUN");
	}
	if(light==0)//��˸�Ĳ���ʾ�׶�
	{
		if(timeset==0)
		{
			lcd1602_show_string(6,1,"  ");
		}
		else if(timeset==1)
		{
			lcd1602_show_string(3,1,"  ");
		}
		else if(timeset==2)
		{
			lcd1602_show_string(0,1,"  ");
		}
		else if(timeset==3)
		{
			lcd1602_show_string(14,0,"  ");
		}
		else if(timeset==4)
		{
			lcd1602_show_string(11,0,"  ");
		}
		else if(timeset==5)
		{
			lcd1602_show_string(6,0,"    ");
		}
		else if(timeset==6)
		{
			lcd1602_show_string(9,1,"     ");
		}
	}
}

void Timeset()//ʱ�����ù���
{
	unsigned char keynum,count,timeset=0;
	bit light=1;//�ж��Ƿ�����˸�׶�
	Readtime(timegot);//����ʱ������ģʽʱֻ���ʼ��ȡһ�ε�ǰʱ��
	while(1)
	{
		count++;
		if(count>4)//������˸��ʱ��������
		{
			count=0;
			light=~light;
		}
		staticTimeshow(timeset,light);//��̬��ʾ��˸ʱ�䣬�Ա�֤ʱ������״̬����ʾ��ʱ�䲻����ʱ��仯
		keynum=key();//������ȡģʽ
		if(keynum==1)//������ʱ����л�Ϊʱ����ʾģʽ
		{
			Mode=~Mode;
			Writetime(timegot);//�����õ�ʱ��ͬʱд�뵱ǰʱ��
			return;
		}
		if(keynum==2)//�ı���Ҫ�޸ĵĲ�ͬʱ�䵥λ
		{
			timeset++;
			if(timeset>6)timeset=0;
		}
		if(keynum==3)//ѡ�е�ʱ�䵥λ��һ
		{
			switch(timeset)
			{
				case 0:timegot[6]++;break;//��+1
				case 1:timegot[5]++;break;//��+1
				case 2:timegot[4]++;break;//ʱ+1
				case 3:timegot[3]++;break;//��+1
				case 4:timegot[2]++;break;//��+1
				case 5:timegot[0]++;break;//��+1
				case 6:timegot[1]++;break;//����+1
			}
			if(timegot[0]>99)timegot[0]=0;//���Խ���ж�
			if(timegot[1]>7)timegot[1]=1;//����Խ���ж�
			if(timegot[2]>12)timegot[2]=1;//�·�Խ���ж�
			
			if(timegot[2]==2&&timegot[0]%4==0)//�������2�¼���С���������Խ���ж�
			{
				if(timegot[3]>29)timegot[3]=1;
			}
			else if(timegot[2]==2)
			{
				if(timegot[3]>28)timegot[3]=1;
			}
			else if(timegot[2]==4||timegot[2]==6||timegot[2]==9||timegot[2]==11)
			{
				if(timegot[3]>30)timegot[3]=1;
			}
			else
			{
				if(timegot[3]>31)timegot[3]=1;
			}
			
			if(timegot[4]>23)timegot[4]=0;
			if(timegot[5]>59)timegot[5]=0;
			if(timegot[6]>59)timegot[6]=0;
		}
		if(keynum==4)//ѡ�е�ʱ�䵥λ��һ
		{
			if(timegot[0]==0)timegot[0]=100;
			
			if(timegot[4]==0)timegot[4]=24;
			if(timegot[5]==0)timegot[5]=60;
			if(timegot[6]==0)timegot[6]=60;
			
			switch(timeset)
			{
				case 0:timegot[6]--;break;//��-1
				case 1:timegot[5]--;break;//��-1
				case 2:timegot[4]--;break;//ʱ-1
				case 3:timegot[3]--;break;//��-1
				case 4:timegot[2]--;break;//��-1
				case 5:timegot[0]--;break;//��-1
				case 6:timegot[1]--;break;//����-1
			}
			if(timegot[1]==0)timegot[1]=7;
			if(timegot[2]==0)timegot[2]=12;
			
			if(timegot[2]==2&&timegot[0]%4==0)
			{
				if(timegot[3]==0)timegot[3]=29;
			}
			else if(timegot[2]==2)
			{
				if(timegot[3]==0)timegot[3]=28;
			}
			else if(timegot[2]==4||timegot[2]==6||timegot[2]==9||timegot[2]==11)
			{
				if(timegot[3]==0)timegot[3]=30;
			}
			else
			{
				if(timegot[3]==0)timegot[3]=31;
			}
		}
	}
}

void main()
{
	unsigned char keynum;
	DS1302_init();
	lcd1602_init();
	
	lcd1602_show_string(0,0,"Time:");
	Write(0x8E,0x00);//ȡ��д����
	Delay1ms();
	Writetime(time);//д��ָ����ʱ��
	Mode=0;//Ĭ��Ϊʱ����ʾģʽ
	while(1)
	{
		keynum=key();
		if(keynum==1)
		{
			Mode=~Mode;//�л�ģʽ
		}
		if(Mode==1)
		{
			Timeset();
		}
		else
		{
			Timeshow();
		}
	}
}
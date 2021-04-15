#include <STC15F2K60S2.H>
#include "iic.h"
#include "ds1302.h"
#define u8 unsigned char
#define u16 unsigned int

extern u8 shijian[];

u8 mod=0,shudumax=50,shudu,kai=0,fmq=0;
u8 yi,er,san,si,wu,liu,qi,ba;
u8 data tab[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90,0XBF,0XFF};
void Allinit();
void Delayms(u16);
void key4();
void display1(u8,u8);
void display2(u8,u8);
void display3(u8,u8);
void display4(u8,u8);

void main(){
	Allinit();
	ds1302_init();
	shudumax=EEPROM_read(0x10);
	yi=1;er=2;san=3;si=4;wu=5;liu=6;qi=7;ba=8;
	while(1){
		shudu=AD_get();
		ds1302_get();
		if(mod==0||mod==2){
			yi=shijian[2]/10;er=shijian[2]%10;san=10;
			si=shijian[1]/10;wu=shijian[1]%10;liu=11;
			qi=shudu/10;ba=shudu%10;
			if(mod==0){
				P2=0x80;P0=0xfe;
			}else if(mod==2){
				P2=0x80;P0=0xfd;
			}
			if(((shudu<shudumax)&&(mod==0))||(kai==1)){
				P2=0xa0;P0=0x10;
			}else{
				P2=0xa0;P0=0x00;
			}
			if((mod==2)&&(shudu<shudumax)&&(kai==0)){
					P2=0xa0;P0=0x40;
			}
		}else if(mod==1){
			yi=10;er=10;san=11;
			si=11;wu=11;liu=11;
			qi=shudumax/10;ba=shudumax%10;
		}
		key4();
		display1(yi,er);
		display2(san,si);
		display3(wu,liu);
		display4(qi,ba);
	}
}


void Allinit(){
	P2=0xa0;P0=0x00;P2=0xc0;P0=0xff;
	P2=0xe0;P0=0xff;P2=0x80;P0=0xff;
}
void Delayms(u16 ms){
	u16 i,j;
	for(i=0;i<ms;i++)
		for(j=845;j>0;j--);
}
void key4(){
	if(P30==0){
		Delayms(5);
		if(P30==0){//S7
			if(mod==0)mod=2;
			else if(mod==2)mod=0;
			while(!P30);
		}
	}
	if(P31==0){
		Delayms(5);
		if(P31==0){//S6
			if(mod==0)mod=1;
			else if(mod==1){mod=0,EEPROM_write(0x10,shudumax);};		
			while(!P31);
		}
	}
	if(P32==0){
		Delayms(5);
		if(P32==0){//S5
			if(mod==1){
				shudumax++;
				if(shudumax==100)shudumax=0;
			}else if(mod==2){
				kai=1;
			}			
			while(!P32);
		}
	}
	if(P33==0){
		Delayms(5);
		if(P33==0){//S4
			if(mod==1){
				if(shudumax==0)shudumax=99;
				else shudumax=shudumax-1;
			}else if(mod==2){
				kai=0;
			}			
			while(!P33);
		}
	}
}
void display1(u8 yi,u8 er){
	P2=0xc0;P0=0x01;P2=0xe0;P0=tab[yi];
	Delayms(1);
	P2=0xc0;P0=0x02;P2=0xe0;P0=tab[er];
	Delayms(1);
}
void display2(u8 san,u8 si){
	P2=0xc0;P0=0x04;P2=0xe0;P0=tab[san];
	Delayms(1);
	P2=0xc0;P0=0x08;P2=0xe0;P0=tab[si];
	Delayms(1);
}
void display3(u8 wu,u8 liu){
	P2=0xc0;P0=0x10;P2=0xe0;P0=tab[wu];
	Delayms(1);
	P2=0xc0;P0=0x20;P2=0xe0;P0=tab[liu];
	Delayms(1);	
}
void display4(u8 qi,u8 ba){
	P2=0xc0;P0=0x40;P2=0xe0;P0=tab[qi];
	Delayms(1);
	P2=0xc0;P0=0x80;P2=0xe0;P0=tab[ba];
	Delayms(1);	
}

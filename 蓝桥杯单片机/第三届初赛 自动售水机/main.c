#include <STC15F2K60S2.H>
#include "iic.h"
#define u8 unsigned char
#define u16 unsigned int

u8 yi,er,san,si,wu,liu,qi,ba;
u8 data tab[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xbf,0xff}; //0100 0000  
u8 data dot[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
u8 kais=0,q=0;//10ml单位 100ml/s
u16 tt=0,chus=0,guang=0;
void AllInit();
void Delayms(u16 ms);
void Key4();
void display1(u8,u8);
void display2(u8,u8);
void display3(u8,u8);
void display4(u8,u8);
void Timer0Init();

void main(){
	AllInit();
	Timer0Init();
	ET0=1;
	EA=1;
	while(1){	
		guang=AD_read();
		yi=11;er=0;san=5;si=0;
		if(kais==0){
			if(chus==9999){TR0=0;kais=1;}
			wu=chus/1000;liu=chus/100%10;qi=chus%100/10;ba=chus%10; 
		}else if(kais==1){
			wu=q/1000;liu=q/100%10;qi=q%100/10;ba=q%10;
		}else if(kais==2){  //测试光敏
			wu=11;liu=guang/100;qi=guang%100/10;ba=guang%10;
		}
		
		if(guang<25){P2=0x80;P0=0xfe;}
		else{P2=0x80;P0=0xff;}
		
		Key4();
		display1(yi,er);
		display2(san,si);
		display3(wu,liu);
		display4(qi,ba);
	}
}

void time0() interrupt 1{
		tt++;
		if(tt==20){
			tt=0;
			chus=chus+1;
		}
}

void AllInit(){
	P2=0xa0;P0=0x00;P2=0xc0;P0=0xff;
	P2=0xe0;P0=0xff;P2=0x80;P0=0xff;
}
void Delayms(u16 ms){
	u16 i,j;
	for(i=0;i<ms;i++)
		for(j=845;j>0;j--);
}
void Key4(){
	if(P30==0){
		Delayms(5);
		if(P30==0){					//S7
				kais=0;
				TR0=1;
				P2=0xa0;P0=0x10;
			while(!P30){
				display1(yi,er);
				display2(san,si);
				display3(wu,liu);
				display4(qi,ba);
			}
		}
	}
	
	if(P31==0){
		Delayms(5);
		if(P31==0){
				q=chus/2;
				chus=0;
				kais=1;					//S6
				TR0=0;
				P2=0xa0;P0=0x00;
			while(!P31);
		}
	}
	
	if(P32==0){
		Delayms(5);
		if(P32==0){
					kais=2;				//S5
			
			while(!P32);
		}
	}
	
	if(P33==0){
		Delayms(5);
		if(P33==0){
									//S4
			
			while(!P33);
		}
	}
}
void display1(u8 yi,u8 er){
	P2=0xc0;P0=0x01;P2=0xe0;P0=tab[yi];
	Delayms(1);
	P2=0xc0;P0=0x02;P2=0xe0;P0=dot[er];
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
	P2=0xc0;P0=0x20;P2=0xe0;P0=dot[liu];
	Delayms(1);
}
void display4(u8 qi,u8 ba){
	P2=0xc0;P0=0x40;P2=0xe0;P0=tab[qi];
	Delayms(1);
	P2=0xc0;P0=0x80;P2=0xe0;P0=tab[ba];
	Delayms(1);
}

void Timer0Init(void)		//5毫秒@11.0592MHz
{
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0x00;		//设置定时初值
	TH0 = 0x28;		//设置定时初值
	TF0 = 0;		//清除TF0标志
}

#include <STC15F2K60S2.H>
#include <iic.h>
#define u8 unsigned char
#define u16 unsigned char
	
u8 yi,er,san,si,wu,liu,qi,ba;
u8 data tab[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90,0XBF,0XFF};
u8 denj[]={40,50,120,100};
u8 mod=1,sz=0,biaoz=0;
void AllInit();
void Delayms(u16);
void key4();
void display1(u8,u8);
void display2(u8,u8);
void display3(u8,u8);
void display4(u8,u8);


void main(){
	AllInit();
	while(1){
		
		if(sz=1){
			yi=10;er=mod;san=10;si=11;
			if(denj[0]>=100){wu=1;liu=denj[mod-1]/10%10;}
			else {wu=11;liu=denj[mod-1]/10;}
			qi=denj[mod-1]%10;ba=0;
		}
		
		key4();
		display1(yi,er);
		display2(san,si);
		display3(wu,liu);
		display4(qi,ba);
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
void key4(){
	if(P30==0){
		Delayms(5);
		if(P30==0){
			//S7
			while(!P30);
		}
	}
	if(P31==0){
		Delayms(5);
		if(P31==0){
			//S6
			if(sz==0)sz=1;
			else if(sz==1&&biaoz==0)biaoz=1;
			else if(sz==1&&biaoz==1)biaoz=2;
			else if(sz==1&&biaoz==2){biaoz=0;sz=0;}
			while(!P31);
		}
	}
	if(P32==0){
		Delayms(5);
		if(P32==0){
			//S5
			if(sz==1){
				if(biaoz==1){
					if(mod==4)mod=1;
					else mod++;
				}else if(biaoz==2){
					if(denj[mod-1]==1200)denj[mod-1]=400;
					else denj[mod-1]=denj[mod-1]+100;
				}
			}
			while(!P32);
		}
	}
	if(P33==0){
		Delayms(5);
		if(P33==0){
			//S4
			if(sz==1){
				if(biaoz==1){
					if(mod==1)mod=4;
					else mod--;
				}else if(biaoz==2){
					if(denj[mod-1]==400)denj[mod-1]=1200;
					else denj[mod-1]=denj[mod-1]-100;
				}
			}
		}
		while(!P33);
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
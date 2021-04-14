#include <STC15F2K60S2.H>
#include "onewire.h"
#include "ds1302.h"
#define u8 unsigned char
#define u16 unsigned int
extern u8 shijian[];
u8 nz[]={0,0,0};
u8 tab[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90,0XBF,0XFF,0xc6};
u8 yi,er,san,si,wu,liu,qi,ba,wd;
u8 mod=0;//模式
u8 led=0,fla=0;
u16 tt=0,wus=0;
void AllInit();
void Delayms(u16 ms);
void key4();
void display1(u8 yi,u8 er);
void display2(u8 san,u8 si);
void display3(u8 wu,u8 liu);
void display4(u8 qi,u8 ba);
void Timer0Init(void);



void main(){
	AllInit();
	Timer0Init();
	ET0=1;EA=1;
	Ds1302Init();
	while(1){
		wd=ds_get();
		Ds1302get();
		if(mod==0){	
			san=10;liu=10;
			yi=shijian[2]/10;er=shijian[2]%10;
			si=shijian[1]/10;wu=shijian[1]%10;
			qi=shijian[0]/10;ba=shijian[0]%10;
			if((shijian[0]==nz[0])&&(shijian[1]==nz[1])&&(shijian[1]==nz[1])){
				led=1;tt=0;wus=0;
			}		
		}else if(mod==1){
			if(shijian[0]%2==0){
				san=10;liu=10;
				yi=shijian[2]/10;er=shijian[2]%10;
				si=shijian[1]/10;wu=shijian[1]%10;
				qi=shijian[0]/10;ba=shijian[0]%10;
			}else{
				san=10;liu=10;
				yi=11;er=11;
				si=shijian[1]/10;wu=shijian[1]%10;
				qi=shijian[0]/10;ba=shijian[0]%10;
			}
		}else if(mod==2){
			if(shijian[0]%2==0){
				san=10;liu=10;
				yi=shijian[2]/10;er=shijian[2]%10;
				si=shijian[1]/10;wu=shijian[1]%10;
				qi=shijian[0]/10;ba=shijian[0]%10;
			}else{
				san=10;liu=10;
				yi=shijian[2]/10;er=shijian[2]%10;
				si=11;wu=11;
				qi=shijian[0]/10;ba=shijian[0]%10;
			}
		}else if(mod==3){
			if(shijian[0]%2==0){
				san=10;liu=10;
				yi=shijian[2]/10;er=shijian[2]%10;
				si=shijian[1]/10;wu=shijian[1]%10;
				qi=shijian[0]/10;ba=shijian[0]%10;
			}else{
				san=10;liu=10;
				yi=shijian[2]/10;er=shijian[2]%10;
				si=shijian[1]/10;wu=shijian[1]%10;
				qi=11;ba=11;
			}
		}else if(mod==4){
			if(shijian[0]%2==0){
				san=10;liu=10;
				yi=nz[2]/10;er=nz[2]%10;
				si=nz[1]/10;wu=nz[1]%10;
				qi=nz[0]/10;ba=nz[0]%10;
			}else{
				san=10;liu=10;
				yi=11;er=11;
				si=nz[1]/10;wu=nz[1]%10;
				qi=nz[0]/10;ba=nz[0]%10;
			}
		}else if(mod==5){
			if(shijian[0]%2==0){
				san=10;liu=10;
				yi=nz[2]/10;er=nz[2]%10;
				si=nz[1]/10;wu=nz[1]%10;
				qi=nz[0]/10;ba=nz[0]%10;
			}else{
				san=10;liu=10;
				yi=nz[2]/10;er=nz[2]%10;
				si=11;wu=11;
				qi=nz[0]/10;ba=nz[0]%10;
			}
		}else if(mod==6){
			if(shijian[0]%2==0){
				san=10;liu=10;
				yi=nz[2]/10;er=nz[2]%10;
				si=nz[1]/10;wu=nz[1]%10;
				qi=nz[0]/10;ba=nz[0]%10;
			}else{
				san=10;liu=10;
				yi=nz[2]/10;er=nz[2]%10;
				si=nz[1]/10;wu=nz[1]%10;
				qi=11;ba=11;
			}
		}
		
		key4();
		display1(yi,er);
		display2(san,si);
		display3(wu,liu);
		display4(qi,ba);
	}
}

void Timer0Init(void)		//5毫秒@11.0592MHz
{
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0x00;		//设置定时初值
	TH0 = 0x28;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0=1;
}

void Timer0() interrupt 1{
	tt++;wus++;
	if((tt==40)&&(led==1)){
		tt=0;
		if(fla==0){fla=1;P2=0x80;P0=0xfe;}
		else if(fla==1){fla=0;P2=0x80;P0=0xff;}
	}
	if(wus==1000){
		wus=0;led=0;P2=0x80;P0=0xff;
	}
}

void key4(){
	if(P30==0){
		Delayms(5);
		if(P30==0){
			if(led==0){
				if(mod==0)mod=1;
				else if(mod==1)mod=2;
				else if(mod==2)mod=3;
				else if(mod==3)mod=0;//S7
			}else if(led==1){
				led=0;P2=0x80;P0=0xff;
			}
			while(!P30){
				display1(yi,er);
				display2(san,si);
				display3(wu,liu);
				display4(qi,ba);
			};
		}
	}
	if(P31==0){
		Delayms(5);
		if(P31==0){
			if(led==0){
			if(mod==0)mod=4;
			else if(mod==4)mod=5;
			else if(mod==5)mod=6;
			else if(mod==6)mod=0;
			}else if(led==1){
				led=0;P2=0x80;P0=0xff;
			}
			while(!P31){
				display1(yi,er);
				display2(san,si);
				display3(wu,liu);
				display4(qi,ba);
			};
		}
	}
	if(P32==0){
		Delayms(5);
		if(P32==0){
			if(led==0){
			if(mod==1){
				shijian[2]=shijian[2]+1;
				if(shijian[2]>23)shijian[2]=0;
				Ds1302Init();
			}else if(mod==2){
				shijian[1]=shijian[1]+1;
				if(shijian[1]>59)shijian[1]=0;
				Ds1302Init();
			}else if(mod==3){
				shijian[0]=shijian[0]+1;
				if(shijian[0]>59)shijian[0]=0;
				Ds1302Init();
			}else if(mod==4){
				nz[2]=nz[2]+1;
				if(nz[2]>23)nz[2]=0;
			}else if(mod==5){
				nz[1]=nz[1]+1;
				if(nz[1]>59)nz[1]=0;
			}else if(mod==6){
				nz[0]=nz[0]+1;
				if(nz[0]>59)nz[0]=0;
			}
			}else if(led==1){
				led=0;P2=0x80;P0=0xff;
			}
			while(!P32){
				display1(yi,er);
				display2(san,si);
				display3(wu,liu);
				display4(qi,ba);
			};
		}
	}
	if(P33==0){
		Delayms(5);
		if(P33==0){
			if(led==0){
			if(mod==1){
				if(shijian[2]==0)shijian[2]=23;
				else shijian[2]=shijian[2]-1;
				Ds1302Init();
			}else if(mod==2){
				if(shijian[1]==0)shijian[1]=59;
				else shijian[1]=shijian[1]-1;
				Ds1302Init();
			}else if(mod==3){
				if(shijian[0]==0)shijian[0]=59;
				else shijian[0]=shijian[0]-1;
				Ds1302Init();
			}else if(mod==4){
				if(nz[2]==0)nz[2]=23;
				else nz[2]=nz[2]-1;
			}else if(mod==5){
				if(nz[1]==0)nz[1]=59;
				else nz[1]=nz[1]-1;
			}else if(mod==6){
				if(nz[0]==0)nz[0]=59;
				else nz[0]=nz[0]-1;
			}
			}else if(led==1){
				led=0;P2=0x80;P0=0xff;
			}
			while(!P33){
				if(mod==0){
					yi=11;er=11;san=11;si=11;wu=11;
					liu=wd/10;qi=wd%10;ba=12;
				}
				display1(yi,er);
				display2(san,si);
				display3(wu,liu);
				display4(qi,ba);
			};
		}
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
	P2=0xc0;P0=0xff;P2=0xe0;P0=0xff;
	Delayms(1);
}

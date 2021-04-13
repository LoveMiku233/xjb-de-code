#include <STC15F2K60S2.H>
#include "onewire.h"
#define u8 unsigned char
#define u16 unsigned int
u8 mod=1,time=0,t_mod;
u16 tt=0,pwm_t,pwm=3;
u8 yi,er,san,si,wu,liu,qi,ba,wd=0;
u8 tab[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90,0XBF,0XFF,0xC6};
void Allinit();
void Delayms(u16 ms);
void key4();
void display1(u8,u8);
void display2(u8,u8);
void display3(u8,u8);
void display4(u8,u8);

void Timer0Init(void);

void main(){
	Allinit();
	Timer0Init();
	ET0=1;EA=1;
	while(1){
		wd=Ds_get();
		yi=10;san=10;er=mod;si=11;
		if(mod==1||mod==2||mod==3){
			wu=time/1000;liu=time%1000/100;qi=time%100/10;ba=time%10;
			if(time>0){
				P2=0x80;
				switch(mod){
					case 1:P0=0xfe;break;
					case 2:P0=0xfd;break;
					case 3:P0=0xfb;break;
				}
			}else{
				P2=0x80;P0=0xff;P34=0;
			}
		}else if(mod==4){
			wu=11;liu=wd/10;qi=wd%10;ba=12;
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
		if(P30==0){
			if(mod!=4){
				t_mod=mod;						//S7
				mod=4;
			}else{
				mod=t_mod;
			}
			while(!P30);
		}
	}
	if(P31==0){
		Delayms(5);
		if(P31==0){
			TR0=0;      //S6
			time=0;
			P2=0x80;P0=0xff;
			while(!P31);
		}
	}
	if(P32==0){
		Delayms(5);
		if(P32==0){
			time=time+60;
			if(time>120)time=0;//S5
			TR0=1;
			while(!P32);
		}
	}
	if(P33==0){
		Delayms(5);
		if(P33==0){
			TR0=1;
			if(mod==1){mod=2;pwm=4;}
			else if(mod==2){mod=3;pwm=8;}
			else if(mod==3){mod=1;pwm=3;}//S4
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
	P2=0xc0;P0=0xff;P2=0xe0;P0=0xff;
	Delayms(1);
}

void Timer0Init(void)		//100微秒@11.0592MHz
{
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0xAE;		//设置定时初值
	TH0 = 0xFB;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 0;		//定时器0开始计时
}

void Time0() interrupt 1{
	tt++;pwm_t++;
	if(pwm_t==11)pwm_t=1;
	if(tt==10000&&time>0){
		time--;
		tt=0;
	}
	if(time>0){
		if(pwm_t<pwm)P34=1;
		else P34=0;
	}
}
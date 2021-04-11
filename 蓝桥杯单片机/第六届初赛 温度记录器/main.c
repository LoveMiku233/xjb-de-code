#include <STC15F2K60S2.H>
#include "onewire.h"
#include "ds1302.h"
#define u8 unsigned char
#define u16 unsigned int
extern u8 shijian[];
u8 tab[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90,0XBF,0XFF};
u8 yi,er,san,si,wu,liu,qi,ba;
u8 wd,a=0;
u8 canshu=0;
u8 timesz=1;
u16 tt=0;
u8 save[10];
u8 i,LED_shuan=0,fla=0;
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
	Ds_Init();
	while(1){

		if(canshu==0){
			yi=11;er=11;san=11;si=11;wu=11;liu=10;qi=timesz/10;ba=timesz%10;
		}else if(canshu==1){
			ET0=1;EA=1;TR0=1;
			Ds_get();
			yi=shijian[2]/10;er=shijian[2]%10;
			si=shijian[1]/10;wu=shijian[1]%10;
			qi=shijian[0]/10;ba=shijian[0]%10;
			if(shijian[0]%2==0){
				san=10;liu=10;
			}else{
				san=11;liu=11;
			}
			if(i==10){
				i=0;
			}
		}else if(canshu==2){
			yi=10;er=a/10;san=a%10;si=11;wu=11;liu=10;qi=save[a]/10;ba=save[a]%10;
			if(a==10){
				a=0;
			}
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
			if(canshu==2){
				canshu=0;TR0=0;a=0;
			}//S7
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
			LED_shuan=0;
			P2=0x80;
			P0=0xff;//S6
			a++;
			TR0=0;
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
			if(canshu==0)canshu=1;
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
			if(timesz==1)timesz=5;
			else if(timesz==5)timesz=30;
			else if(timesz==30)timesz=60;
			else if(timesz==60)timesz=1;
			while(!P33){
				display1(yi,er);
				display2(san,si);
				display3(wu,liu);
				display4(qi,ba);
			};
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

void Timer0Init(void)		//5毫秒@11.0592MHz
{
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0x00;		//设置定时初值
	TH0 = 0x28;		//设置定时初值
	TF0 = 0;		//清除TF0标志		//定时器0开始计时
}


void Time0() interrupt 1{
	tt++;
	if((canshu==1)&&(tt==(timesz*200))&&(i<10)){
		wd=Temp_get();
		tt=0;
		save[i]=wd;
		i++;
	}
	if((i==10)&&(LED_shuan==0)){
		LED_shuan=1;i=0;canshu=2;
	}
	if((tt==200)&&(LED_shuan==1)){
		tt=0;
		if(fla==0){
			P2=0x80;P0=0xfe;fla=1;
		}else if(fla==1){
			fla=0;P2=0x80;P0=0xff;
		}
	}
}
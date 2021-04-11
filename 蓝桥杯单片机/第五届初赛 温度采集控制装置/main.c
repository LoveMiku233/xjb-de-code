#include <STC15F2K60S2.H>
#include "onewire.h"
#define u8 unsigned char 
#define u16 unsigned int 

u8 yi,er,san,si,wu,liu,qi,ba,wd,quj;
u8 max=30,min=20,tt=0,t_max,t_min;
u8 data tab[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90,0XBF,0XFF};
void AllInit();//初始化
void Delayms(u16);//延时函数
//void key4();//键盘
void key16();//矩阵键盘
u8 num=0;
//数码管显示
void display1(u8 yi,u8 er);
void display2(u8 san,u8 si);
void display3(u8 wu,u8 liu);
void display4(u8 qi,u8 ba);
void Timer0Init(void);
//主函数
bit flag=0;//
//设置
bit szflag=0,bz=0;
//清0
bit qingko=0;
void main(){
	AllInit();
	//主循环
	Timer0Init();
	while(1){
		if(szflag==0){
			wd=Temp_get();
			if(wd<min){
				quj=0;P2=0xa0;P0=0x00;
			}else if((wd>=min)&&(wd<=max)){
				quj=1;P2=0xa0;P0=0x00;
			}else if(wd>max){
				quj=2;P2=0xa0;P0=0x10;
			}
			yi=10;er=quj;san=10;si=11;wu=11;liu=11;qi=wd/10;ba=wd%10;
		}else{
			
			if((er==11)&&(bz==1)){
				bz=0;er=num;
			}else if((san==11)&&(bz==1)){
				bz=0;san=num;
			}else if((qi==11)&&(bz==1)){
				bz=0;qi=num;
			}else if((ba==11)&&(bz==1)){
				bz=0;ba=num;
				t_max=er*10+san;t_min=qi*10+ba;
				if(t_min>t_max){
					yi=10;er=11;san=11;si=11;wu=11;liu=10;qi=11;ba=11;
					P2=0x80;P0=0xbf;
				}else{
					max=t_max;
					min=t_min;
				}
			}
			if(qingko==1){
				qingko=0;
				yi=10;er=11;san=11;si=11;wu=11;liu=10;qi=11;ba=11;
			}
		}
		key16();
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

//void key4(){
//	if(P30==0){
//		Delayms(5);
//		if(P30==0){
//			//S7
//			while(!P30);
//		}
//	}
//	if(P31==0){
//		Delayms(5);
//		if(P31==0){
//			//S6
//			while(!P31);
//		}
//	}
//	if(P32==0){
//		Delayms(5);
//		if(P32==0){
//			//S5
//			while(!P32);
//		}
//	}
//	if(P33==0){
//		Delayms(5);
//		if(P33==0){
//			//S4
//		}
//		while(!P33);
//	}
//}

void key16(){
	u8 temp;
	P44=0;P42=1;P3=0x7f;
	temp=P3;
	temp=temp&0x0f;
	if(temp!=0x0f){
		Delayms(5);
		temp=P3;
		temp=temp&0x0f;
		if(temp!=0x0f){
			temp=P3;
			switch(temp){
				case 0x7e: num=0;bz=1;break;//S7
				case 0x7d: num=3;bz=1;break;//S6
				case 0x7b: num=6;bz=1;break;//S5
				case 0x77: num=9;bz=1;break;//S4
			}
			while(temp!=0x0f){
				temp=P3;temp=temp&0x0f;
			}
		}
		
	}
	P44=1;P42=0;P3=0xbf;
	temp=P3;
	temp=temp&0x0f;
	if(temp!=0x0f){
		Delayms(5);
		temp=P3;
		temp=(temp&0x0f);
		if(temp!=0x0f){
			temp=P3;
			switch(temp){
				case 0xbe: num=1;bz=1;break;
				case 0xbd: num=4;bz=1;break;
				case 0xbb: num=7;bz=1;break;
				case 0xb7: 
					if(szflag==0){
						szflag=1;ET0=0;P2=0xa0;P0=0x00;P2=0x80;P0=0xff;
						yi=10;er=11;san=11;si=11;wu=11;liu=10;qi=11;ba=11;
					}else{
						szflag=0;ET0=1;
					}
				break;
			}
			while(temp!=0x0f){
				temp=P3;temp=(temp&0x0f);
			}
		}
		
	}
		P44=1;P42=1;P3=0xdf;
		temp=P3;
		temp=temp&0x0f;
		if(temp!=0x0f){
			Delayms(5);
			temp=P3;
			temp=temp&0x0f;
			if(temp!=0x0f){
				temp=P3;
				switch(temp){
					case 0xde: num=2;bz=1;break;
					case 0xdd: num=5;bz=1;break;
					case 0xdb: num=8;bz=1;break;
					case 0xd7: qingko=1;break;
				}
				while(temp!=0x0f){
					temp=P3;temp=temp&0x0f;
				}
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
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0=1;
	EA=1;
}

void Time0() interrupt 1{
	tt++;
	if((quj==0)&&(tt==160)){
		tt=0;
		if(flag==0){flag=1;P2=0x80;P0=0x7f;}
		else{flag=0;P2=0x80;P0=0xff;}
	}
	if((quj==1)&&(tt==80)){
		tt=0;
		if(flag==0){flag=1;P2=0x80;P0=0x7f;}
		else{flag=0;P2=0x80;P0=0xff;}
	}
	if((quj==2)&&(tt==40)){
		tt=0;
		if(flag==0){flag=1;P2=0x80;P0=0x7f;}
		else{flag=0;P2=0x80;P0=0xff;}
	}
}
#ifndef __DS1302_H
#define __DS1302_H
void ds1302_init();
void Write_Ds1302(unsigned char temp);
void Write_Ds1302_Byte( unsigned char address,unsigned char dat );
unsigned char Read_Ds1302_Byte( unsigned char address );
void ds1302_get();
#endif

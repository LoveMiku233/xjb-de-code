#include "stdio.h"
int main()
{
float num=1;
printf("输入金额: ");
scanf("%f",&num) ;
if ( num<1000) ;
else if(num>=1000)num*=0.95F ;
else if(num>=3000)num*=0.9F ;
else if(num>=5000)num*=0.8F ;
else if(num>=8000) num*=0.7F ;
printf("打折后金额: %.2f\n",num) ;
return 0;
}

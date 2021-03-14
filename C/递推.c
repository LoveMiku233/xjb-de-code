#include <stdio.h>

int tuzi(int n){ //兔子产仔
    int t1,t2;
    if(n==1||n==2)
        return 1;
    else{
        t1=tuzi(n-1);
        t2=tuzi(n-2);
        return t1+t2;
    }
}

int main(){
    int n;
    printf("输入几个月: ");
    scanf("%d",&n);
    printf("%d月后，兔子对数: %d\n",n,tuzi(n));
    return 0;
}
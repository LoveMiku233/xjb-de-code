#include <stdio.h>
int fact(int n){
    if(n<=1)
        return 1;
    else
        return n*fact(n-1);
}

int main(){
    int i;
    printf("请输入递归的数: ");
    scanf("%d",&i);
    printf("结果: %d\n",fact(i));
    return 0;
}
#include <stdio.h>
int fact(int n){
    if(n<=1)
        return 1;
    else
        return n*fact(n-1);
}




int main(){
    int i=2134;
    //printf("请输入递归的数: ");
    //scanf("%d",&i);
    printf("yi= %d er= %d san= %d si= %d\n",i%10,(i%100)/10,(i%1000)/100,i/1000);
    return 0;
}
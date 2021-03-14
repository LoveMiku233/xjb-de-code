#include <stdio.h>

//鸡兔同笼
int jit(int head,int foot,int *chicken,int *rabbit){ //穷举
    int re,i,j; //标志，鸡，兔
    for(i=0;i<head;i++){
        j=head-i;
        if((i*2+j*4)==foot){
            *chicken=i;
            *rabbit=j;
            re=1;//置1
        }
    }
    return re; 
}
int main(){
    int chicken,rabbit,head,foot;
    printf("穷举法解决鸡兔同笼: \n");
    printf("输入头数: ");
    scanf("%d",&head);
    printf("输入脚数: ");
    scanf("%d",&foot);

    if(jit(head,foot,&chicken,&rabbit)){
        printf("鸡有: %d 只,兔有: %d 只\n",chicken,rabbit);
    }else{
        printf("输入有误!\n");
    }
    return 0;
}
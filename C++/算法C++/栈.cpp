/*
* 文件名：栈.cpp                   
* 作者：LoveMiku233〈1657041544@qq.com〉    
* 描述：Stack测试主函数 
* 创建日期：2021-1-29
* 修改时间：2021-1-29 简单实现Stack 
*/
#include "iostream"
#include "Stack.h"
using namespace std;
int main(){
    Queue2 qu;
    qu.enqueue(10);
    qu.enqueue(32);
    qu.enqueue(20);
    qu.enqueue(20);
    qu.printQueue();
    cout<<qu.dequeue()<<endl;
    qu.printQueue();
    return 0;
}
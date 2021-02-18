/*
* 文件名：Stack.h                   
* 作者：LoveMiku233〈1657041544@qq.com〉    
* 描述：Stack类 
* 创建日期：2021-1-29
* 修改时间：2021-1-29 利用Array类简单实现Stack类 和 queue类
*/
#ifndef _STACK_MIKU_
#define _STACK_MIKU_
#include "Array.h"
class Stack{
    public:
        virtual void push(int);
        virtual void pop();
        virtual int peek();
        virtual int getSize();
        virtual bool isEmpty();
};
class ArrayStack{
    private:
        Array arr;
    public:
        ArrayStack(int a):arr(a){};
        ArrayStack():arr(10){};
        void push(int a){arr.addList(a);};
        int pop(){int a=arr.get(arr.lenght-1);arr.reMoveList();return a;}; 
        int peek(){return arr.get(arr.lenght-1);};
        int getSize(){return arr.lenght;};
        bool isEmpty(){return (arr.lenght==0?false:true);};
};
class Queue{
    private:
        Array arr;
    public:
        Queue(int a):arr(a){};
        Queue():arr(10){};
        void enqueue(int a){arr.addList(a);};
        int dequeue(){int a=arr.get(0);arr.reMoveFirst();return a;};
        int getFront(){return arr.get(0);};
        int getSize(){return arr.lenght;};
        bool isEmpty(){return arr.lenght?true:false;};
};
class Queue2{
    private:
        Array arr;
        int front,tail,size;
    public:
        Queue2(int a):arr(a+1){front=0;tail=0;size=a+1;};
        Queue2():arr(6){front=0;tail=0;size=6;};
        int getCapacity(){return size-1;};
        bool isEmpty(){return front==tail;};
        void enqueue(int);
        int dequeue();
        void printQueue();

};
void Queue2::printQueue(){
    std::cout<<"[";
    for(int i=front;i<tail;i++)
        std::cout<<arr.get(i)<<" ";
    std::cout<<"]"<<std::endl;
}
void Queue2::enqueue(int a){
    if((tail+1)%size==front)
        arr.reSize(size*2+1);
    arr.set(tail,a);
    tail++;
}
int Queue2::dequeue(){
    if(!isEmpty()){
        int a=arr.get(front);
        front++;
        return a;
    }
    return -1;
}
#endif
/*****************************************
* 文件名：插入排序法.cpp                    
* 作者：LoveMiku233〈1657041544@qq.com〉    
* 描述：插入排序法实现 
* 创建日期：2021-1-25                                              
* 修改内容：2021-1-25 am 基础算法实现
                    pm 添加简单优化,class测试
******************************************/

#include <iostream>
#include "test.h"
using namespace std;
template<class T> void arrSort(T *,int); //插入排序
template<class T> void sawp(T *,T,T); //数组索引交换
template<class T> bool isSorted(T *,int);//判断是否有序
template<class T> void arrSort1(T *,int);//第二种方法
int main(){
    int arr[5]={4,2,2,1,2};//{4,4} 2
    //判断1
    test arrTest[5]={
        test(233,"Miku"),
        test(436,"yankai"),
        test(111,"Love"),
        test(222,"NO1"),
        test(999,"NB"),
    };
    cout<<"is sorted? "<<(isSorted(arr,5)?"Yes":"No")<<endl;
    arrSort1(arr,5);
    arrSort1(arrTest,5);
    cout<<"is sorted? "<<(isSorted(arr,5)?"Yes":"No")<<endl;
    for(int k=0;k<5;k++)
        cout<<arr[k];
    for(int k=0;k<5;k++)
        cout<<"Name: "<<arrTest[k].get_str()<<" Score: "<<arrTest[k].get_int()<<endl;
    cout<<endl;
    return 0;
}
template<class T> void arrSort(T *arr,int size){
    for(int i=0;i<size;i++){
        int j=i;
        while(j>0){
            if(arr[j]<arr[j-1])
                sawp(arr,j,j-1);
            else
                j--;
        }
    }
}
//优化后
template<class T> void arrSort1(T *arr,int size){
    for(int i=0;i<size;i++){
        //a存放arr中i索引中的值
        T a=arr[i];
        //j索引
        int j;
        //j=i；判断j-1是否大于0并且a中的值是否小于j-1索引中的值,如果小于就把j-1的值往后移一位;
        for(j=i;j-1>=0&&(a<arr[j-1]);j--)
                arr[j]=arr[j-1];
        //j索引的值替换为a(一开始arr[i])中的值
        arr[j]=a;
       }   
}
template<class T> void sawp(T *arr,T a,T b){
    T temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
template<class T> bool isSorted(T *arr,int size){
    for(int f=1;f<size;f++){
        if(arr[f]<arr[f-1])
            return 0;
    }
    return 1;
}
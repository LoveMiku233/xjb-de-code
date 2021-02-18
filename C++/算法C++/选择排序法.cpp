/*****************************************
* 文件名：选择排序法.cpp                    
* 作者：LoveMiku233〈1657041544@qq.com〉    
* 描述：选择排序法实现 
* 创建日期：2021-1-23                                              
* 修改内容：2021-1-23  实现基础功能
          2021-1-24  添加test.h
                     添加判断是否有序的函数              
******************************************/

#include <iostream>
#include "test.h"
using namespace std;
int maxOrmin(int*, int, bool,int);//寻找数组中最大值或者最小值
template<class T> void SelectionSort(T*, int); //算法函数
template<class T> void sawp(T*,int,int); //交换数组两个索引中的值
template<class T> bool isSorted(T*,int);//判断是否有序
template<class T> int compareTo(T,T); //第一个操作数大于第二个返回1,等于返回0,小于返回-1
int main() {
    //int无序数组
    int arr[5] = { 3,4,1,1,2 };
    //class 测试数组
    test arrTest[5]={
        test(100,"Miku"),
        test(70,"Yankai"),
        test(88,"233"),
        test(86,"Love233"),
        test(69,"jie"),
    };
    //对class数组进行排序,已经在test.h中实现判断test大小
    SelectionSort(arrTest,5);
    //打印排序后的class数组
    for (int i = 0; i < 5; i++)
    {
        cout<<"Name: "<<arrTest[i].get_str()<<" "
            <<"score:"<<arrTest[i].get_int()<<endl;
    }
    cout<<endl;
    //测试寻找最大值,最小值函数
    cout << "MAX: " << maxOrmin(arr, 5, true,0) << endl
        << "MIN: " << maxOrmin(arr, 5, false,0) << endl;
    cout << "....OK!" << endl;
    //对int数组进行排序
    SelectionSort(arr,5);
    /*判断是否为有序
    if(isSorted(arr,5))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    */
    cout<<"Sort? "<<(isSorted(arr,5)?"Yes":"No")<<endl;
    //打印数组
    for (int i = 0; i < 5; i++)
        cout << arr[i];
    cout << endl;
    return 0;
}
//返回最小值或者最大值
int maxOrmin(int* arr, int size, bool zt,int start) {
    int temp = arr[0];
    for (int i = start; i < size; i++) {
        if (zt) {
            if (temp < arr[i])
                temp = arr[i];
        }
        else {
            if (temp > arr[i])
                temp = arr[i];
        }
    }
    return temp;
}
/*
 void SelectionSort(int* arr, int size) {
        maxOrmin(arr1, size - i, false,);
        arr[i] = a;
}
*/
template<class T> void SelectionSort(T *arr,int size){
    for(int i=0;i<size;i++){
        int minIndex=i; //索引为数组第一个 0
        for(int j=i;j<size;j++){ //
            if(arr[minIndex]>arr[j])//最小值索引的值 大于 数组j位置的值
                minIndex=j;//最小值索引
        }
        sawp(arr,minIndex,i);//交换minIndex和j 索引的值
    }
}
template<class T> void sawp(T* arr,int a,int b){
    T temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
template<class T> bool isSorted(T* arr,int size){
    for(int i=1;i<size;i++){
        //判断arr[i-1]是否大于arr[i],是则不是有有序数组
        if(compareTo(arr[i-1],arr[i])==1)
            return false;
    } 
    return true;
}
template<class T> int compareTo(T a,T b){
    if(a>b)
        return 1;
    else if(a==b)
        return 0;
    else
        return -1;
    
}   

/*
* 文件名：Array.h                   
* 作者：LoveMiku233〈1657041544@qq.com〉    
* 描述：int数组类 
* 创建日期：2021-1-27
* 修改时间：2021-1-27 简单实现Array类   
          2021-1-28 添加查，搜，删，改功能
                    基本实现数组功能   
*/
#ifndef _ARRAY_MIKU_
#define _ARRAY_MIKU_

class Array{
    private:
        int size;//数组大小
        int *arr;//数组
    public:
        int lenght;//实际长度 可以直接.lenght访问
        Array(int a):size(a){arr=new int[a];lenght=0;};//new 申请空间
        Array(){size=10;arr=new int[size];lenght=0;};//默认大小为10
        int get_size() const{return size;}; //获取数组空间大小
        bool isEmpty() const{return (lenght==0?true:false);};//判断是否为空
        bool isVal(int) const;//判断数组中是否有这个值
        int find(int) const;//找到某个值第一个位置,找不到返回-1
        void reMove(int);//删除数组索引的值
        void reMoveFirst(){reMove(0);};//删除数组第一个
        void reMoveList(){reMove(lenght-1);};//删除数组最后一个
        void reMoveElement(int);//先寻找是否有该值，有就删除该值
        void inIndex(int,int);//在数组中插入值(插入位置索引，插入值)
        void add(int);//在数组尾部添加值 ???可以删了
        void addList(int a){inIndex(lenght,a);}; //尾部
        void addFirst(int a){inIndex(0,a);};    //开头
        int get(int) const;//接收索引，返回索引的值
        void Sort1();//选择排序
        void Sort2();//插入排序
        void set(int,int);//索引,修改的值
        void sawp(int,int);//交换两个索引数组的内容
        void arrPrint();//打印数组
        void printDebug();//打印调试信息
        void reSize(int);
        void MergeSort(arr,l,r);
        ~Array(){delete []arr;};//析构函数 释放空间   
};
void Array::reSize(int a){
        if(a>lenght){
            int *rearr=new int[a];
            for(int i=0;i<lenght;i++){
                rearr[i]=arr[i];
                size=a;
            }
            arr=rearr;
        }
}
void Array::reMoveElement(int a){
    int index=find(a);
    if(a!=-1){
        reMove(index);
        std::cout<<"OK"<<std::endl;
    }else{
        std::cout<<"No"<<std::endl;
    }
}
void Array::reMove(int a){
    if(a>=0&&a<lenght){
        for(int i=a;i<lenght;i++){
            arr[i]=arr[i+1];
        }
        lenght--;
    }
}
int Array::find(int a) const{
    for (int i=0;i<lenght;i++){
        if(arr[i]==a)
            return i;
    }
    return -1;
}
bool Array::isVal(int a) const{
    for(int i=0;i<lenght;i++){
        if(arr[i]==a)
            return true;
    }
    return false;
}
void Array::set(int index,int val){
    if(index<0&&index>(lenght-1))
        std::cout<<"no index"<<std::endl;
    else
        arr[index]=val;
}
void Array::printDebug(){
    std::cout<<"[ Array size: "<<size<<" "<<"Array lenght: "<<lenght<<" ]"<<std::endl;
}
void Array::arrPrint(){
    std::cout<<"[";
    for(int i=0;i<lenght;i++){
        std::cout<<arr[i];
        if(i!=lenght-1)
            std::cout<<",";
    }
    std::cout<<"]";
}
int Array::get(int a) const{
    if(!isEmpty()&&a>=0&&a<lenght){
        return arr[a];
    }
    return arr[a];
}
void Array::add(int a){
    if(lenght>=0&&lenght<size){
        arr[lenght]=a;
        lenght++;
    }else{
        std::cout<<"nm"<<std::endl;
    }
}
void Array::Sort1(){
    for(int i=0;i<lenght;i++){
        int minIndex=i;
        for(int j=i;j<lenght;j++){
            if(arr[minIndex]>arr[j])
                minIndex=j;
        }
        sawp(minIndex,i);
    }
}
void Array::Sort2(){
    for(int i=0;i<lenght;i++){
        int a=arr[i];
        int j;
        for(j=i;j-1>=0&&(a<arr[j-1]);j--)
            arr[j]=arr[j-1];
        arr[j]=a;
    }
}
void Array::sawp(int a,int b){
    if(a>=0&&b>=0&&a<lenght&&b<lenght){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
    }
}
void Array::inIndex(int a,int num){
    if(lenght<size&&a<size&&a>=0){
        for(int i=lenght;i>a;i--){
            arr[i]=arr[i-1];
        }
        arr[a]=num;
        lenght=(a>lenght)?(a+1):(lenght+1);
    }
}

#endif
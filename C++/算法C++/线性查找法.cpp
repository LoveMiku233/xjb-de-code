/*****************************************
* 文件名：线性查找法.cpp                    
* 作者：LoveMiku233〈1657041544@qq.com〉    
* 描述：线性查找法实现
* 创建日期：2021-1-23                    
* 修改时间：2021-1-23                      
* 修改内容：实现基础功能                     
******************************************/

#include <iostream>
#include <time.h> //clock()返回 clock_t   ms!
 //#define nums 5
using namespace std;
#define SIZE 100000
class test {
private:
    string s1;
public:
    string get() { return s1; };
    test(string str) :s1(str) {};
    bool operator==(test& a) const;
    friend bool operator==(test&, char* s2);
};
template <class T> int linearSearch(const T data[], int size, T num);
void newIntArr(int *);
int main() {
    int data[5] = { 15,17,18,16,14 };
    /* 寻找16
     for(int i=0;i<5;i++){
        if (data[i]==16)
            cout<<"Search 16 : "<<i<<endl;
    }

    test test1[5]={test("233"),test("2d33"),test("a3"),test("23ss3"),test("2123")};
    double f1[7]={1.41,3.14,5.555,6.666,7.6666,8.1111,9.1111};
    cout<<linearSearch(test1,5,test("2123"))<<endl;
    */
    clock_t start, end;
    int Arrtt[SIZE];
    newIntArr(Arrtt);
    short sy = 0;
    start = clock();
    sy = linearSearch(Arrtt, 100000, 5000); //测试时间复杂度
    end = clock();
    double dur = (double)(end - start);
    cout << "索引为: " << sy << endl
        << "用时: " << dur/CLOCKS_PER_SEC<<"ms"<< endl;
    return 0;
}
//找到返回索引，没有返回-1
template <class T> int linearSearch(const T data[], int size, T num) {
    int i = 0;
    while (i < size)
    {
        if (data[i] == num)
            return i;
        else
            i++;
    }
    return -1;
}

bool test::operator==(test& a) const {
    if (s1 == a.get())
        return true;
    else
        return false;
}
//错误函数 裂开了
/* int* newIntArr()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
        arr[i] = i;
    return arr;//返回临时变量地址cao
} 
*/
void newIntArr(int* arr)
{
    for (int i = 0; i < SIZE; i++)
        arr[i] =i;
}
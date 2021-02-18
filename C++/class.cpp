#include <iostream>
using namespace std;
class yan{
    public:
    int j;
    int k;
    void setj(int a){
        j=a;
    }
    void setk(int a){
        k=a;
    }
};
class miku{
protected:
    int a;
    int b;
public:
friend void printb(miku m1);
    int sumAB();
    miku(int c,int d):a(c),b(d){
 //   a=c;
 //   b=90;
};
    int getA();
    ~miku(){
        cout<<"GG"<<endl;
    }
};
class kai:public yan{
    public:
    void printjk(){
         cout<<j*k<<endl;
    }
    void printjk(int a){
        cout<<j*k+a<<endl;
    }
};
int miku::sumAB(){
    return a+b;
}
int miku::getA(){
    return a;
}
inline void printb(miku m1){
    cout<<m1.b<<endl;
}
int main(){
    miku m1(233,70);
    kai k1;
    k1.setj(4);
    k1.setk(6);
    k1.printjk();
    k1.printjk(30);

    int b=m1.getA();
    int a=m1.sumAB();
    cout<<a<<endl;
    cout<<b<<endl;

    printb(m1);
    return 0;
}

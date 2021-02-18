#include <iostream>
using namespace std;
void sawp(int& a,int& b);
int miku[]={10,20,30,40,50};
int& setnum(int i);
int main(){

    int i;
    double d;
    int& r=i;
    double& s=d;
    i=5;
    cout<<"i的值是: "<<i<<endl;
    cout<<"i的引用的值是: "<<r<<endl;
    
    d=11.7;
    cout<<"i的值是: "<<i<<endl;
    cout<<"i的引用的值是: "<<r<<endl;
    int h=7;//i=5,h=7
    sawp(i,h);
    cout<<"i= "<<i<<endl
        <<"h= "<<h<<endl;
    for(int i=0;i<5;i++){
        cout<<"没有改变"<<i<<" "
            <<miku[i]<<endl;
    }
    
    setnum(4)=34;
    setnum(0)=11;

    for(int i=0;i<5;i++){
        cout<<"改变后"<<i<<" "
            <<miku[i]<<endl;
    }
    return 0;
}

void sawp(int& a,int& b){
    int temp=a;
    a=b;
    b=temp;
}
int& setnum(int i){
    return miku[i];
}
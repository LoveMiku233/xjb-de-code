#include <iostream>
using namespace std;
double division(int a,int b){
    if(b==0||a==0){
        throw "zero";
    }
    return a/b;
}
int main(){
     int x=50;
     int y=9;
     double z=0;

     try{
         z=division(x,y);
         cout<<z<<endl;
     }catch(const char* msg){
         cerr<<msg<<endl;
     }
     return 0;
}
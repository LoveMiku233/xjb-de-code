#include <iostream>
#include "vector3.h"
#include "Matrix3x3.h"
using namespace std;
void printVector(const Vector3 &v){
    cout<<"["<<v.x<<","<<v.y<<","<<v.z<<"]"<<endl;
}
void printMatrx(const Matrix3x3 &a){
   cout<<"["<<a.m11<<","<<a.m12<<","<<a.m13<<"]"<<endl;
   cout<<"["<<a.m21<<","<<a.m22<<","<<a.m23<<"]"<<endl;
   cout<<"["<<a.m31<<","<<a.m33<<","<<a.m33<<"]"<<endl;
}
int main(){
     Matrix3x3 a,b,c;
     a.m11=1;a.m12=-5;a.m13=3;
     a.m21=0;a.m22=-2;a.m23=6;
     a.m31=7;a.m32=2;a.m33=-4;
     
     b.m11=-8;b.m12=6;b.m13=1;
     b.m21=7;b.m22=0;b.m23=-3;
     b.m31=2;b.m32=4;b.m33=5;
     c=a*b;
     printMatrx(c);
    return 0;
}
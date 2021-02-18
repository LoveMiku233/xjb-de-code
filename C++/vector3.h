#ifndef __VECCTOR3_H_INCLUDED__
#define __VECCTOR3_H_INCLUDED__
#include <math.h>
class Vector3{//三维向量
  public:
  float x,y,z;//三维向量的数

  Vector3(){}//无初始值
  Vector3(const Vector3 &a):x(a.x),y(a.y),z(a.z){};//参数是三维向量时,初始化
  Vector3(float nx,float ny,float nz):x(nx),y(ny),z(nz){}//初始化

  void zero(){x=y=z=0;}//零向量

  Vector3 operator -() const{return Vector3(-x,-y,-z);}//重载,负向量

  //标量
  Vector3 operator *(float a) const{
    return Vector3(x*a,y*a,z*a);
  }
  Vector3 operator *=(float a){
    x*=a,y*=a,z*=a;
    return *this;
  }
  Vector3 operator /(float a) const{
    float oneOverA=1.0f/a;
    return Vector3(x*oneOverA,y*oneOverA,z*oneOverA);
  }
  Vector3 operator /=(float a){
    float oneOverA=1.0f/a;
    x*oneOverA;
    y*oneOverA;
    z*oneOverA;
    return *this;
  }
  void normalize(){
    float magSq=x*x+y*y+z*z;
    if(magSq>0.0f){
      float oneOver=1.0f/sqrt(magSq);
      x *=oneOver;
      y *=oneOver;
      z *=oneOver;
    }
  }
  Vector3 operator +(const Vector3 &a) const{
    return Vector3(x+a.x,y+a.y,z+a.z);
  }
  Vector3 operator +=(const Vector3 &a){
    x +=a.x;
    y +=a.y;
    z +=a.z;
    return *this;
  }
  Vector3 operator -(const Vector3 &a) const{
    return Vector3(x-a.x,y-a.y,z-a.z);
  }
  Vector3 operator -=(const Vector3 &a){
   x-=a.x;
   y-=a.y;
   z-=a.z;
   return *this;
  }
  float operator*(const Vector3 &a){
    return x*a.x+y*a.y+z*a.z;
  }
};
inline float vectorMag(const Vector3 &a){ //计算向量长度，模
    return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}
inline Vector3 operator*(float a,const Vector3 b){
  return Vector3(a*b.x,a*b.y,a*b.z);
}
inline float vectorSize(const Vector3 &a,const Vector3 &b){
  return vectorMag(a-b);
}
  //[1,2,3] [3,2,1]
  //[2*1-3*2,3*3-1*1,1*2-2*3]
  //叉乘 miku up up up
inline Vector3 miku(const Vector3 &a,const Vector3 &b){
     //Vector3 c(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x)
     return Vector3(
       a.y*b.z-a.z*b.y,
       a.z*b.x-a.x*b.z,
       a.x*b.y-a.y*b.x
     );
  }
#endif
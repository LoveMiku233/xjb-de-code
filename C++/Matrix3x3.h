#ifndef __Matrix3x3__
#define __Matrix3x3__

class Vector3;
class  Matrix3x3
{
public:
   float m11,m12,m13;
   float m21,m22,m23;
   float m31,m32,m33;
   //Matrix3x3(){
     // m11=m12=m13=0;
     //m21=m22=m23=0;
      //m31=m32=m33=0;
  // };
  // Matrix3x3(const Matrix3x3& a):m11(a.m11),m12(a.m12),m13(a.m13),m21(a.m21),m22(a.m22),m23(a.m23),m31(a.m31),m32(a.m32),m33(a.m33) {};
};

Matrix3x3 operator*(const Matrix3x3 &a,const Matrix3x3 &b);

Vector3 operator*(const Vector3 &p,const Matrix3x3 &d);






#endif
#include "vector3.h"
#include "Matrix3x3.h"

Matrix3x3 operator*(const Matrix3x3 &a,const Matrix3x3 &b){
 Matrix3x3 r;
 r.m11=a.m11*b.m11+a.m12*b.m21+a.m13*b.m31;
 r.m12=a.m11*b.m12+a.m12*b.m22+a.m13*b.m32;
 r.m13=a.m11*b.m13+a.m12*b.m23+a.m13*b.m33;

 r.m21=a.m21*b.m11+a.m22*b.m21+a.m23*b.m31;
 r.m22=a.m21*b.m12+a.m22*b.m22+a.m23*b.m32;
 r.m23=a.m21*b.m13+a.m22*b.m23+a.m23*b.m33;

 r.m31=a.m31*b.m11+a.m32*b.m21+a.m33*b.m31;
 r.m32=a.m31*b.m12+a.m32*b.m22+a.m33*b.m32;
 r.m33=a.m31*b.m13+a.m32*b.m23+a.m33*b.m33;

 return r;
}

Vector3 operator*(const Vector3 &p,const Matrix3x3 &d){
    Vector3 r;
    r.x=p.x*d.m11+p.x*d.m21+p.y*d.m31;
    r.y=p.y*d.m12+p.y*d.m22+p.y*d.m32;
    r.z=p.z*d.m13+p.z*d.m23+p.z*d.m33;
    return r;
}
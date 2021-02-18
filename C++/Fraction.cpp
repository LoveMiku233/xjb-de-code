#include <iostream>
using namespace std;

class Fraction{
    public:
        Fraction(int m,int n=1):a(m),b(n){}
        operator double() const{
            return (double)(a/b);
        }
        Fraction operator+(const Fraction &f){
            return Fraction(f.a*4+t*4,f.b*4);
        }
        int get_a(){
            return a;
        }
        int get_b(){
            return b;
        }
    private:
        int a;
        int b;
};

Fraction operator+(int t,Fraction &f){
    return Fraction(f.get_a()*4+t*4,f.get_b().b*4);
}
int main(){
    Fraction f(3,5);
    double x=4+f;
    cout<<x<<endl;
    return 0;
}
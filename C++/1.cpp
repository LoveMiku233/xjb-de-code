#include <iostream>
#include "1.h"
using namespace std;

int main(){
    complex a(2,1);
    complex b(3,1);
    cout<<a.imag()<<endl;
    a.prinths(233);
    cout<<a.func(b)<<endl;
    return 0;
}
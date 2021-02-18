#include <iostream>
#include "2.h"
using namespace std;


int main(){
    cout<<"test"<<endl;
    for (char i = 32; i < 127; ++i) {
        cout << i << ' ';
        if (i % 16 == 15)
            cout << '\n';
    }

    return 0;
}
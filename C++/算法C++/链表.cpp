#include <iostream>
#include "Node.h"
using namespace std;
int main(){
    Node nd;
    nd.addFirst(4);
    nd.addFirst(5);
    nd.addFirst(6);
    nd.printLinked();
    cout<<endl;
    nd.add(2,233);
    nd.printLinked();
    return 0;
}


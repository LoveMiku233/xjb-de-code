#include <iostream>
#include <fstream>
using namespace std;
int main(){
    char data[100];
    ofstream txt;
    txt.open("miku.txt",ios::out|ios::trunc);
    cout<<"enter bot num: ";
    cin>>data;
    txt<<data<<endl;
    txt.seekp(0,ios::beg);
    txt<<"233"<<endl;
    txt.close();
    cout<<"over"<<endl;
    return 0;

}
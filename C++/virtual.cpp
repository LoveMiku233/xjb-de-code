#include <iostream>
using namespace std;
class Shape{
    public:
    virtual void draw(){};
    virtual void error(const string& msg){};
};
class miku: public Shape{
    public:
    virtual void draw(){
        cout<<"test"<<endl;
    }
    virtual void error(const string& msg){
        cout<<"err: "<<msg<<endl;
    }
};

int main(){
    miku m;
    m.draw();
    string a="miku";
    m.error(a);
    return 0;
}
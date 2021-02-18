#include <iostream>
#include "myString.h"
using namespace std;

ostream& operator << (ostream& os,String &a) {
    return os << a.getstr();
}
String operator+(const String &a, const String &b){
    char* temp=new char[a.getlen()+b.getlen()+1];
    strcpy(temp,a.getstr());
    strcat(temp,b.getstr());
    String s1(temp);
    return s1;
}
int main(){
   char* m="No.1";
   String s2("fuck");
   String s1("VS ");
   String s3=s2+s1;
   cout<<s2<<s1<<'!'<<endl<<s3<<endl<<m<<endl;
  
   return 0;
}
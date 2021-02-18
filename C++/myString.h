#ifndef __MYSTRING__
#define __MYSTRING__
#include <string.h>
class String
{
private:
     //动态分配的方式
     // char m_data[]错误的
    char * m_data;
public:
    String(const char* cstr);
    String(const String& str);
    String& operator=(const String& str);
    ~String();
    inline int getlen() const{
       return strlen(m_data);
    }
    char* getstr() const {return m_data;}
};
inline String::String(const char* cstr){
    if(cstr){
        //
        m_data=new char[strlen(cstr)+1];
        strcpy(m_data,cstr);
    }else{
        m_data=new char[1];
        *m_data='/0';
    }
}
inline String::String(const String& str){
    m_data=new char[strlen(str.m_data)+1];
    strcpy(m_data,str.m_data);
}
inline String& String::operator=(const String& str){
   if(this==&str)
    return *this;
   delete m_data;
   m_data=new char[strlen(str.m_data)+1];
   strcpy(m_data,str.m_data);
   return *this;
}
inline String::~String(){
   delete m_data;
}

#endif
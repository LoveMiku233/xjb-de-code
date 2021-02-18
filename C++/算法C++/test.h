/*
* 文件名：test.h                   
* 作者：LoveMiku233〈1657041544@qq.com〉    
* 描述：测试int 字符串,int数组类 
* 创建日期：2021-1-24
* 修改时间：2021-1-24 创建test类  
*/
#ifndef _TEST_MIKU_
#define _TEST_MIKU_
class test{
    private:
    int s1;
    char* s2;
    public:
    int get_int(){return s1;};
    char* get_str(){return s2;};
    test(int a,char* b):s1(a),s2(b){};
    bool operator>(test& a) const;
    bool operator==(test& a) const;
    bool operator<(test& a) const;
};

bool test::operator>(test& a) const{
    return (s1>a.get_int())?true:false;
}
bool test::operator==(test& a) const{
    return (s1==a.get_int())?true:false;
}
bool test::operator<(test& a) const{
    return (s1<a.get_int())?true:false;
}

#endif
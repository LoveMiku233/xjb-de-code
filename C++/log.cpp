/*************************************************************************
	> File Name: log.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

#ifdef DEBUG

#define LOG(frm, args...) { \
    printf("[%s : %d : %s] ", __FILE__, __LINE__, __func__); \
    printf(frm, ##args); \
    printf("\n"); \
}

#else 

#define LOG(frm, args...)

#endif

void test() {
    LOG("hello world");
    return ;
}

#define CAT(a, b) a##b

int main() {
    int haizei = 789;
    CAT(hai, zei) = 1000;
    LOG("haizei = %d", haizei);
    LOG("hello world");
    test();
    return 0;
}

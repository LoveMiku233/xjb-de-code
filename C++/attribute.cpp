/*************************************************************************
	> File Name: attribute.cpp
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

__attribute__((constructor))
void test() {
    printf("%s : hello world\n", __func__);
    return ;
}

int main() {
    printf("%s : hello world\n", __func__);
    return 0;
}

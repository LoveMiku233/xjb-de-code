/*************************************************************************
	> File Name: array.cpp
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

class ArrayFunction {
public :
    int operator()(int x) {
        return 2 * x;
    }
    int operator[](int x) {
        return 2 * x;
    }
};

int main() {
    ArrayFunction f;
    cout << f[2] << endl;
    cout << f(2) << endl;
    return 0;
}

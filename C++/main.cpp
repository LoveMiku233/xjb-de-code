/*************************************************************************
	> File Name: main.cpp
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
#include <haizei/htest.h>
using namespace std;

int add(int a, int b) {
    return a + b;
}

TEST(test, add1) {
    EXPECT_EQ(add(3, 4), 7); // ==
    EXPECT_NE(add(3, 4), 6); // !=
    EXPECT_LT(add(3, 4), 8); // <
    EXPECT_LE(add(3, 4), 7); // <=
    EXPECT_GT(add(3, 4), 6); // > 
    EXPECT_GE(add(3, 4), 7); // >=
}

TEST(test, add2) {
    EXPECT_EQ(add(3, 4), 7); // ==
    EXPECT_NE(add(3, 4), 7); // !=
    EXPECT_LT(add(3, 4), 8); // <
    EXPECT_LE(add(3, 4), 7); // <=
    EXPECT_GT(add(3, 4), 6); // > 
    EXPECT_GE(add(3, 4), 7); // >=
}

int main() {
    printf("\033[0;1;33;41mhello world\033[0m\n");
    printf("\033[0;32madd(3, 4) = %d\n", add(3, 4));
    return RUN_ALL_TESTS();
}


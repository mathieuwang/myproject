//
//  main.cpp
//  leetcode_8_atoi
//
//  Created by mathieuwang on 15/8/31.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <iostream>
#include <string>
#include "atoi.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    string teststr = "      -11919730356x";
    int output = 0;
    Solution sl;
    output = sl.myAtoi(teststr);
    std::cout << output << endl;
    return 0;
}

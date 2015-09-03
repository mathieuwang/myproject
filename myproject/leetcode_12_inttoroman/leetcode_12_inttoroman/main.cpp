//
//  main.cpp
//  leetcode_12_inttoroman
//
//  Created by mathieuwang on 15/9/2.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <iostream>
#include "inttoroman.cpp"
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int testint = 10;
    Solution sl;
    string ret = sl.intToRoman(testint);
    
    std::cout << "The Roman numeral of " << testint << " is " << ret << "." <<endl;
    return 0;
}

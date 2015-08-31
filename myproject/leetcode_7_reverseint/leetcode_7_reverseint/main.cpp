//
//  main.cpp
//  leetcode_7_reverseint
//
//  Created by mathieuwang on 15/8/31.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <iostream>
#include "reverseint.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    int testint = 10;
    Solution sl;
    int res = sl.reverse(testint);
    
    std::cout << "original number is " << testint << endl;
    std::cout << "reversed number is " << res <<endl;
    
    return 0;
}

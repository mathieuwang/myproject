//
//  main.cpp
//  leetcode_9_palindromenbr
//
//  Created by mathieuwang on 15/8/31.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <iostream>
#include "palindromenumber.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    int testint = 0;
    Solution sl;
    bool ret = sl.isPalindrome(testint);
    
    std::cout << testint << " ";
    if (ret) {
        std::cout << "is a palindrome number" <<std::endl;
    }
    else {
        std::cout << "is not a palindrome number" <<std::endl;
    }
    return 0;
}

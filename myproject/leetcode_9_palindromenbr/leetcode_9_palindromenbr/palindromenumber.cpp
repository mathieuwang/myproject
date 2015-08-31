//
//  palindromenumber.cpp
//  leetcode_9_palindromenbr
//
//  Created by mathieuwang on 15/8/31.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }
        if (x % 10 == 0) {
            return false;
        }
        int lastdigit = x % 10;
        
        while (x > lastdigit) {
            
        }
    }
};
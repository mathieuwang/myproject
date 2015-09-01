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
        int digitcount = 1;
        int tmp = x;
        
        int max = 1;
        int min = 1;
        
        while (tmp > 9) {
            ++ digitcount;
            tmp = tmp / 10;
            max = max * 10;
        }
        
        int i = 0, j = 0;
        for (; i < digitcount / 2; ++ i) {
            j = digitcount - i;
            if ((x / max) % 10 != (x / min) % 10) {
                return false;
            }
            max /= 10;
            min *= 10;
        }
        
        return true;
    }
};
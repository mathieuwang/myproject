//
//  reverseint.cpp
//  leetcode_7_reverseint
//
//  Created by mathieuwang on 15/8/31.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        if (x < 0) {
            negative = true;
            x = - x;
        }
        if (x == 0) {
            return x;
        }
        
        vector<int> digits;
        while (x > 9) {
            digits.push_back(x % 10);
            x = x / 10;
        }
        digits.push_back(x);
        
        int res = 0;
        
        int multi = 1;
        int oldmulti = 1;
        for (int idx = (int) digits.size() - 1; idx >= 0; -- idx) {
            if (oldmulti > INT_MAX / 10 || (digits[idx] != 0 && multi > INT_MAX / digits[idx])) {
                return 0;
            }
            int addon = multi * digits[idx];
            if (res > INT_MAX - addon)
                return 0;
            res += addon;
            oldmulti = multi;
            multi *= 10;
        }
        
        if (negative) {
            res = - res;
        }
        return res;
    }
};
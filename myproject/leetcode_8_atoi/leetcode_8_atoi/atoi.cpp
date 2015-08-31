//
//  atoi.cpp
//  leetcode_8_atoi
//
//  Created by mathieuwang on 15/8/31.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <limits.h>

using namespace std;

//32 for ' '
//45 for '-'
//48 for '0'

class Solution {
public:
    int myAtoi(string str) {
        //treatment of all illegal strings
        int ssize = (int) str.size();
        int beginpos = 0;
        
        for (int i = 0; i < ssize; ++ i) {
            const char currchar = str[i];
            if (currchar == ' ') {
                beginpos ++;
            }
            else {
                break;
            }
        }
        
        if (beginpos == ssize) return 0;
        
        int bnegative = 1;
        
        if (str[beginpos] == '-' || str[beginpos] == '+') {
            if (beginpos == ssize - 1) return 0;
            if (str[beginpos] == '-') {
                bnegative = -1;
            }
            beginpos = beginpos + 1;
        }
        
        int res = 0;
        int firstintchar = (int) str[beginpos] - 48;
        if (firstintchar < 0 || firstintchar > 9) {
            return 0;
        }
        
        for (int i = beginpos; i < ssize; ++ i) {
            const char currchar = str[i];
            int intchar = (int) currchar - 48;
            if (intchar < 0 || intchar > 9) {
                return bnegative * res;
            }
            if (res > (INT_MAX - intchar) / 10) {
                if (bnegative < 0) {
                    return INT_MIN;
                }
                else {
                    return INT_MAX;
                }
            }
            res = res * 10 + intchar;
        }
        return bnegative * res;
    }
};
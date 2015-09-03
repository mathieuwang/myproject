//
//  inttoroman.cpp
//  leetcode_12_inttoroman
//
//  Created by mathieuwang on 15/9/2.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ret = "";
        ret.reserve(20);
        vector<char> romandigits = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int dcount = 1;
        int multi = 1;
        int tmp = num;
        while (tmp > 9) {
            tmp /= 10;
            ++ dcount;
            multi *= 10;
        }
        for (; dcount > 0; -- dcount, multi /= 10) {
            int thisdigit = (num / multi) % 10;
            if (thisdigit == 0) {
                continue;
            }
            if (thisdigit < 4) {
                for (int k = 0; k < thisdigit; ++ k) {
                    ret.push_back(romandigits[2 * (dcount - 1)]);
                }
            }
            if (thisdigit == 4 || thisdigit == 9) {
                ret.push_back(romandigits[2 * (dcount - 1)]);
            }
            if (thisdigit > 3 && thisdigit < 9) {
                ret.push_back(romandigits[2 * (dcount - 1) + 1]);
            }
            if (thisdigit > 5 && thisdigit < 9) {
                for (int k = 0; k < thisdigit - 5; ++ k) {
                    ret.push_back(romandigits[2 * (dcount - 1)]);
                }
            }
            if (thisdigit == 9) {
                ret.push_back(romandigits[2 * dcount]);
            }
        }
        return ret;
    }
};

//
//  romantoint.cpp
//  leetcode_13_romantoint
//
//  Created by mathieuwang on 15/9/2.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> letmapping = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ssize = (int) s.length();
        int ret = 0;
        int currvalue = letmapping[s[0]];
        int prevvalue = letmapping[s[0]];
        for (int i = 1; i < ssize; ++ i) {
            currvalue = letmapping[s[i]];
            if (prevvalue < currvalue) {
                prevvalue = - prevvalue;
            }
            ret += prevvalue;
            prevvalue = currvalue;
        }
        ret += currvalue;
        return ret;
    }
};
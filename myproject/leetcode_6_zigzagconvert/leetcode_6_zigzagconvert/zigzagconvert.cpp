//
//  zigzagconvert.cpp
//  leetcode_6_zigzagconvert
//
//  Created by mathieuwang on 15/8/30.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string res = "";
        int ssize = (int) s.size();
        if (ssize <= numRows || numRows == 1) {
            return s;
        }
        vector<string> outputs(numRows);
        int period = numRows * 2 - 2;
        int pcount = ssize / period;
        
        int pos = 0;
        for (int k = 0; k <= pcount; ++ k) {
            int i = 0;
            for (; i < numRows && pos < ssize; ++ i, ++ pos) {
                outputs[i].push_back(s[pos]);
            }
            for (; i < period && pos < ssize; ++ i, ++ pos) {
                outputs[period - i].push_back(s[pos]);
            }
        }
        
        for (int k = 0; k < numRows; ++ k) {
            int currsize = (int) outputs[k].size();
            for (int i = 0; i < currsize; i ++) {
                res.push_back(outputs[k][i]);
            }
        }
        return res;
    };
};

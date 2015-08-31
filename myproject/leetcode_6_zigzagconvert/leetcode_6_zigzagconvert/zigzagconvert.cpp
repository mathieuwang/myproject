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
        string res;
        int ssize = (int) s.size();
        vector<string> outputs(numRows);
        int period = numRows * 2 - 2;
        int pcount = ssize / period;
        
        int pos = 0;
        for (int k = 0; k <= pcount && pos < ssize; ++ k) {
            int i = 0;
            for (; i < numRows; ++ i, ++ pos) {
                outputs[i].push_back(s[pos]);
            }
            for (; i < period; ++ i, ++ pos) {
                outputs[period - i].push_back(s[pos]);
            }
        }
        
        for (int k = 0; k < numRows; ++ k) {
            for (int i = 0; i < outputs[k].size(); i ++) {
                res.push_back(outputs[k][i]);
            }
        }
        return res;
    };
};

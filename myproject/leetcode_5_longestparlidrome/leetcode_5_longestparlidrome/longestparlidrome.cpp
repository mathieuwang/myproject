//
//  longestparlidrome.cpp
//  leetcode_5_longestparlidrome
//
//  Created by mathieuwang on 15/8/30.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int ssize = (int) s.size();
        int maxpos = 0;
        int maxlength = 0;
        int maxoffset = 0;
        
        bool oddtype = true;
        
        for (int pos = 0; pos < ssize; ++ pos) {
            int currlength = 1;
            int offset = 0;
            int maxpossibleoffset = pos;
            if (ssize < pos * 2) {
                maxpossibleoffset = ssize - pos;
            }
            for (offset = 1; offset <= maxpossibleoffset; ++ offset) {
                if (s[pos - offset] != s[pos + offset]) {
                    break;
                }
                currlength = currlength + 2;
            }
            --offset;
            if (maxlength < currlength) {
                maxlength = currlength;
                maxpos = pos;
                maxoffset = offset;
            }
        }
        
        for (int pos = 0; pos < ssize - 1; ++ pos) {
            int currlength = 0;
            int offset = 0;
            int maxpossibleoffset = pos + 1;
            if (ssize < pos * 2 + 2) {
                maxpossibleoffset = ssize - pos - 1;
            }
            for (offset = 1; offset <= maxpossibleoffset; ++ offset) {
                if (s[pos - offset + 1] != s[pos + offset]) {
                    break;
                }
                currlength = currlength + 2;
            }
            --offset;
            if (maxlength < currlength) {
                oddtype = false;
                maxlength = currlength;
                maxpos = pos;
                maxoffset = offset;
            }
        }
        
        if (oddtype) {
            //res = (s, maxpos - maxoffset, maxpos + maxoffset);
            for (int idx = maxpos - maxoffset; idx < maxpos + maxoffset + 1; ++ idx) {
                res.push_back(s[idx]);
            }
        }
        else {
            //res = string(s, maxpos - maxoffset + 1, maxpos + maxoffset);
            for (int idx = maxpos - maxoffset + 1; idx < maxpos + maxoffset + 1; ++ idx) {
                res.push_back(s[idx]);
            }
        }
        
        return res;
    };
};

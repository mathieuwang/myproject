//
//  regularexpressionmatching.cpp
//  leetcode_10_regexpmatching
//
//  Created by mathieuwang on 15/9/1.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

//'\0' for the end of string

class Solution {
public:
    bool isMatch(string s, string p) {
        int pos1 = 0;
        int pos2 = 0;
        
        int size1 = (int) s.length();
        int size2 = (int) p.length();
        
        if (size1 == 0 && size2 == 0) {
            return true;
        }
        
        while (pos1 != size1 && pos2 != size2) {
            if (singleMatch(s[pos1], p[pos2])) {
                if (pos1 < size1 - 2 && s[pos1 +1] == '*') {
                    
                }
            }
        }
        
    }
private:
    bool singleMatch (char s, char p) {
        if (s == p || s == '.' || p == '.') {
            return true;
        }
        return false;
    }
};
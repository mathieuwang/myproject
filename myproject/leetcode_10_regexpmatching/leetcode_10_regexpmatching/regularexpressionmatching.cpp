//
//  regularexpressionmatching.cpp
//  leetcode_10_regexpmatching
//
//  Created by mathieuwang on 15/9/1.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

//'\0' for the end of string

class Solution {
public:
    bool isMatch(string s, string p) {
        bool res = false;
        
        if (s.size() == 0 && p.size() == 0) {
            return true;
        }
        
        if (s.size() == 0) {
            string tmp = s;
            s = p;
            p = tmp;
        }
        
        module = (int) p.size() + 1;
        vector<int> tmp((s.size() + 1) * (p.size() + 1), -1);//0=false, 1=true;
        lookuptable.swap(tmp);
        
        res = subMatch(s, p, 0, 0);
        
        return res;
    }
private:
    bool singleMatch (char s, char p) {
        if (s == p || s == '.' || p == '.') {
            return true;
        }
        return false;
    }
    
    bool subMatch (const string & s, const string & p, int begin1, int begin2) {
        int size1 = (int) s.size();
        int size2 = (int) p.size();
        
//        int debug = 0;
//        if (begin1 == 3 && begin2 == 2) {
//            debug = 1;
//        }
        //first, look up in the table
        int lookup = lookuptable[begin1 * module + begin2];
        if (lookup != -1) {
            return (bool) lookup;
        }
        
        if (begin1 == size1 && begin2 == size2) {
            setlookuptable(begin1, begin2, true);
            return true;
        }
        
        if (begin1 == size1) {
            if (begin2 == size2 - 1 || p[begin2 + 1] != '*') {
                setlookuptable(begin1, begin2, false);
                return false;
            }
            bool res = subMatch(s, p, begin1, begin2 + 2);
            setlookuptable(begin1, begin2, res);
            return res;
        }
        
        if (begin2 == size2) {
            if (begin1 == size1 - 1 || s[begin1 + 1] != '*') {
                setlookuptable(begin1, begin2, false);
                return false;
            }
            bool res = subMatch(s, p, begin1 + 2, begin2);
            setlookuptable(begin1, begin2, res);
            return res;
        }
        
        //first digit mismatch
        if ((begin1 == size1 - 1 || s[begin1 + 1] != '*') && (begin2 == size2 - 1 || p[begin2 + 1] != '*')) {
            if (!singleMatch(s[begin1], p[begin2])) {
                setlookuptable(begin1, begin2, false);
                return false;
            }
            else
            {
                bool res = subMatch(s, p, begin1 + 1, begin2 + 1);
                setlookuptable(begin1, begin2, res);
                return res;
            }
        }
        
        //recursive
        if (s[begin1 + 1] == '*' && p[begin2 + 1] != '*') {
            if (subMatch(s, p, begin1 + 2, begin2)) {
                setlookuptable(begin1, begin2, true);
                return true;
            }
            bool bmatch = false;
            int currpos = begin2;
            while (currpos <= size2) {
                if (currpos < size2 - 1 && p[currpos + 1] == '*') {
                    if (subMatch(s, p, begin1, currpos)) {
                        bmatch = true;
                    }
                    break;
                }
                else if (!singleMatch(s[begin1], p[currpos])) {
                    if (subMatch(s, p, begin1 + 2, currpos)) {
                        bmatch = true;
                    }
                    break;
                }
                else {
                    if (subMatch(s, p, begin1, currpos)) {
                        bmatch = true;
                        break;
                    }
                    currpos ++;
                }
            }
            setlookuptable(begin1, begin2, bmatch);
            return bmatch;
        }
        
        if (s[begin1 + 1] != '*' && p[begin2 + 1] == '*') {
            if (subMatch(s, p, begin1, begin2 + 2)) {
                setlookuptable(begin1, begin2, true);
                return true;
            }
            bool bmatch = false;
            int currpos = begin1;
            while (currpos < size1) {
                if (currpos < size1 - 1 && s[currpos + 1] == '*') {
                    if (subMatch(s, p, currpos, begin2)) {
                        bmatch = true;
                    }
                    break;
                }
                else if (!singleMatch(s[currpos], p[begin2])) {
                    if (subMatch(s, p, currpos, begin2 + 2)) {
                        bmatch = true;
                    }
                    break;
                }
                else {
                    
                    currpos ++;
                    if (subMatch(s, p, currpos, begin2)) {
                        bmatch = true;
                        break;
                    }
                }
            }
            setlookuptable(begin1, begin2, bmatch);
            return bmatch;
        }
        
        if (s[begin1 + 1] == '*' && p[begin2 + 1] == '*') {
            if (subMatch(s, p, begin1 + 2, begin2) || subMatch(s, p, begin1, begin2 + 2)) {
                setlookuptable(begin1, begin2, true);
                return true;
            }
            else {
                setlookuptable(begin1, begin2, false);
                return false;
            }
        }
        
        return false;
    }
    
    void setlookuptable (int pos1, int pos2, bool val) {
        if (val){
            lookuptable[pos1 * module + pos2] = 1;
        }
        else {
            lookuptable[pos1 * module + pos2] = 0;
        }
    }
    
    vector<int> lookuptable;
    int module;
    
};
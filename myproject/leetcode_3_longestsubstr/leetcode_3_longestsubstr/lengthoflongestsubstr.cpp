//
//  lengthoflongestsubstr.cpp
//  leetcode_3_longestsubstr
//
//  Created by mathieuwang on 15/8/28.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <map>

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = (int) s.size();
        if (size == 0) {
            return 0;
        }
        
        map<char, vector<int>> occurencemap;
        for (int i = 0; i < size; ++ i) {
            char thischar = s[i];
            if (occurencemap.find(thischar) != occurencemap.end()) {
                occurencemap[thischar].push_back(i);
            }
            else {
                vector<int> newvec = {i};
                occurencemap[thischar] = newvec;
            }
        }
        
        vector<vector<int>> lookuptable;
        //lookuptable[i][j] = the longest length a substr begins at j can be
        //without repeating the i-th char
        
        map<char, vector<int>>::iterator mcviter = occurencemap.begin();
        for (; mcviter != occurencemap.end(); ++mcviter) {
            vector<int> ocvec = mcviter->second;
            vector<int> sublookuptable(size);
            if (ocvec.size() < 2) {
                for (int ii = 0; ii < size; ii++) {
                    sublookuptable[ii] = size - ii;
                }
            }
            else {
                for (int ii = 0; ii <= ocvec[0]; ++ ii) {
                    sublookuptable[ii] = ocvec[1] - ii;
                }
                for (int idx = 0; idx < ocvec.size() - 2; idx ++) {
                    for (int ii = ocvec[idx] + 1; ii <= ocvec[idx + 1]; ++ ii) {
                        sublookuptable[ii] = ocvec[idx + 2] - ii;
                    }
                }
                for (int ii = ocvec[ocvec.size() - 2] + 1; ii <= size - 1; ++ ii) {
                    sublookuptable[ii] = size - ii;
                }
            }
            lookuptable.push_back(sublookuptable);
        }
        
        //debug
        for (int xx = 0; xx < lookuptable.size(); ++ xx) {
            for (int yy = 0; yy < lookuptable[xx].size(); ++ yy) {
                cout<<lookuptable[xx][yy]<<'\t';
            }
            cout<<endl;
        }
        
        int submax = 0;
        for (int beginpos = 0; beginpos < size; ++ beginpos) {
            int submin = size;
            for (int charidx = 0; charidx < lookuptable.size(); ++ charidx) {
                if (lookuptable[charidx][beginpos] < submin) {
                    submin = lookuptable[charidx][beginpos];
                }
            }
            if (submin > submax) {
                submax = submin;
            }
        }
        
        return submax;
        
    }
};

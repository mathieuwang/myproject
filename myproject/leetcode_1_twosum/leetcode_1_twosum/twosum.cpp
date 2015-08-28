//
//  twosum.cpp
//  leetcode_1_twosum
//
//  Created by mathieuwang on 15/8/28.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class numberlist {
public:
    numberlist(int n, int i) {
        num = n;
        index = i;
    };
    int num;
    int index;
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = (int) nums.size();
        vector<int> res;
        int idx1 = 0, idx2 = 0;
        
        hashsetconstructor(nums);
        
        bool bfound = false;
        for (; idx1 < size - 1; ++ idx1) {
            int validnumber = target - nums[idx1];//the value that nums[idx2] should be
            int validresidule;
            if (validnumber >= 0) {
                validresidule = validnumber % size;
            }
            else {
                validresidule = (size - (-validnumber) % size) % size;
            }
            
            vector<numberlist> & nlist = numberhashset[validresidule];
            for (int ii = 0; ii < nlist.size(); ++ ii) {
                if (nlist[ii].num == validnumber) {
                    idx2 = nlist[ii].index;
                    if (idx2 != idx1) {
                        bfound = true;
                        break;
                    }
                }
            }

            if (bfound) {
                break;
            }
        }
        if (idx1 > idx2) {
            int tmp = idx1;
            idx1 = idx2;
            idx2 = tmp;
        }
        res.push_back(idx1 + 1);
        res.push_back(idx2 + 1);
        return res;
    }
    
private:
    
    vector<vector<numberlist>> numberhashset; //use a hash set to store the numbers
    
    void hashsetconstructor(vector<int>& nums) {
        int size = (int) nums.size();
        numberhashset.resize(size);
        
        for (int ind = 0; ind < nums.size(); ++ ind) {
            int thisnum = nums[ind];
            numberlist nl(thisnum, ind);
            int residule = -1;
            if (thisnum >= 0) {
                residule = thisnum % size;
            }
            else {
                residule = (size - (- thisnum) % size) % size;
            }
            numberhashset[residule].push_back(nl);
        }
    };
    
};

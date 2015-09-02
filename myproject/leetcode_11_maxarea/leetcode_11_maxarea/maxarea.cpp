//
//  maxarea.cpp
//  leetcode_11_maxarea
//
//  Created by mathieuwang on 15/9/2.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int hsize = (int) height.size();
        int ret = 0;
        
        int i = 0;
        int j = hsize - 1;
        
        while (i < j) {
            bool hjisbigger = false;
            if (height[i] < height[j]) hjisbigger = true;
            int area = (hjisbigger ? height[i] : height[j]) * (j - i);
            if (area > ret) {
                ret = area;
            }
            if (hjisbigger) {
                ++ i;
            }
            else {
                -- j;
            }
        }
        
        return ret;
    }
};
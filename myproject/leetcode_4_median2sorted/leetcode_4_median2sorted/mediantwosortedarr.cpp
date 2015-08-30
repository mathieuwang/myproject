//
//  mediantwosortedarr.cpp
//  leetcode_4_median2sorted
//
//  Created by mathieuwang on 15/8/28.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = (int) nums1.size();
        int size2 = (int) nums2.size();
        
        bool acsend = true;
        if ((size1 > 1 && nums1[0] > nums1[1]) || (size2 > 1 && nums2[0] > nums2[1])) {
            acsend = false;
        }

        if (size1 < size2) {
            return find_sub(nums2, nums1, 0, size2, 0, size1, acsend);
        }
        return find_sub(nums1, nums2, 0, size1, 0, size2, acsend);
    };
    
private:
    double find_sub(vector<int> & nums1, vector<int> & nums2, int s1, int e1, int s2, int e2, bool ascend) {
        //input should yield that e1 - s1 >= e2 - s2
        int size1 = e1 - s1;
        int size2 = e2 - s2;
        
        if (size1 < 7 && size2 < 7) {
            return trivialcase(nums1, nums2, s1, e1, s2, e2, ascend);
        }
        
        if (size1 > size2 * 3) {
            int deletesize = (int) ((size1 + 0.5) / 3);
            s1 = s1 + deletesize;
            e1 = e1 - deletesize;
        }
        else {
            int deletesize = (int) ((size2 - 0.5) / 2);
            if (((nums1[s1 + deletesize - 1] <= nums2[s2 + deletesize - 1]) && ascend)
                || ((nums1[s1 + deletesize - 1] > nums2[s2 + deletesize - 1]) && !ascend)) {
                s1 = s1 + deletesize;
            }
            else {
                s2 = s2 + deletesize;
            }
            if (((nums1[e1 - deletesize] <= nums2[e2 - deletesize]) && ascend)
                || ((nums1[e1 - deletesize] > nums2[e2 - deletesize]) && !ascend)) {
                e2 = e2 - deletesize;
            }
            else {
                e1 = e1 - deletesize;
            }
        }
        if (e1 - s1 < e2 - s2) {
            return find_sub(nums2, nums1, s2, e2, s1, e1, ascend);
        }
        return find_sub(nums1, nums2, s1, e1, s2, e2, ascend);
    };
    
    double trivialcase(vector<int> & nums1, vector<int> & nums2, int s1, int e1, int s2, int e2, bool ascend) {
        //remaining lengths no greater than 7
        vector<int> combinevec;
        int maxlength = e1 + e2 - s1 - s2;
        for (int i = 0; i < maxlength; ++ i) {
            if (s1 == e1) {
                combinevec.push_back(nums2[s2]);
                ++ s2;
            }
            else if (s2 == e2) {
                combinevec.push_back(nums1[s1]);
                ++ s1;
            }
            else {
                if (((nums1[s1] <= nums2[s2]) && ascend) || ((nums1[s1] > nums2[s2]) && !ascend)) {
                    combinevec.push_back(nums1[s1]);
                    ++ s1;
                }
                else {
                    combinevec.push_back(nums2[s2]);
                    ++ s2;
                }
            }
        }
        
        if (maxlength % 2 == 0) {
            int tmp = (int) ((maxlength * 1.0 - 1) / 2.0 );
            return (combinevec[tmp] + combinevec[tmp + 1]) / 2.0;
        }
        else {
            return combinevec[(int) (maxlength * 1.0 / 2.0)];
        }
    }
    
};

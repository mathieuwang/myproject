//
//  main.cpp
//  leetcode_4_median2sorted
//
//  Created by mathieuwang on 15/8/28.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <iostream>
#include "mediantwosortedarr.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
//    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 9, 11, 13, 15, 17, 19, 21, 22};
//    vector<int> nums2 = {8, 10, 12, 14, 16, 18, 20};
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4, 5, 6};
    Solution sl;
    double res = sl.findMedianSortedArrays(nums1, nums2);
    std::cout << "Median is " << res << endl;
    return 0;
}

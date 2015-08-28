//
//  main.cpp
//  leetcode_1_twosum
//
//  Created by mathieuwang on 15/8/28.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <iostream>
#include "twosum.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution newsolution;
//    vector<int> testnums = {2, 8, -1, 15, 9 , 5, 10};
//    int testtarget = 9;
    
    vector<int> testnums = {-1, -2, -3, -4, -5};
    int testtarget = -8;
    
    vector<int> testresult;
    testresult = newsolution.twoSum(testnums, testtarget);
    std::cout << "index1 = "<< testresult[0] <<"\t"<< "index2 = "<< testresult[1];
    return 0;
}

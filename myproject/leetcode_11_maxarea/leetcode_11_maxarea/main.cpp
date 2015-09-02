//
//  main.cpp
//  leetcode_11_maxarea
//
//  Created by mathieuwang on 15/9/2.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <iostream>
#include <vector>
#include "maxarea.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> testvec = {1, 2, 1};
    Solution sl;
    int output = sl.maxArea(testvec);
    std::cout << output << endl;
    return 0;
}

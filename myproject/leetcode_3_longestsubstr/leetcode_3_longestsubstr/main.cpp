//
//  main.cpp
//  leetcode_3_longestsubstr
//
//  Created by mathieuwang on 15/8/28.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <iostream>
#include "lengthoflongestsubstr.cpp"

int main(int argc, const char * argv[]) {
    Solution sl;
    string input = "abcdefgh";
    int res = sl.lengthOfLongestSubstring(input);
    std::cout << res << endl;
    return 0;
}

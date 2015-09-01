//
//  main.cpp
//  leetcode_10_regexpmatching
//
//  Created by mathieuwang on 15/9/1.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <iostream>
#include "regularexpressionmatching.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    const char * teststr1 = "abc";
    const char * teststr2 = "d*a*b*c";
    Solution sl;
    bool ret = sl.isMatch(teststr1, teststr2);
    if (ret) {
        std::cout << "match\n";
    }
    else {
        std::cout << "mismatch\n";
    }
    return 0;
}

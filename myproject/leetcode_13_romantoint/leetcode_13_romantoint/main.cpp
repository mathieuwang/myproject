//
//  main.cpp
//  leetcode_13_romantoint
//
//  Created by mathieuwang on 15/9/2.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <iostream>
#include <string>
#include "romantoint.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    string teststr = "MDCCCLXXXIV";
    Solution sl;
    int ret = sl.romanToInt(teststr);
    
    std::cout << "The int of " << teststr << " is " << ret << endl;
    return 0;
}

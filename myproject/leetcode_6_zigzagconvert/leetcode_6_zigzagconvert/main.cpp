//
//  main.cpp
//  leetcode_6_zigzagconvert
//
//  Created by mathieuwang on 15/8/30.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <iostream>
#include <string>
#include "zigzagconvert.cpp"
using namespace std;

//void zigzagoutput(string s, int numRows) {
//    int period = numRows * 2 - 2;
//    vector<string> outputs(numRows);
//    
//}

int main(int argc, const char * argv[]) {
    // insert code here...
    //string teststr = "PAYPALISHIRING";
    string teststr = "ABC";
    int testint = 2;
    
    //zigzagoutput(teststr, testint);
    
    Solution sl;
    string res;
    res = sl.convert(teststr, testint);
    
    std::cout << res << endl;
    return 0;
}


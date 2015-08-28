//
//  main.cpp
//  leetcode_2_addtwonumbers
//
//  Created by mathieuwang on 15/8/28.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <iostream>
#include "addtwonumbers.cpp"
#include <vector>

using namespace std;


//input is in the normal order
ListNode * lnconstructor (vector<int> & input)
{
    ListNode * prev = NULL;
    for (int i = 0; i < input.size(); ++ i) {
        ListNode * thisdigit = new ListNode(input[i]);
        thisdigit->next = prev;
        prev = thisdigit;
    }
    return prev;
};

void outputlistnode (ListNode * ln) {
    if (ln) {
        cout<<ln->val;
        ln = ln->next;
    }
    while (ln) {
        cout<<"->"<<ln->val;
        ln = ln->next;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> input1 = {};
    vector<int> input2 = {};
    ListNode* ln1 = lnconstructor(input1);
    ListNode* ln2 = lnconstructor(input2);
    
    outputlistnode(ln1);
    cout<<endl;
    outputlistnode(ln2);
    cout<<endl;
    
    Solution sl;
    ListNode* res = sl.addTwoNumbers(ln1, ln2);

    outputlistnode(res);
    
    
    return 0;
};




//
//  addtwonumbers.cpp
//  leetcode_2_addtwonumbers
//
//  Created by mathieuwang on 15/8/28.
//  Copyright (c) 2015年 mathieuwang. All rights reserved.
//

#include <stdio.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * result = new ListNode(0);
        ListNode * list1 = l1;
        ListNode * list2 = l2;
        ListNode * thisdigit = result;
        ListNode * nextdigit = NULL;
        while (list1 != NULL || list2 != NULL) {
            int num1 = 0;
            int num2 = 0;
            
            if (list1 != NULL) {
                num1 = list1->val;
            }
            if (list2 != NULL) {
                num2 = list2->val;
            }
            
            if (thisdigit->next == NULL) {
                ListNode * tmp = new ListNode(0);
                thisdigit->next = tmp;
                thisdigit = tmp;
            }
            else {
                thisdigit = thisdigit->next;
            }
            
            int sum = num1 + num2 + thisdigit->val;
            nextdigit = NULL;
            
            if (sum < 10) {
                thisdigit->val = sum;
            }
            else {
                thisdigit->val = sum - 10;
                nextdigit = new ListNode(1);
            }
            
            //proceed
            thisdigit->next = nextdigit;
            
            if (list1 != NULL) {
                list1 = list1->next;
            }
            
            if (list2 != NULL) {
                list2 = list2->next;
            }
        }
        thisdigit = result;
        result = result->next;
        delete thisdigit;
        
        return result;
    }
};

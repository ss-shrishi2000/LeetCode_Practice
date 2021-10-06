PROBLEM STATEMENT :- You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes 
contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
  
  Example 1:-
    Input: l1 = [7,2,4,3], l2 = [5,6,4]
    Output: [7,8,0,7]
    
  Example 2:-
    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [8,0,7]
    
SOLUTION :-
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
    vector<int> num1, num2;
     int sum = 0, carry = 0;
     ListNode * t1 = l1, * t2 = l2;
    while(t1) 
    {
        nums1.push_back(t1->val);
        t1 = t1->next;
    }
    while(t2) 
    {
        nums2.push_back(t2->val);
        t2 = t2->next;
    }

    int m = nums1.size(), n = nums2.size();
    ListNode *head = nullptr , *p = nullptr;

    for(int i = m - 1, j = n - 1; i >= 0 || j >= 0 || carry > 0; i--, j--)
    {
        sum = carry;
        if(i >= 0) 
            sum += nums1[i];

        if(j >= 0)
            sum += nums2[j];

        carry = sum / 10;

        p = new ListNode(sum%10);
        p->next = head;
        head = p;
    }

    return head;
    }
};

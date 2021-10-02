
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the
values in the list's nodes (i.e., only nodes themselves may be changed.)
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Input: head = []
Output: []

Input: head = [1]
Output: [1]

Solution :-
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
    ListNode* swapPairs(ListNode* head)
    {
        if(!head)
            return head;
        
        ListNode *tmp=head;
        while(tmp && tmp->next)
        {
            ListNode* r1=tmp->next;
            int ex;
            ex=r1->val;
            r1->val=tmp->val;
            tmp->val=ex;
            tmp=tmp->next->next;
        }
        return head;
    }
};
  
  
  
  
  
  
  
  
  
  
  
  
  

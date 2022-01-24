PROBLEM STATEMENT :-
  Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.You should preserve the
  original relative order of the nodes in each of the two partitions.
  
  Sample Input: 
         head = [1,4,3,2,5,2], x = 3
         Output: [1,2,2,4,3,5]
         
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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode *small_ptr = new ListNode(0);
        ListNode *great_ptr = new ListNode(0);
        ListNode *tmp = head;
        ListNode *sm = small_ptr , *gr = great_ptr;
        while(tmp)
        {
            if(tmp->val<x)
            {
                small_ptr->next=tmp;
                small_ptr=small_ptr->next;
            }
            else
            {
                great_ptr->next =tmp;
                great_ptr=great_ptr->next;
            }
            
            tmp=tmp->next;
        }
        great_ptr->next=NULL;
        small_ptr->next=gr->next;
        return sm->next;
    }
};

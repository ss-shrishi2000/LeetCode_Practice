PROBLEM STATEMENT:-
  Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
  
  Sample Input 1:-
    Input: head = [1,2,6,3,4,5,6], val = 6
    Output: [1,2,3,4,5]
    
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
    ListNode* removeElements(ListNode* head, int val)
    {
        if(head==NULL)
            return NULL;
        
        ListNode *tmp=head;
        if(tmp->val==val)
        {
            while(head->val==val && head->next!=NULL)
                       head=head->next;
        }
        
        while(tmp->next!=NULL)
        {
            if(tmp->next->val==val)
            {
                tmp->next=tmp->next->next;
            }
            else
                tmp=tmp->next;
        }
        if(tmp !=NULL && tmp->val==val)
            return NULL;
        
        return head;
    }
};
 

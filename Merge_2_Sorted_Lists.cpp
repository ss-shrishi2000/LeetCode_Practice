PROBLEM STATEMENT :-
  Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.
  
  Sample Input:- l1 = [1,2,4], l2 = [1,3,4]
         Output: [1,1,2,3,4,4]
  Sample 2:- l1= [1] ,l2 = []
          Output:- [1]
          
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *tmp1=l1;
        ListNode *tmp2=l2;
        ListNode *s=new ListNode(0);
        ListNode *dummy =s;
        while(tmp1!=NULL || tmp2!=NULL)
        {
            if(tmp1==NULL)
            {
                if(tmp2)
                {
                    s->next=tmp2;
                    s=s->next;
                    tmp2=tmp2->next;
                }
                else
                    break;
            }
            
            else if(tmp2==NULL)
            {
                if(tmp1)
                {
                    s->next=tmp1;
                    s=s->next;
                    tmp1=tmp1->next;
                }
                else
                    break;
            }
            
            else if(tmp1 && tmp2 && tmp1->val <= tmp2->val)
            {
                s->next=tmp1;
                s=s->next;
                tmp1=tmp1->next;
            }
            else if(tmp2)
            {
                s->next=tmp2;
                s=s->next;
                tmp2=tmp2->next;
            }
        }
        s->next=NULL;
        return dummy->next;
    }
};
  

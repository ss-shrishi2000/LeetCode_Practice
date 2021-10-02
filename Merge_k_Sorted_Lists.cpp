PROBLEM STATEMENT :-
  You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.Merge all the linked-lists into one sorted linked-list and return it.
  
  Example 1:
           Input: lists = [[1,4,5],[1,3,4],[2,6]]
           Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:  1->1->2->3->4->4->5->6
  
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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        vector<int> val;
        for(int i=0;i<lists.size();i++)
        {
            auto tmp=lists[i];
            while(tmp)
            {
            val.push_back(tmp->val);
            tmp=tmp->next;
            }
        }
        ListNode * s=new ListNode(0);
        ListNode *dummy =s;
        sort(val.begin(),val.end());
        for(int i=0;i<val.size();i++)
        {
            s->next = new ListNode(val[i]);
            s=s->next;
        }
        s->next=NULL;
        return dummy->next;
    }
};
                                 

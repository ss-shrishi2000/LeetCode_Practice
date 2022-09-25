PROBLEM STATEMENT :-
  Given the head of a linked list, rotate the list to the right by k places.
  
  Input: head = [1,2,3,4,5], k = 2
  Output: [4,5,1,2,3]
  
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
    int getsize(ListNode* head)
    {
        ListNode* tmp = head;
        int t = 0;
        while(tmp)
        {
            t++;
            tmp = tmp->next;
        }
        return t;
    }
    ListNode* rotateRight(ListNode* head, int k) 
    {
        int sz = getsize(head);
        // all places shift by x distance
        ListNode* n2 = new ListNode(0);
        if(head == NULL)
            return n2->next;
        
        vector<int> v;
        ListNode* tmp1 = head;
        while(tmp1)
        {
            v.push_back(tmp1->val);
            tmp1 = tmp1->next;
        }
        int r = v.size();
        k = k % r;
        rotate(v.begin(), v.begin() + r - k, v.end());
        
        ListNode* l1 = new ListNode(0);
        ListNode* dummy = l1;
        
        //l1 = l1->next;
        for(int j = 0; j < r; j++)
        {
            ListNode* n1 = new ListNode(v[j]);
            l1->next = n1;
            l1 = l1->next;
        }
        return dummy->next;
    }
};

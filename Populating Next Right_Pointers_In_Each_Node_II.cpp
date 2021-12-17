PROBLEM STATEMENT :- Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

 SOLUTION :-
   /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root==NULL)
            return NULL;
        
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) 
        {
            int size = q.size();
            int size1 = size;
            Node* store;
            while (size-- > 0)
            {
                Node* rem = q.front();
                if (size1-1 == size) 
                {
                    store = rem;
                } 
                else 
                {
                    rem->next = store;
                    store = rem;
                }
                q.pop(); 
                if (rem->right)
                    q.push(rem->right);
                
                if (rem->left)
                    q.push(rem->left);
            }
        }
        
        return root;
    }
};

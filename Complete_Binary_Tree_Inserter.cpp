PROBLEM STATEMENT :- A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes 
are as far left as possible. Design an algorithm to insert a new node to a complete binary tree keeping it complete after the insertion.
Implement the CBTInserter class:

CBTInserter(TreeNode root):- Initializes the data structure with the root of the complete binary tree.
int insert(int v):- Inserts a TreeNode into the tree with value Node.val == val so that the tree remains complete, and returns the value of the parent 
of the inserted TreeNode.
TreeNode get_root():- Returns the root node of the tree.
  
  SOLUTION :-
    
    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
public:
    TreeNode* r1;
    CBTInserter(TreeNode* root) {
        r1 = root;
    }
    int insert(int val)
    {
        queue<TreeNode*> q;
        int ans;
        TreeNode* n1 = new TreeNode(val);
        q.push(r1);
        while(!q.empty())
        {
            TreeNode* t = q.front();
            q.pop();
            if(t->left == NULL)
            {
                t->left = n1;
                ans = t->val;
                break;
            }
            else
            {
                q.push(t->left);
            }
            if(t->right == NULL)
            {
                t->right = n1;
                ans = t->val;
                break;
            }
            else
            {
                q.push(t->right);
            }
        }
        return ans;
    }
    
    TreeNode* get_root() {
        return r1;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */

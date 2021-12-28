
PROBLEM STATEMENT :- Given the root of a binary tree, invert the tree, and return its root.

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Input: root = [2,1,3]
Output: [2,3,1]

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
class Solution {
public:
    void mirror(TreeNode * root)
    {
        if(root==NULL)
            return ;
        else
        {
        mirror(root->left);
        mirror(root->right);
        
        struct TreeNode *tmp;
        tmp=root->left;
        root->left=root->right;
        root->right=tmp;
            
        }
    }
    TreeNode* invertTree(TreeNode* root) 
    {
       mirror(root);
       return root;
    }
};

PROBLEM STATEMENT :- Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along 
the path equals targetSum. A leaf is a node with no children.
  
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
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root==NULL)
            return false;
        
        if(root->val == targetSum && root->left==NULL && root->right==NULL)
            return true;
        
        return hasPathSum(root->left , targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
        
    }
};

 

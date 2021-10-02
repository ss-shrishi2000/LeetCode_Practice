PROBLEM STATEMENT :-
  Given the root of a binary tree, return the inorder traversal of its nodes' values.
  
  Example 1:-
  Input: root = [1,null,2,3]
  Output: [1,3,2]
  
  Example 2:
  Input: root = []
  Output: []
  
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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode * cur=root;
        while(cur!=NULL || s.empty()!=true)
        {
            while(cur!=NULL)
            {
                s.push(cur);
                cur=cur->left;
            }
            cur=s.top();
            s.pop();
            ans.push_back(cur->val);
            cur=cur->right;
        }
        
        return ans;
    }
};

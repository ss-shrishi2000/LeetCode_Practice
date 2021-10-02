PROBLEM STATEMENT :-
  Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, 
  construct and return the binary tree.
    
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]

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
  
  class Solution 
  {
public:
    int index; // record the index of each element in inorder list
    map<int, int> table;  // root index in inorder list
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        index = 0;                                        // tree root is the first element
        for(int i = 0; i < inorder.size(); ++i)
            table[inorder[i]] = i;
        
        return divideAndConquer(preorder, 0, inorder.size() - 1);
    }
	 
    TreeNode* divideAndConquer(vector<int>& pre, int l, int r)
    {
        if(l > r) 
            return NULL;
        TreeNode * head = new TreeNode(pre[index++]);
        
        int root = table[head->val];
        
        head->left = divideAndConquer(pre, l, root - 1);
        
        head->right = divideAndConquer(pre, root + 1, r);
        
        return head;
    }
};

 

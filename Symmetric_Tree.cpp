PROBLEM STATEMENT :- Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
 Example 1:
 Input: root = [1,2,2,3,4,4,3]
 Output: true
  
 Example 2:
 Input: root = [1,2,2,null,3,null,3]
 Output: false



struct TreeNode
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool mirror(TreeNode *r1,TreeNode *r2)
    {
        if(r1==nullptr && r2==nullptr)
            return true;

        if(r1!=nullptr && r2!=nullptr && r1->val==r2->val)
            return mirror(r1->left,r2->right) && mirror(r1->right,r2->left);

        return false;
    }
    bool isSymmetric(TreeNode* root)
    {
        if(root==nullptr)
            return true;

        return mirror(root->left,root->right);
    }
};

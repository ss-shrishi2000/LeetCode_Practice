PROBLEM STATEMENT :-
Given two binary search trees root1 and root2. Return a list containing all the integers from both trees sorted in ascending order.

Example 1:
Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Example 2:
Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]

Example 3:
Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]

Example 4:
Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]


SOLUTION :- /**
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
    map<int,int> hashmap;
    void dfs(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        hashmap[root->val]++;
        
        if(root->left)
            dfs(root->left);
        
        if(root->right)
            dfs(root->right);
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        
        dfs(root1);
        dfs(root2);
        vector<int> vec;
        for(auto it = hashmap.begin();it!=hashmap.end();it++)
        {
            while(it->second > 0)
            {
            vec.push_back(it->first);
                it->second-=1;
            }
        }
        return vec;
    }
};

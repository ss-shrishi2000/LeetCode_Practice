Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.
The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).
  
Input: root = [5,2,-3]
Output: [2,-3,4]
Solution :-
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
   
    int dfs(TreeNode * root ,  map<int , int> & mp)
    {
        if(root==NULL)
            return 0;
        
        int sum=0;
        sum += dfs(root->left, mp);
        sum += root->val;
        sum += dfs(root->right , mp);
        mp[sum]++;
        return (sum);
    }
    vector<int> findFrequentTreeSum(TreeNode* root)
    {
        map<int , int> mp;
        dfs(root , mp);
        vector<int> vec;
        int mx=INT_MIN;
        
        for(auto it=mp.begin() ; it!=mp.end(); it++)
        {
            mx=max(mx,it->second);
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
             if(mx==it->second)
                vec.push_back(it->first);
        }
        return vec;
    }
};

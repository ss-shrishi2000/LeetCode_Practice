PROBLEM STATEMENT :- Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) 
respectively. The root of the tree is at (0, 0). The vertical order traversal of a binary tree is a list of top-to-bottom orderings
for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same 
row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
  
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
    vector<vector<int>> r;
    static bool cmp(pair<int, int>& p1, pair<int, int>& p2)
    {
        if(p1.first == p2.first)
        return (p1.second < p2.second);

        return (p1.first < p2.first);
    }
    void dfs(TreeNode* root, map<int, vector<pair<int, int>>>& mp, int ind, int height)
    {
        if(root == NULL)
        return;

        mp[ind].push_back({height, root->val});
        dfs(root->left, mp, ind-1, height + 1);
        dfs(root->right, mp, ind+1, height + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int, vector<pair<int,int>>> mp;
        dfs(root, mp, 0, 0);
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            sort(it->second.begin(), it->second.end(), cmp);
            vector<int> t;
            for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
            {
                t.push_back(it2->second);
            }
            r.push_back(t);
        }
        return r;
    }
};

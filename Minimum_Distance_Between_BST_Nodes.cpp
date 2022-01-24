PROBLEM STATEMENT :-
  Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.
  
  Example 1:-
  Input: root = [1,0,48,null,null,12,49]
  Output: 1
    
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
    int minDiffInBST(TreeNode* root) 
    {
        queue<TreeNode *> q;
        q.push(root);
        set<int> s;
        s.insert(root->val);
        bool f=false;
        int ans;
        while(q.empty()==false)
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                s.insert(tmp->val);
                
                if(tmp->left)
                {
                    q.push(tmp->left);
                }
                if(tmp->right)
                {
                    q.push(tmp->right);
                }
            }
        }
        vector<int> vec;
        ans=INT_MAX;
        for(auto it=s.begin();it!=s.end();it++)
        {
            vec.push_back(*it);
        }
        for(int i=0;i<vec.size()-1;i++)
        {
            ans = min(ans , vec[i+1]-vec[i]);
        }
        return ans;
    }
};

RUNTIME :- 4 ms using level-order traversal for the Binary Search Tree.
  
  
  SOLUTION -2 :-
    
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
    int minDiffInBST(TreeNode* root)
    {
        int min = INT_MAX,val = -111111110;                // min for minimum differense , val for value of previous node 
      stack <TreeNode*> ps;
        	
      while(!ps.empty() || root != NULL)
      { 
        if(root != NULL)
        {
            ps.push(root);
            root=root->left;
        }
        else
        {
            root = ps.top();
            
            ps.pop();
            
            if((root->val - val) < min) 
                       min =  root->val - val;                //if current differense more less than previous
            
            val = root->val;
            
            root = root->right;
        }
      }
      return min;       
    }
};

RUNTIME :- 0 ms using Stack based approach


    
    

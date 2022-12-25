PROBLEM STATEMENT :-
  You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak 
  at the same time, so multiple "croak" are mixed. Return the minimum number of different frogs to finish all the croaks in the given string.
  A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a 
  croak. If the given string is not a combination of a valid "croak" return -1.

 

Example 1:
Input: croakOfFrogs = "croakcroak"
Output: 1 
Explanation: One frog yelling "croak" twice.
  
Example 2:
Input: croakOfFrogs = "crcoakroak"
Output: 2 
Explanation: The minimum number of frogs is two. 
The first frog could yell "crcoakroak".
The second frog could yell later "crcoakroak".
  
  
SOLUTION :-
  
  class Solution {
public:
    bool dfs(int src, vector<vector<int>>& graph, vector<int>& vis, vector<int>& mpvis)
    {
        if(mpvis[src])
        return 1;

        if(vis[src])
        return 0;

        vis[src] = 1;
        mpvis[src] = 1;
        for(auto &x: graph[src])
        {
            if(dfs(x, graph, vis, mpvis))
            return 1;
        }

        mpvis[src] = 0;
        return 0;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> vis(n,0), mpvis(n,0);
        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            if(!dfs(i, graph, vis, mpvis))
            ans.push_back(i);
        }
        return ans;
    }
};

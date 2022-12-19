PROBLEM STATMENT :- There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 
2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a 
terminal node (or another safe node).
Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
  
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

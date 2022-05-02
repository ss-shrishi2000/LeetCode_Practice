PROBLEM STATEMENT :- 
  
  There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents 
  a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.You are given an initial 
  computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected 
  computers to make them directly connected.
  Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
    
Example 1:
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
  
  SOLUTION :-
    
    class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &adj, int node, vector<bool> &vis)
    {
        if(vis[node])
            return;
        
        vis[node]=true;
        for(auto it : adj[node])
        {
            if(vis[it]==false)
            {
                dfs(adj, it, vis);
            }
        }
    }
    
    int calc(vector<vector<int>> connections, int n, int m)
    {
        int component = 0;
        // where m = total number of edges = connections.size();
        vector<bool> vis(n, false);
        unordered_map<int, vector<int>> graph;
        int edge = 0;
        for(int i=0; i<m; i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
            edge++;
        }
        for(int i=0; i<n; i++)
        {
            if(vis[i]==false)
            {
                component++;
                dfs(graph, i, vis);
            }
        }
        
        if(edge < n-1)
            return -1;
        
        int x = edge - (n - component);
        if(x>=component-1)
            return component-1;
        
        return -1;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        int ans = calc(connections, n, m);
        return ans;
    }
};

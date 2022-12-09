PROBLEM STATEMENT :- You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where 
roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities 
graph is not necessarily connected.
The score of a path between two cities is defined as the minimum distance of a road in this path.
Return the minimum possible score of a path between cities 1 and n.

Note:
A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.
  
  SOLUTION :-
    
    class Solution {
public:
    void dfs(vector<pair<int,int>> gr[], map<int, bool>& vis, int src, int& m)
    {
        for(auto it: gr[src])
        {
            m = min(m, it.second);
        }

        vis[src] = 1;
        for(auto it:gr[src])
        {
            if(vis[it.first] == false)
            dfs(gr, vis, it.first, m);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) 
    {
        vector<pair<int, int>> gr[100005];
        //vector<pair<int, int>> cst[100005];

        map<int, bool> vis;

        for(int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0], v = roads[i][1], c = roads[i][2];
            gr[u].push_back({v, c});
            gr[v].push_back({u, c});
        }
        int m = INT_MAX;
        dfs(gr, vis, 1, m);

        return m;
    }
};

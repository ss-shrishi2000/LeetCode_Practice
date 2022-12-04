PROBLEM STATEMENT :-
  You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
  The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from 
  node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1. You are also given two integers node1 and node2.
  Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to 
  that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if 
  no possible answer exists, return -1. Note that edges may contain cycles.
    
  Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
  Output: 2
  Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
  The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.
    
    SOLUTION :-
      
      class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        int n = edges.size();
        vector<vector<int>> graph(n+100);
        for(int i = 0; i < n; i++)
        {
            int u = i, v = edges[i];
            if(v == -1)
            continue;

            graph[u].push_back(v);
        }

        unordered_map<int, int> dist;
        unordered_map<int, bool> vis;
        queue<int> q;
        int src1 = node1;
        q.push(src1);
        vis[src1] = 1;
        dist[src1] = 0;

        while(!q.empty())
        {
            int tp = q.front();
            q.pop();
          //  cout<<tp<<endl;
            for(auto it = graph[tp].begin(); it != graph[tp].end(); it++)
            {
                if(vis[*it]==0)
                {
                    q.push(*it);
                    dist[*it] = dist[tp] + 1;
                    vis[*it] = 1;
                }
            }
        }
        /*
        for(auto it: dist)
        cout<<it.first<<" "<<it.second<<endl;
        */

        unordered_map<int, int> dist2;
        unordered_map<int, bool> vis2;
        int src2 = node2;
        q.push(src2);
        vis2[src2] = 1;
        dist2[src2] = 0;
        set<int> st;

        while(!q.empty())
        {
            int tp = q.front();
            q.pop();
            //cout<<tp<<endl;
            for(auto it = graph[tp].begin(); it != graph[tp].end(); it++)
            {
                if(vis2[*it]==0)
                {
                    q.push(*it);
                    dist2[*it] = dist2[tp] + 1;
                    vis2[*it] = 1;
                }
            }
        }
        // index -> edge no. , value => dist from node1, dist from node2
        int ans = -1, dn1 = INT_MAX, dn2;
        vector<pair<int,int>> fin;
        for(int i = 0; i < n; i++)
        {
            if(dist.find(i)!=dist.end() && dist2.find(i) != dist2.end())
            fin.push_back({max(dist[i], dist2[i]), i});
        }
        for(int i = 0; i < fin.size(); i++)
        {
            if(fin[i].first < dn1)
            {
                dn1 = fin[i].first;
                ans = fin[i].second;
            }
        }
        return ans;
    }
};

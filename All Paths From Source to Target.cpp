Problem Statement :-
  Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1, and return them in any order.The graph 
  is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).
    
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

  Solution:-
    class Solution 
    {
    public:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<vector<int>> &graph , int curr_node , int dest)
    {
        tmp.push_back(curr_node);
        if(curr_node==dest)
            res.push_back(tmp);
        else
        {
            for(auto it=graph[curr_node].begin();it!=graph[curr_node].end();it++)
            {
                dfs(graph , *it , dest );
            }
        }
        tmp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        dfs(graph , 0 , graph.size()-1);
        return res;
    }
};
 

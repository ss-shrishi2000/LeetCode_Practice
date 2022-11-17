PROBLEM STATEMENT :- There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and 
city b is connected directly with city c, then city a is connected indirectly with city c. A province is a group of directly or indirectly 
connected cities and no other cities outside of the group. You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith 
city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

SOLUTION :-

class Solution {
public:
    int cc = 0;
    void dfs(int src, map<int, set<int>> mp, map<int, bool>& vis, int& cc)
    {
        vis[src] = 1;
        for(auto it = mp[src].begin(); it != mp[src].end(); it++)
        {
            if(vis[*it] == false)
            {
                dfs(*it, mp, vis, cc);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        map<int, set<int>> mp;
        int n = isConnected.size();
        
        for(int i = 0; i < isConnected.size(); i++)
        {
            for(int j = 0; j < isConnected[0].size(); j++)
            {
                if(isConnected[i][j] == 1)
                {
                    int x = i+1, y = j+1;
                    mp[x].insert(y);
                    mp[y].insert(x);
                }
            }
        }
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            set<int> s = it->second;
            for(auto it2 = s.begin(); it2 != s.end(); it2++)
            {
                cout<<(*it2)<<" ";
            }
            cout<<endl;
        }
        map<int, bool> vis;
        for(int i = 1; i <= n; i++)
        {
            if(vis[i]==false)
            {
                dfs(i, mp, vis, cc);
                cc++;
            }
        }
        return cc;
    }
};

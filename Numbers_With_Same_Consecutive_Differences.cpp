PROBLEM STATEMENT :- Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. 
  You may return the answer in any order. Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.
  
Example 1:

Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
  
  SOLUTION :-
    
    class Solution {
public:
    void dfs(vector<vector<int>>& gr, map<int, bool>& vis, vector<string>& v1, int i, int n, string s)
    {
        //vis[i] = 1;
        
        if(s.size() == n)
        {
            v1.push_back(s);
            return;
        }

        s += to_string(i);

        for(auto it = gr[i].begin(); it != gr[i].end(); it++)
        {
            //if(!vis[*it])
            dfs(gr, vis, v1, *it, n, s);
        }
        //vis[i] = 0;
    }
    vector<int> numsSameConsecDiff(int n, int k) 
    {
        vector<vector<int>> gr(105);
        for(int i = 0; i <= 9; i++)
        {
            for(int j = 0; j <= 9; j++)
            {
                if(abs(i - j) == k)
                {
                    gr[i].push_back(j);
                    gr[j].push_back(i);
                }
            }
        }
        vector<string> d;
        for(int i = 1; i <= 9; i++)
        {
            map<int, bool> vis;
            string p = "";
            dfs(gr, vis, d, i, n, p);
        }
        vector<int> t;
        set<int> st;
        for(int i = 0; i < d.size(); i++)
        {
            int x = stoi(d[i]);
            st.insert(x);
        }
        for(auto it:st)
        t.push_back(it);

        return t;
    }
};

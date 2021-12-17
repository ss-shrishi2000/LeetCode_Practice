PROBLEM STATEMENT :-
  You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server.
  Two servers are said to communicate if they are on the same row or on the same column. Return the number of servers that communicate with any other server.
    
Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.
  
Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.
  
  Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. 
The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.
  
  SOLUTION :-
    class Solution {
public:
    void dfs(vector<vector<int>>& grid , int i , int j , int& cnt)
    {
        if(grid[i][j]==1)
        {
            cnt+=1;
            grid[i][j]=0;
            
            for(int k=0;k<grid.size();k++)
            {
                if(grid[k][j]==1)
                    dfs(grid , k , j ,cnt);
            }
            
            for(int m = 0; m < grid[0].size() ; m++)
            {
                if(grid[i][m] == 1)
                    dfs(grid , i , m , cnt);
            }
        }
    }
    int countServers(vector<vector<int>>& grid) 
    {
        vector<vector<int>> rows , columns;
        int m = grid.size() , n = grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int cnt=0;
                    dfs(grid , i , j , cnt);
                    if(cnt > 1)
                        ans += cnt;
                }
            }
        }
        return ans;
    }
};


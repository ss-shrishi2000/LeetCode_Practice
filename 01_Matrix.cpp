PROBLEM STATEMENT :-
  Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
    
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

SOLUTION:-
  class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        queue<pair<int, int>> q;
        int n = mat.size();                      //rows
        int m = mat[0].size();                  //columns
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==1)
                {
                    cnt++; 
                    mat[i][j] = -10000;
                }
                else
                {
                    q.push({i,j});
                }
            }
        }
        if(cnt==0)
            return mat;
        
        int dirx[4] = {-1, 0, 1, 0};
        int diry[4] = {0, 1, 0, -1};
        
        while(!q.empty())
        {
            pair<int, int> pr = q.front();
            q.pop();
            int ff = pr.first;
            int ss = pr.second;
            for(int i=0; i<4; i++)
            {
                int x = ff + dirx[i];
                int y = ss + diry[i];
                
                if(!(x<0 || y<0 || x>=n || y>=m))
                {
                    if(mat[x][y] == -10000)
                    {
                        mat[x][y] = mat[ff][ss]+1;
                        q.push({x, y});
                    }
                }
            }
        }
        return mat;
    }
};

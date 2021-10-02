PROBLEM STATEMENT :-
  Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
  An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid 
  are all surrounded by water.

 

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
  
  
Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
  
  SOLUTION :-
    class Solution 
{
public:
    int check(vector<vector<char>>& grid , int i ,int j , vector<vector<int>>& visited , int &n , int &m)
    {
        if(i==n || i<0 || j==m || j<0 || grid[i][j]=='0' || visited[i][j]==1)
            return 0;
        
        visited[i][j]=1;
        
        return 1 + check(grid,i+1,j,visited,n,m) + check(grid,i,j+1,visited,n,m) + check(grid,i-1,j,visited,n,m) + check(grid,i,j-1,visited,n,m);
        
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> visited( n , vector<int>(m , 0)) ;
        
        vector<int> p;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0)
                {
                    visited[i][j]=1;
                    if(grid[i][j]=='1')
                    {
                        int sz = 1 + check( grid , i+1 , j , visited , n , m ) + check( grid, i, j+1 ,visited ,n ,m ) + check( grid, i-1, j, visited, n , m ) + check( grid , i , j-1, visited , n , m) ;
                        
                        p.push_back(sz);
                    }
                }
            }
        }
        return p.size();
    }
};

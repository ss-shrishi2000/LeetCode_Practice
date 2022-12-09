PROBLEM STATEMENT :- You are given an integer matrix isWater of size m x n that represents a map of land and water cells.
If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:
The height of each cell must be non-negative. If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, 
south, or west of the latter (i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.
Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.
  
  SOLUTION :-
    class Solution {
public:
    bool isvalid(int x, int y, int row, int column)
    {
        if( x < 0 || y < 0 || x >= row || y >= column)
        return false;

        return true;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        int n = isWater.size();
        int row = isWater.size(), column = isWater[0].size();

        vector<vector<int>> graph(10005);
        map<pair<int, int>, bool> vis;

        int dx[] = { -1, 0, 1, 0 };
        int dy[] = { 0, 1, 0, -1 };
        
        queue<pair<int, int>> q;
        int r = 1;

        for(int i = 0; i < isWater.size(); i++)
        {
            for(int j = 0; j < isWater[i].size(); j++)
            {
                if(isWater[i][j] == 1)
                q.push({i, j}), isWater[i][j] = 0;
                else
                isWater[i][j] = INT_MAX;
            }
        }

        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                pair<int, int> cor = q.front();
                vis[{cor.first, cor.second}] = 1;
                q.pop();

                for(int j = 0; j < 4; j++)
                {
                    int nx = cor.first + dx[j];
                    int ny = cor.second + dy[j];

                    if(isvalid(nx, ny, row, column) == true)
                    {
                        if(r < isWater[nx][ny])
                        {
                            isWater[nx][ny] = r;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            r++;
        }
        return isWater;
    }
};

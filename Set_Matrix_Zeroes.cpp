PROBLEM STATEMENT => Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.
  
  Example 1:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

SOLUTION 1 :- 11 ms

class Solution {
public:
     int rows[250];
     int cols[250];
        
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0)
                {
                    rows[i]=1;
                    cols[j]=1;
                }
            }
        }
        
       for (int i=0; i<m; i++) 
       {
         for (int c = 0; c < n; ++c) 
         {
             if(rows[i]==1 || cols[c]==1)
                 matrix[i][c] = 0;
         }
       }
    }
};

SOLUTION 2 :- 16 ms

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        unordered_set<int> zero_row, zero_col;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0)
                {
                    zero_row.insert(i);
                    zero_col.insert(j);
                }
            }
        }
        
       for (auto r : zero_row) 
       {
         for (int c = 0; c < n; ++c) 
         {
             matrix[r][c] = 0;
         }
       }

      for (auto c : zero_col) 
      {
          for (int r = 0; r < m; ++r) 
          {
              matrix[r][c] = 0; 
          }
      }
    }
};

SOLUTION 3 :- 41ms
  
  class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        unordered_set<int> zero_row, zero_col;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0)
                {
                    if(zero_row.find(i)==zero_row.end())
                        zero_row.insert(i);
                    
                    if(zero_col.find(j) == zero_col.end())
                        zero_col.insert(j);
                }
            }
        }
        
       for (auto r : zero_row) 
       {
         for (int c = 0; c < n; ++c) 
         {
             matrix[r][c] = 0;
         }
       }

      for (auto c : zero_col) 
      {
          for (int r = 0; r < m; ++r) 
          {
              matrix[r][c] = 0; 
          }
      }
    }
};

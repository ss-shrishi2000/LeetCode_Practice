PROBLEM STATEMENT => Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
  
Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true 
  
  SOLUTION => 
  class Solution {
public:
   /* bool isSafe(int x, int y, int n, int m)
    {
        if(x<0 || x>=n || y<0 || y>=m)
            return false;
        else
            return true;
    }
   */
    
    bool dfs(vector<vector<char>>& board, string word, int x, int y, int word_index)
    {
        if(word_index == word.size())
            return true;
        
        if(x < 0 || y < 0 || x > board.size()-1 || y > board[0].size()-1)                  // If any index is safe or not
            return false;
        
        if(word[word_index] != board[x][y])
            return false;
        
        char t = board[x][y];
        board[x][y]='&';
        
           bool ans = dfs(board, word, x, y-1, word_index+1)
               || dfs(board, word, x-1, y, word_index+1) 
               || dfs(board, word, x, y+1, word_index+1) 
               || dfs(board, word, x+1, y, word_index+1);
              
        
        board[x][y]=t;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        vector<vector<int>> source;
        int n = board.size() ;
        int m = board[0].size();
        bool f=false;
        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] == word[0] && dfs(board , word, i, j, 0))
                {
                    f=true;
                    break;
                }
            }
            if(f)
                break;
        } 
        return f;
    }
};

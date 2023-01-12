PROBLEM STATEMENT :- On an alphabet board, we start at position (0, 0), corresponding to character board[0][0].
Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the diagram below. 
We may make the following moves:-
'U' moves our position up one row, if the position exists on the board;
'D' moves our position down one row, if the position exists on the board;
'L' moves our position left one column, if the position exists on the board;
'R' moves our position right one column, if the position exists on the board;
'!' adds the character board[r][c] at our current position (r, c) to the answer.
(Here, the only positions that exist on the board are positions with letters on them.)
Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  You may return any path that does so.

 

Example 1:
Input: target = "leet"
Output: "DDR!UURRR!!DDD!"
  
Example 2:
Input: target = "code"
Output: "RR!DDRR!UUL!R!"
  
  SOLUTION :-
    
    class Solution {
public:

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    map<pair<int, int>, string> check = {{{0,-1}, "L"},{{0,1}, "R"},{{-1,0}, "U"},{{1,0}, "D"}};

    bool isValid(int x, int y)
    {
        if(x > 5 || y > 4 || x < 0 || y < 0)
        return 0;

        return 1;
    }

    string bfs(vector<string>& board, int x, int y, char target, map<char, pair<int, int>> mp)
    {
        queue<pair<string, pair<int, int>>> q;
        q.push({"", {x, y}});

        while(!q.empty())
        {
            pair<string, pair<int, int>> tp = q.front();
            q.pop();

            string s = tp.first;
            int prx = tp.second.first;
            int pry = tp.second.second;

            if(board[prx][pry] == target)
            {
                return s;
            }

            for(auto it:check)
            {
                int nwx = prx + it.first.first, nwy = pry + it.first.second;

                if(isValid(nwx, nwy) && board[nwx][nwy] != '*')
                {
                    q.push({s + it.second, {nwx, nwy}});
                }
            }
        }
        return "";
    }
    string alphabetBoardPath(string target) 
    {
        int n = target.size();
        map<char, pair<int, int>> mp;
        vector<string> board;
        
        board.push_back("abcde");
        board.push_back("fghij");
        board.push_back("klmno");
        board.push_back("pqrst");
        board.push_back("uvwxy");
        board.push_back("z****");

        string st = "";
        //assigning positions to the characters
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                int x = i, y = j;
                mp[board[i][j]] = {x, y};
            }
        }
        // new coordinates could be found using the board
        string t = "";
        char start = 'a';

        for(int i = 0; i < target.size(); i++)
        {
            char r = target[i];
            string ans = bfs(board, mp[start].first, mp[start].second, r, mp);
            t += ans + "!";
            start = r;
        }
        return t;
    }
};

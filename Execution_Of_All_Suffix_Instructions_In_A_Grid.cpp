#include<bits/stdc++.h>
using namespace std;
bool Safe(int lastrow, int lastcol, int cur_row, int cur_col)
{
    if(cur_row>lastrow || cur_col>lastcol || cur_row<0 || cur_col<0)
        return false;

    return true;
}

int main()
{
    int n;
    vector<int> startPos(2);
    string s;
    cin>>n>>s;
    cin>>startPos[0] >> startPos[1];
    int lastrow = n-1, lastcol = n-1;
        vector<int> ans;

        for(int i=0; i<s.size(); i++)
        {
            int cnt=0, cur_row = startPos[0] , cur_col = startPos[1];

            for(int j = i;j < s.size(); j++)
            {
                if(s[j]=='L')
                    cur_col -=1;
                else if(s[j]=='R')
                    cur_col += 1;
                else if(s[j]=='U')
                    cur_row -= 1;
                else
                    cur_row += 1;

                cout<<cur_row << " " << cur_col << endl;

                if(Safe(lastrow,lastcol,cur_row,cur_col))
                    cnt++;
                else
                    break;
            }
            ans.push_back(cnt);
        }
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        return 0;
}

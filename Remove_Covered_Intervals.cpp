#include<bits/stdc++.h>
using namespace std;
int main()
{
     vector<vector<int>> intervals;
     int x,y,n;
     cin>>n;
     for(int i=0; i<n;i++)
     {
         cin>>x>>y;
         intervals.push_back({x,y});
     }
     int ans = n;
        for(int i=0; i<n;i++)
        {
            int a = intervals[i][0] , b = intervals[i][1];
            for(int j=0; j<n; j++)
            {
                if(j==i)
                    continue;

                int c = intervals[j][0] , d = intervals[j][1];
                cout<< j << " " << i << endl;
                if(c<=a && b<=d)
                {
                    ans--;
                    cout<< ans << endl;
                    break;
                }
            }
        }
        cout<<ans;
        return 0;
}

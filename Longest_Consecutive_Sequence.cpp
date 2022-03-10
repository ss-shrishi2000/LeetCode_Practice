#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s; cin>>s;
    int x;
    map<int,int> mp;
    for(int i=0; i<s; i++)
    {
        cin>>x;
        mp[x]++;
    }
        int prev = -1000000;
        int cnt=0;
        int r = 0;
        for(auto it:mp)
        {
            //cout<< it.first << " " << it.second << endl;
            if(prev==-1000000)
            {
                prev = it.first;
                cnt += 1;
                r = max(r,cnt);
            }
            else if( it.first - prev != 1)
            {
                cnt = 1;
                prev = it.first;
               // cout<<2<<endl;
            }
            else if(it.first - prev == 1)
            {
                prev = it.first;
                cnt += 1;
                r = max(r,cnt);
               // cout<< 1 << endl;
            }
            cout<<prev << " " << cnt<< " " << r << endl;
        }
        cout<<r;
        return 0;
}

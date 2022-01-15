#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar[n];
        int x = 1000000;
        for(int i=0;i<n;i++)
            cin>>ar[i];

        int ans = 0;

        for(int i=1;i<n;i++)
        {
            if(ar[i]!=ar[i-1])
                continue;
            else
            {
                ar[i] = x;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}

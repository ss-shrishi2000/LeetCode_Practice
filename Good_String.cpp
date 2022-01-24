#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l;cin>>l;
    string s,ans="";cin>>s;
    ans+=s[0];
    for(int i=1;i<s.size();i++)
    {
        if(ans.size()%2==0 || ans.back()!=s[i])
        {
            ans+=s[i];
        }
    }
    if(ans.size()%2==1)
        ans.pop_back();
    cout<<l-ans.size()<<endl;
    cout<<ans<<endl;
}

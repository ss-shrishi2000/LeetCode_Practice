#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int k; cin>>k;
     int n = s.size();
        if(k==1)
        return s.size();
        int ans=0;
        for(int i=0;i+k<=s.size();i++)
        {
            int c=0,a[26]={0};
            for(int j=i;j<s.size();j++)
            {
                if(a[s[j]-'a']==0 )
                    c++;
                a[s[j]-'a']++;
                if(a[s[j]-'a']==k)
                    c--;
                if(c==0)
                ans=max(ans,j-i+1);
            }
        }
        cout<<ans<<endl;
        return 0;
}

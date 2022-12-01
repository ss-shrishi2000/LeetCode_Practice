#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> arr;
    int k,n;
    cin>>n>>k;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        arr.push_back(s);
    }

    map<string,int> mp;

    for(int i=0;i<arr.size();i++)
        mp[arr[i]]++;

    vector<string> vec;
    string ans="";
    int j = 0;

    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(it->second==1)
            vec.push_back(it->first);

        //cout<<it->first<<endl;
    }
    reverse(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++)
    {
        if(i==k-1)
        {
            ans = vec[i];
            break;
        }
    }

    cout<<ans;
    return 0;
}

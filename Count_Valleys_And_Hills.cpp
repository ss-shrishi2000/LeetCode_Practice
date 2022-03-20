#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x;
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    unordered_set st(v.begin(), v.end());
    for(auto it=st.begin(); it!=st.end(); it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}

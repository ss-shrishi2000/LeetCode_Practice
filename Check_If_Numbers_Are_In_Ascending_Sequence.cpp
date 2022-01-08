#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    vector<int> vec;
    int i=0;
    while(i<s.size())
    {
        if(s[i]>='0' && s[i]<='9')
        {
            int r = (s[i]-'0') ;
            i+=1;
            while(i<s.size() && (s[i]>='0') && (s[i]<='9'))
            {
               r = r*10 + (s[i]-'0');
               i++;
            }
            // cout<<r<<endl;
            vec.push_back(r);
        }
        else
            i++;
    }
    
    bool f=true;
    
    for(int i=1;i<vec.size();i++)
    {
        if(vec[i] < vec[i-1])
        {
            f=false;
            break;
        }
    }
    if(f)
        cout<<"Yes";
    else
        cout<<"No";
    
    return 0;

}

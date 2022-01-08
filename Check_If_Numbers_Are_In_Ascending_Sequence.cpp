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
            cout<<r<<endl;
            vec.push_back(r);
        }
        else
            i++;
    }
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
    return 0;

}

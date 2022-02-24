#include<bits/stdc++.h>
using namespace std;

 static bool cmp(pair<string,int> &a, pair<string,int> &b)
{
    if(a.first.size() == b.first.size())
        return (a.second<b.second);
    else
        return (a.first.size()<b.first.size());
}

int main()
{
    string text;
    getline(cin,text);
    vector<pair<string,int>> ans;
        int ord=0;
        for(int i=0; i<text.size();)
        {
            string p="";
            while(i<text.size() && text[i]!=' ')
                p=p+text[i],i++;

            i=i+1;
            ord++;
            ans.push_back(make_pair(p,ord));
        }
        sort(ans.begin(),ans.end(),cmp);
        string fr="";
        for(int i=0; i<ans.size();i++)
        {
            fr += ans[i].first;
            fr+=" ";
        }
        fr[0]=toupper(fr[0]);
        cout<<fr;
}

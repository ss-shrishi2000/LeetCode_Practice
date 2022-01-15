#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n = stoi(s);
        if(n%2==0)
        {
            cout<<0<<endl;
            continue;
        }
        if(s.size()==1 && ((s[0]-'0')%2==0 ))                         //single digit even
        {
            cout<<0<<endl;
        }
        else if(s.size()==1 && ((s[0]-'0')%2))               //single digit odd
        {
            cout<<-1<<endl;
        }
        else
        {
            int e=0, x= s.size();
            for(int i=0;i<s.size();i++)
            {
                if((s[i]-'0') %2 ==0)
                    e++;
            }
            if(e==0)
            {
                cout<<-1<<endl;                                           //doesn't contain even digit
            }
            else
            {
                if((s[0]-'0')%2 && (s[x-1]-'0')%2)                           //first and last digit both r odd
                {
                    cout<<2<<endl;
                }
                else if( (s[0]-'0')%2==0 && (s[x-1]-'0')%2 )                 //first digit is even and last digit is odd
                {
                    cout<<1<<endl;
                }
            }
        }
    }
}

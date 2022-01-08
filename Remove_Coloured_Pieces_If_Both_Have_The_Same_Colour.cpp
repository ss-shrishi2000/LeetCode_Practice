#include<bits/stdc++.h>
using namespace std;
int main()
{
    string colors;
    cin>>colors;
    int ca = 0, cb=0, ans1=0, ans2=0;
      int i=0;
        while(i<colors.size())
        {
            if(colors[i]=='A')
            {
                while(i<colors.size() && colors[i]=='A')
                {
                    i++;
                    ca++;
                }

                if(ca>2)
                    ans1 += (ca-2);
                
                ca=0;
            }
            else
            {
                while(i<colors.size() && colors[i]=='B')
                {
                    i++;
                    cb++;
                }

                if(cb>2)
                    ans2 += (cb-2);
                cb=0;
            }
        }

       // cout<< ans1 << " " << ans2 << endl;
    
        if(ans1>ans2)
            cout<<"Alice"<<endl;
        else
            cout<<"Bob"<<endl;

        return 0;
}

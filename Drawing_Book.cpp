#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,p;
    cin>>n>>p;
    int left = 1, right = n-1, c1=0, c2=0;
    int ans = INT_MAX;

    if(p==1 || p==n || p==n-1)
    {
        cout<<0<<endl;
    }
    else {

    while(left<=n-2 && right>=0)
    {
        if(left>=right || left>=n-1 || right<=0)
          break;

          cout<<left<< " " << right << endl;

       if(left==p || left+1 ==p)
       {
           break;
       }
       else {
       left += 2;
       c1++;
       }

       if(right == p || right == p-1)
       {
           break;
       }
       else {
       right -=2;
       c2++;
       }
    }
    cout<<min(c1,c2)<<endl;
    }
}

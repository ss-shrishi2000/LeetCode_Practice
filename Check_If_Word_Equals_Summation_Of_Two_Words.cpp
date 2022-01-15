#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int n1=0,n2=0,n3=0;
    int i=0;
    while( i<s1.size() && ( s1[i]-'a' == 0 ))
            i++;

    int j=0;
    while( j<s2.size() && ( s2[j]-'a' == 0 ))
        j++;

    int k=0;
    while( k<s3.size() && ( s3[k]-'a' == 0 ))
        k++;

    while(i<s1.size())
        n1 = n1*10 + (s1[i]-'a'),i++;

     while(j<s2.size())
        n2 = n2*10 + (s2[j]-'a'),j++;

     while(k<s3.size())
        n3 = n3*10 + (s3[k]-'a'),k++;

      //  cout<<n1 << " " << n2 << " " << n3 << endl;

    if(n1+n2 == n3)
        cout<<"Yes";
    else
        cout<<"No";

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x;
    vector<int> nums;
    for(int i = 0; i < n; i++)
    {
        cin>>x;
        nums.push_back(x);
    }
    if(n == 3)
        {
            if(nums[0] < nums[1] && nums[1] < nums[2])
            return true;
            else
            return false;
        }
        int mnindex = min_element(nums.begin(), nums.end()) - nums.begin();
        int mxindex = max_element(nums.begin(), nums.end()) - nums.begin();
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        if(mnindex < mxindex && (mxindex - mnindex) > 0 && (mx - mn) > 1)
        {
            cout<<"True"<<endl;
            return 0;
        }
        int prefix[n], suffix[n];
        memset(prefix, INT_MAX, sizeof(prefix));
        memset(suffix, INT_MIN, sizeof(suffix));
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];

        for(int i = 1; i < n; i++)
        {
            prefix[i] = min(nums[i], prefix[i-1]);
        }
        for(int i = n-2; i >= 0; i--)
        {
            suffix[i] = max(nums[i], suffix[i+1]);
        }
        bool f = false;
        for(int i = 0; i < n; i++)
        {
            cout<<prefix[i]<<" "<<suffix[i]<<endl;
        }
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != prefix[i] && nums[i] != suffix[i] &&
               nums[i]>prefix[i] && nums[i]<suffix[i]
               && prefix[i] != suffix[i])
            {
                f = true;
                break;
            }
        }
        if(f)
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
}

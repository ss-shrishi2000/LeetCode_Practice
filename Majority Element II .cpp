PROBLEM STATEMENT :-
  Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
  Follow-up: Could you solve the problem in linear time and in O(1) space ?
    
Example 1:
Input: nums = [3,2,3]
Output: [3]


Example 2:
Input: nums = [1]
Output: [1]


Example 3:
Input: nums = [1,2]
Output: [1,2]


SOLUTION :-
    class Solution 
    {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        map<int,int> mp;
        vector<int> ans;
        int n=nums.size();
        int x = (n+3)/3;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
             if(it->second >= x )
                ans.push_back(it->first);
        }
        return ans;
    }
};

 

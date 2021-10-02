PROBLEM STATEMENT :-Given an unsorted integer array nums, return the smallest missing positive integer.
You must implement an algorithm that runs in O(n) time and uses constant extra space. 
  
  Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
  
  SOLUTION:-
    class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        set<int> s;
        int c=1,ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)s.insert(nums[i]);
        }
        for(auto it=s.begin();it!=s.end();it++)
        {
            if(*it!=c)
            {
                ans=c;
                break;
            }
            c+=1;
        }
        return ans;
    }
};

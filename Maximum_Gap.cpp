PROBLEM STATEMENT :-
  Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
  You must write an algorithm that runs in linear time and uses linear extra space.
  
Example 1:
Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
  
  SOLUTION :-
    //LeetCode HARD
    // time consumption - 470 ms
    class Solution {
public:
    int maximumGap(vector<int>& nums)
    {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++)
            pq.push(nums[i]);
        
        if(nums.size()<2)
            return 0;
        int mx=INT_MIN;
        while(pq.size()>1)
        {
            int t=pq.top();
            pq.pop();
            int r=pq.top();
            mx=max(mx, t-r);
        }
        return mx;
    }
};

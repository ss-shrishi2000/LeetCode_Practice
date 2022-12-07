PROBLEM STATEMENT :- Given an integer array nums and an integer k, return the number of subarrays of nums where the least common multiple of the 
subarray elements is k. A subarray is a contiguous non-empty sequence of elements within an array. The least common multiple of an array is the 
smallest positive integer that is divisible by all the array elements.

 

Example 1:
Input: nums = [3,6,2,7,1], k = 6
Output: 4
Explanation: The subarrays of nums where 6 is the least common multiple of all the subarray's elements are:
- [3,6,2,7,1]
- [3,6,2,7,1]
- [3,6,2,7,1]
- [3,6,2,7,1]

SOLUTION :-
  
  class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) 
    {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int currlcm = 1;
            for (int j = i; j < n; j++)
            {
                currlcm = lcm(currlcm, nums[j]);
                if(currlcm == k)
                cnt++;

                if (currlcm > k)
                break;
            }
        }
        return cnt;
    }
};

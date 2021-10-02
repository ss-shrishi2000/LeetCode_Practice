PROBLEM STATEMENT :- The distance of a pair of integers a and b is defined as the absolute difference between a and b.
Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

Example 1:
Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
  
  
Example 2:
Input: nums = [1,1,1], k = 2
Output: 0
Example 3:

Input: nums = [1,6,1], k = 3
Output: 5
  
  SOLUTION :-
    
    class Solution 
    {
public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {
       sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int low = 0, high = nums[n-1] - nums[0];
        int ans = -1;
        while (low <= high) 
        {
            int cnt = 0, j = 0;
            int mid = ( low + high )/2;
            for (int i = 0; i < n; ++i) 
            {
                while (j < n && nums[j] - nums[i] <= mid) 
                    ++j;
                
                cnt += j-i-1;
            }
            
            if (cnt >= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else 
                low = mid + 1;
        }
        
        return ans;
    }
};



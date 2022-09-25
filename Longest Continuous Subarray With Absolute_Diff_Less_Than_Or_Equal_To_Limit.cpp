PROBLEM STATEMENT :-
  Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two 
  elements of this subarray is less than or equal to limit.

Example 1:
Input: nums = [8,2,4,7], limit = 4
Output: 2 
  
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
  
  SOLUTION :-
    class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        int n = nums.size();
        // difference between maximum and minimum should be less
        // than or equal to limit
        // implies difference between mx and min should be less than or
        // equal to limit
        
        int ans = 1;
        map<int, int> mp;
        int l = 0, r = 0, d = 0;
        for(; r < n; r++)
        {
            mp[nums[r]]++;
            auto m1 = mp.begin()->first;
            auto m2 = mp.rbegin()->first;
            if(m2 - m1 <= limit)
            {
                ans = max(ans, r - l + 1);
            }
            else
            {
                while(l < r)
                {
                    mp[nums[l]]--;
                    if(mp[nums[l]] == 0)
                        mp.erase(mp.find(nums[l]));
                    
                    l++;
                    auto m1 = mp.begin()->first, m2 = mp.rbegin()->first;
                    if(m2 - m1 <= limit)
                        break;
                }
            }
        }
        return ans;
    }
};

PROBLEM STATEMENT :- Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) such that:
0 <= i < j <= n - 1 and
nums[i] * nums[j] is divisible by k.
Example 1:

Input: nums = [1,2,3,4,5], k = 2
Output: 7
Explanation: 
The 7 pairs of indices whose corresponding products are divisible by 2 are
(0, 1), (0, 3), (1, 2), (1, 3), (1, 4), (2, 3), and (3, 4).
Their products are 2, 4, 6, 8, 10, 12, and 20 respectively.
Other pairs such as (0, 2) and (2, 4) have products 3 and 15 respectively, which are not divisible by 2.    
  
  SOLUTION :-
    class Solution {
public:
    long long countPairs(vector<int>& nums, int k) 
    {
    map<long long int, long long int>mp;
    long long ans = 0;
    for(int i=0;i<nums.size();i++)
    {    
        long long g= __gcd(nums[i], k);
        long long required = k/g;
        for(auto it:mp)
        {
            if(it.first%required==0)ans += it.second;
        }
        mp[g]++;
    }
    return ans;
    }
};

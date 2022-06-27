PROBLEM STATEMENT :- Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is 
divisible by p. It is not allowed to remove the whole array.
Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.
A subarray is defined as a contiguous block of elements in the array.
  
Example 1:-
Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the 
remaining elements is 6, which is divisible by 6.
  
 SOLUTION :-
   class Solution {
public:
    int minSubarray(vector<int>& nums, int p)
    {
        int n = nums.size();
        long long int mod[n], total = 0;
        for(int i = 0; i<n; i++)
        {
            mod[i] = (nums[i] + p) % p;
            total += nums[i];
        }
        
        if(total%p==0)
            return 0;
        
        long long int target_rem = total%p;
        int res = INT_MAX;
        unordered_map<long long int, int> mp;
        mp[0] = -1;
        long long int curr = 0;
        
        for(int i=0; i<n; i++)
        {
            curr = (curr + nums[i] + p)%p;
            mp[curr] = i;
            long long int mod = (curr - target_rem + p)%p;
            
            if(mp.find(mod)!= mp.end())
                res = min(res, i-mp[mod]);
        }
        if(res == INT_MAX || res>=n)
            return -1;
        else
            return res;
    }
};

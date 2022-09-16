PROBLEM STATEMENT :- Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as 
side lengths of a triangle.
  
Example 1:
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
  
Example 2:
Input: nums = [4,2,3,4]
Output: 4

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 1000
  
  SOLUTION :-
    
    class Solution {
public:
    int triangleNumber(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[nums[i]]++;
        
        int ans = 0;
        for(int i = n-1; i > 0; i--)
        {
            int left = 0, right = i-1;
            while(left < right)
            {
                if(nums[i] < nums[right] + nums[left])
                {
                    ans += (right - left);
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return ans;
    }
};

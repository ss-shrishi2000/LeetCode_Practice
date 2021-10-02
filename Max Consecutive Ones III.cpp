PROBLEM STATEMENT :-
  Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
 
Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]

  
Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]


  SOLUTION :-
    class Solution 
    {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int zc=0;
        int left=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                ++zc;
            if(zc>k)
            {
                while(zc>k)
                {
                    if(nums[left]==0)
                        --zc;
                    left++;
                }
            }
            ans=max(ans , i-left+1);
        }
        return ans;
    }
};




PROBLEM STATEMENT =>
  Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

SOLUTION :-
  
  class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        long long int pr = 1, pr1 = 1;
        int z=0;
        for(int i=0; i<nums.size(); i++)
        {
            pr = pr*nums[i];
            
            if(nums[i]==0)
                z++;
            
            if(nums[i]!=0)
                pr1 = pr1*nums[i];
        }
         
        vector<int> x;
        if(pr==0 && z>1)
        {
           
            for(int i=0; i<nums.size(); i++)
                x.push_back(0);
        }
        else if(pr==0)
        {
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i]!=0)
                    x.push_back(0);
                else
                    x.push_back(pr1);
            }
        }
        else
        {
            for(int i=0; i<nums.size(); i++)
            {
                x.push_back(pr/nums[i]);
            }
        }
        return x;
    }
};
 

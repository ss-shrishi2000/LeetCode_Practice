PROBLEM STATEMENT :- Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
  
  SOLUTION :-
    class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
         if(nums.size()<3)
         { 
           return vector<vector<int>>{}; 
         }
      
        vector<vector<int>> rt;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-2; ++i)
        {
            if (nums[i]>0) 
            { 
              break; 
            } 
            //if a is pos, no combination can make it 0
            if (i!=0 && nums[i-1]==nums[i])
            { 
              continue;
            } 
            //if repeat, skip
            
            int l=i+1;
            int r=nums.size()-1;
            
            while (l<r) 
            {
                if (nums[l]+nums[r]+nums[i]<0)
                { 
                  l++; 
                }
                else if (nums[l]+nums[r]+nums[i]>0) 
                { 
                  r--;
                }
                else
                {
                    rt.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    while (l<r && nums[l]==nums[l+1])
                                l++;                
                    while (l<r && nums[r]==nums[r-1])
                                r--; 
                    l++;
                    r--;
                }
            }
        }
        return rt;
    }
};

 

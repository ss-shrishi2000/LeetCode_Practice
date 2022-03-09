PROBLEM STATEMENT => Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
 

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
  
  SOLUTION :- 
    class Solution {
public:
    void subsetsUtil(vector<int>& nums, vector<vector<int> >& ans,
                 vector<int>& subset, int index)
{
    ans.push_back(subset);
    for (int i = index; i < nums.size(); i++)
    {
        // include the A[i] in subset.
        subset.push_back(nums[i]);
 
        // move onto the next element.
        subsetsUtil(nums, ans, subset, i + 1);
 
        // exclude the A[i] from subset and triggers
        // backtracking.
        subset.pop_back();
    }
    return;
}
    vector<vector<int>> subsets(vector<int>& nums)
    {
     vector<int> subset;
    vector<vector<int>> ans;
 
    // keeps track of current element in vector A;
    int in = 0;
    subsetsUtil(nums, ans, subset, in);
    return res;
    }
};

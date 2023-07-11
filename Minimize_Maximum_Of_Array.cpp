Problem Statement: You are given 0-indexed array nums comprising n non-negative integers.
In one operation, you must:
Choose an integer i such that 1 <= i < n and nums[i] > 0.
Decrease nums[i] by 1.
Increase nums[i - 1] by 1.
Return the minimum possible value of the maximum integer of nums after performing any number of operations.

Example 1:
Input: nums = [3,7,1,6]
Output: 5
Explanation:
One set of optimal operations is as follows:
1. Choose i = 1, and nums becomes [4,6,1,6].
2. Choose i = 3, and nums becomes [4,6,2,5].
3. Choose i = 1, and nums becomes [5,5,2,5].
The maximum integer of nums is 5. It can be shown that the maximum number cannot be less than 5.
Therefore, we return 5.

Solution:
class Solution {
public:
    bool calc(vector<int> nums, long long mid){
        int n = nums.size();
        // increase nums[i] by 1
        // decrease nums[i] by 1
        long long d = 0;
        for(int i = n-1; i >= 0; i--){
            if(nums[i] > mid){
                d += (nums[i] - mid);
            } else {
                d -= min(mid - nums[i], d);
            }
        }
        return (d == 0);
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long low = 1, high = *max_element(nums.begin(), nums.end()), ans = *max_element(nums.begin(), nums.end());
        while(low < high){
            long long mid = (low + high)/2;
            //cout<<mid<<" Mid "<<endl;
            if(calc(nums, mid)){
                high = mid;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};


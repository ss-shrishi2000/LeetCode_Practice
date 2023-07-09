
Problem Statement:
You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:

nums.length == n
nums[i] is a positive integer where 0 <= i < n.
abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
The sum of all the elements of nums does not exceed maxSum.
nums[index] is maximized.
Return nums[index] of the constructed array.

Note that abs(x) equals x if x >= 0, and -x otherwise.

 

Example 1:

Input: n = 4, index = 2,  maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].

Solution:-

class Solution {
public:
    bool isPossible(long long mid, int index, int index2, int maxSum, int n){
        long long leftSum = 0, rightSum = 0;

        if(mid <= index){
            leftSum += (mid*(mid+1))/2 + (index + 1 - mid);
        } else {
            leftSum += (mid*(mid+1))/2;
            leftSum -= (mid-index-1)*(mid-index)/2;
        }

        if(mid <= index2){
            rightSum += (mid*(mid-1))/2 + (index2 + 1 - mid);
        } else {
            rightSum += (mid*(mid-1))/2;
            rightSum -= ((mid - index2 - 1)*(mid - index2))/2;
        }

        long long f1 = leftSum + rightSum;
        if(f1 <= maxSum){
            return 1;
        }
        return 0;
    }
    int maxValue(int n, int index, int maxSum) {
        long long low = 1, high = maxSum;
        int ans = 1;
        while(low <= high){
            long long mid = (low + high)/2;
            if(isPossible(mid, index, n-1-index, maxSum, n)){
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

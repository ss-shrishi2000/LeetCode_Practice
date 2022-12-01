PROBLEM STATEMENT :-

Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the 
given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.
In case of a tie, return the minimum such integer.
Notice that the answer is not neccesarilly a number from arr.


Example 1:
Input: arr = [4,9,3], target = 10
Output: 3
Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.


Example 2:
Input: arr = [2,3,5], target = 10
Output: 5

SOLUTION:

class Solution {
public:
    long long check(vector<int> arr, int r)
    {
        long long t = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] < r)
            t += arr[i];
            else
            t += r;
        }
        return t;
    }
    int findBestValue(vector<int>& arr, int target) 
    {
        int n = arr.size();
        long long low = 0, high = *max_element(arr.begin(), arr.end());
        long long s = INT_MAX, w = INT_MAX;

        while(low + 1 < high)
        {
            long long mid = low + (high - low)/2;
            long long r = check(arr, mid);
            if(r > target)
            {
                high = mid;
            }
            else
                low = mid;
        }

        long long sleft = check(arr, low);
        long long sright = check(arr, high);
        //cout<<low<<" "<<high<<endl;
        if(abs(sleft - target) <= abs(sright - target))
        return low;
        else
        return high;
    }
};

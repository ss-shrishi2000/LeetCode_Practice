PROBLEM STATEMENT :- Given an array of digit strings nums and a digit string target, return the number of pairs of indices (i, j) (where i != j) such that the 
concatenation of nums[i] + nums[j] equals target.
Example 1:

Input: nums = ["777","7","77","77"], target = "7777"
Output: 4
Explanation: Valid pairs are:
- (0, 1): "777" + "7"
- (1, 0): "7" + "777"
- (2, 3): "77" + "77"
- (3, 2): "77" + "77"
Example 2:

Input: nums = ["123","4","12","34"], target = "1234"
Output: 2
Explanation: Valid pairs are:
- (0, 1): "123" + "4"
- (2, 3): "12" + "34"
Example 3:

Input: nums = ["1","1","1"], target = "11"
Output: 6
Explanation: Valid pairs are:
- (0, 1): "1" + "1"
- (1, 0): "1" + "1"
- (0, 2): "1" + "1"
- (2, 0): "1" + "1"
- (1, 2): "1" + "1"
- (2, 1): "1" + "1"
  
  SOLUTION :- 
    
    First Solution having a higher time complexity (O(n^2)) using space complexity O(1) whereas second solution having a time complexity O(n) and space complexity O(n).
    
    class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) 
    {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0; j<nums.size() && j!=i ; j++)
            {
                string x = nums[i];
                string y = nums[j];
                if(x+y == target)
                    ans++;
                if(y+x == target)
                    ans++;
            }
        }
        
        return ans;
    }
};

    
    class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) 
    {
        int ans=0;
        map<string,int> mp;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            string x = nums[i];
            int sz1 = x.size();
            if(nums[i]==target.substr(0,sz1))
            {
            string rem = target.substr(sz1);
                
            if(mp.find(rem)!=mp.end() && x+rem == target)
            {
                ans+=mp[rem];
                if(rem == x)
                    ans--;
            }
            }
        }
        return ans;
    }
};

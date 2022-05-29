PROBLEM STATEMENT :-
  Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.
  
  SOLUTION :-
    class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) 
    {
        if(nums.size() % k != 0) 
            return false;
        
        map<int, int> mp;
        for(int num : nums)
            mp[num]++;
        
        for(auto it : mp)
        {
            while(mp[it.first] > 0)
            {
                for(int i = 0; i < k; i++)
                {
                    mp[it.first + i]--;
                    if(mp[it.first + i] < 0) 
                        return false;
                }
            }
        }
        return true;
    }
};

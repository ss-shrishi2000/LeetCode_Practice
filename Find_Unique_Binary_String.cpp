PROBLEM STATEMENT :-
  Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. 
  If there are multiple answers, you may return any of them.

Example 1:
Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
  
Example 2:
Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
  
Example 3:
Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
  
  SOLUTION :-
    class Solution {
public:
    void solveFunc(int n,string tmpStr,set<string> s,string &ans) 
    {
    
    if(tmpStr.size()==n)
    {
        if(!s.count(tmpStr))
            ans = tmpStr;
        return;
    }
    
    if(!ans.empty())
        return;
    
    tmpStr+='0';
    solveFunc(n,tmpStr,s,ans);
    
    if(!ans.empty())
        return;
    
    tmpStr.pop_back();
    tmpStr+='1';
    solveFunc(n,tmpStr,s,ans);
}
    
string findDifferentBinaryString(vector<string>& nums) 
{
    set<string> temp;
    for(int i=0; i<nums.size();i++)
    {
        temp.insert(nums[i]);
    }
    string ans;
    solveFunc(nums[0].size(),"",temp,ans);
    return ans;
}
};

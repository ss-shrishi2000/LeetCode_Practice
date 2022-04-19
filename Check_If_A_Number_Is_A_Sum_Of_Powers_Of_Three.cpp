PROBLEM STATEMENT :-
  Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.An integer 
  y is a power of three if there exists an integer x such that y == 3x.

Example 1:
Input: n = 12
Output: true
Explanation: 12 = 31 + 32
  
Example 2:
Input: n = 91
Output: true
Explanation: 91 = 30 + 32 + 34
  
Example 3:
Input: n = 21
Output: false
  
  SOLUTION :-
    class Solution {
public:
    bool recurr(vector<int> v, int ind, int n)
    {
        if(n==0)
            return true;
        if(n<0)
            return false;
        if(ind<=0)
            return false;
        
        return recurr(v, ind-1, n) || recurr(v, ind-1, n-v[ind-1]);
    }
    
    bool checkPowersOfThree(int n)
    {
        vector<int> v;
        for(int i=0; i<20 && pow(3,i)<1e8; i++)
        {
            v.push_back(pow(3,i));
        }
        bool f = recurr(v, v.size(), n);
        return f;
    }
};

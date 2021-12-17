
PROBLEM STATEMENT :- Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their 
values changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 SOLUTION :-
  class Solution {
public:
    int dfs(vector<int>& A, int k, int index,vector<int>& dp){
    
    if(index>=A.size()) return 0;
    int n=A.size();
    
    if(dp[index]!=-1) 
        return dp[index];
        
    int maxele=0 , max_sum=0;
        
    for(int i=index;i<min(n,index+k);i++)
    {
        maxele = max(maxele,A[i]);
        
        int temp;
        
        if(dp[i+1]!=-1) 
            temp=dp[i+1];
        else 
            temp=dfs(A,k,i+1,dp);
        
        dp[i+1]=temp;
        
        max_sum=max(max_sum, maxele*(i-index+1)+ temp);
    }
        
    dp[index]=max_sum;
    return max_sum;
}


int maxSumAfterPartitioning(vector<int>& A, int k) 
{    
    int n=A.size(); vector<int> dp(n+1,-1);
    return dfs(A,k,0,dp);
}
};

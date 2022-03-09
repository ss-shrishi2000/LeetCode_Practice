
PROBLEM STATEMENT => You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval 
and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals 
(merge overlapping intervals if necessary).
Return intervals after the insertion.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
  
  SOLUTION =>
  
  class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        
        if(n==1)
            return intervals;
        
        int a= intervals[0][0];
        int b= intervals[0][1];
        for(int i=1;i<n;i++)
        {
        int c= intervals[i][0];
        int d= intervals[i][1];
        if( c>=a && c<=b )
        {
            a=min(a,c);
            b=max(b,d);
            if(i==n-1)
            {
                ans.push_back({a,b});
            }
        }
        else
        {
            ans.push_back({a,b});
            a=c;
            b=d;
            if(i==n-1)
            {
                ans.push_back({c,d});
            }
        }
        }
        return ans;
    }
};

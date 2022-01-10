PROBLEM STATEMENT :-
  Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
An integer a is closer to x than an integer b if:
|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

SOLUTION 1 :-
  class Solution 
  {
public:
    bool static cmp(pair<int, int> & p1 , pair<int ,int> & p2)
    {
    if(p1.first<p2.first)
        return 1;
    else
        return p1.second<p2.second;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
    int n=arr.size();
     vector<pair<int,int>> vec[n];
    for(int i=0;i<n;i++)
    {
        vec[i].push_back({abs(arr[i]-x) , arr[i]});
    }
    sort(vec.begin(),vec.end(),cmp);
        vector<int> ans;
    for(int i=0;i<k;i++)
    {
        ans.push_back(vec[i].second);
    }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

SOLUTION 2:- (Using Priority Queue)
  
  class Solution 
  {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        priority_queue<pair<int,int>>pq;
        vector<int> ans;
        for(int i=0;i<arr.size();i++)
        {
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};


  

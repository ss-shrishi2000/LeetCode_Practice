PROBLEM STATEMENT :- 
  You are given a positive integer array grades which represents the grades of students in a university. 
  You would like to enter all these students into a competition in ordered non-empty groups, such that the ordering meets the following conditions:
  The sum of the grades of students in the ith group is less than the sum of the grades of students in the (i + 1)th group, for all groups (except the last).
  The total number of students in the ith group is less than the total number of students in the (i + 1)th group, for all groups (except the last).
  Return the maximum number of groups that can be formed.
    
    Example 1:
    Input: grades = [10,6,12,7,3,5]
    Output: 3
    Explanation: The following is a possible way to form 3 groups of students:
- 1st group has the students with grades = [12]. Sum of grades: 12. Student count: 1
- 2nd group has the students with grades = [6,7]. Sum of grades: 6 + 7 = 13. Student count: 2
- 3rd group has the students with grades = [10,3,5]. Sum of grades: 10 + 3 + 5 = 18. Student count: 3
It can be shown that it is not possible to form more than 3 groups.
  
    Example 2:
    Input: grades = [8,8]
    Output: 1
    Explanation: We can only form 1 group, since forming 2 groups would lead to an equal number of students in both groups.
      
      SOLUTION :-
        
        class Solution {
public:
    int maximumGroups(vector<int>& grades) 
    {
        // sum of 1st group < sum of 2nd group grades
        // total no of students in ith group < (i+1)th group
        sort(grades.begin(), grades.end());
        int sz = grades.size();
        vector<long long> sum, grpsz;
        long long s = grades[0], n = 1, cnt = 0, j = 1;
        sum.push_back(s);
        n = 2;
        
        grpsz.push_back(1);
        s = 0;
        int ans = 0;
        while( j < sz )
        {
            while(j < sz && cnt < n)
            s+=grades[j++], cnt++;

            sum.push_back(s);
            grpsz.push_back(cnt);
            cnt = 0;
            n++;
        }

        /*
        for(int i = 0; i < sum.size(); i++)
        cout<<sum[i]<<" "<<grpsz[i]<<endl;
        */

        int r = sum.size()-1;
        while(r>0 && (sum[r-1] >= sum[r] || grpsz[r-1] >= grpsz[r]))
        {
            sum[r-1] += sum[r];
            grpsz[r-1] += grpsz[r];
            r--;
        }

        if(r==1 && sum[r] == sum[r-1])
        return 1;

        return r+1;
    }
};


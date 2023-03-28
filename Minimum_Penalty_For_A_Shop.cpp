PROBLEM STATEMENT :- You are given the customer visit log of a shop represented by a 0-indexed string customers consisting only of characters 'N' and 'Y':
if the ith character is 'Y', it means that customers come at the ith hour whereas 'N' indicates that no customers come at the ith hour.
If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:
For every hour when the shop is open and no customers come, the penalty increases by 1.
For every hour when the shop is closed and customers come, the penalty increases by 1.
Return the earliest hour at which the shop must be closed to incur a minimum penalty.
Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.

SOLUTION :-
  
  class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int suffyes[n+1], prefno[n+1];
        prefno[0] = 0;
        suffyes[n] = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if(customers[i] == 'Y')
            suffyes[i] = 1 + suffyes[i+1];
            else
            suffyes[i] = suffyes[i+1];
        }

        for(int i = 0; i < n; i++)
        {
            if(customers[i] == 'N')
            prefno[i+1] = 1 + prefno[i];
            else
            prefno[i+1] = prefno[i];
        }

        if(suffyes[0] == n)
        return n;

        int ans = INT_MAX, y = INT_MAX;
        for(int i = 0; i <= n; i++)
        {
            int x = prefno[i] + suffyes[i];
            if(x < ans)
            {
                y = i;
                ans = x;
            }
        }
        return y;
    }
};

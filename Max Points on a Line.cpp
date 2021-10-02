PROBLEM STATEMENT :-
  Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
  
  Input: points = [[1,1],[2,2],[3,3]]
  Output: 3
    
  Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
  Output: 4
    
  SOLUTION :-
    class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
             map<pair<int,int> ,int > mp;
            int duplicates=0,cur=0;
            for(int j=i+1; (j<n) ;j++)
            {
                if(points[i] == points[j]) {
                    duplicates++;
                    continue;
                }
                
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = __gcd(dx,dy);
                pair<int,int> ip = {dx/g, dy/g};
                mp[ip]++;
                cur = max(cur,mp[ip]);
            }
            ans=max(ans ,cur+duplicates+1);  
        }
        return ans;
    }
};

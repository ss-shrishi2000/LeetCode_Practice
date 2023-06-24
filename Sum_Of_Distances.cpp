class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        vector<long long> ans(nums.size());

        for(auto it = mp.begin(); it != mp.end(); it++){
            int num = it->first;
            vector<int> ar = it->second;
            if(ar.size() <= 1) {
                int index = ar[0];
                ans[index] = 0;
            } else {
                vector<long long> pref(nums.size(), 0);
                pref[0] = ar[0];
                for(int j = 1; j < ar.size(); j++){
                    pref[j] = ar[j] + pref[j-1];
                }
                // prefix sum created
                int sz = ar.size();
                int firstInd = ar[0];
                ans[firstInd] = pref[sz-1] - firstInd*sz;
                for(int j = 1; j < sz; j++) {
                    long long index = 1LL*(pref[j] - pref[j-1]);
                    long long backSum = (index*j - pref[j-1]);
                    long long forwardSum = (pref[sz-1] - pref[j]) - ((sz-1)-j)*index;
                    ans[index] = backSum + forwardSum;
                }
            }
        }
        return ans;
    }
};

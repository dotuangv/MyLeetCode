class Solution {
public:
    int maxProfitAssignment(vector<int>& dif, vector<int>& pro, vector<int>& worker) {
        unordered_map<int, int> mp;
        for(int i = 0; i < dif.size(); i++)
        {
            mp[dif[i]] = max(mp[dif[i]], pro[i]);
        }
        vector<int> Max(100001);
        for(int i = 1; i <= 100000; i++)
        {
            Max[i]  = max(Max[i - 1], mp[i]);
        }
        int ans =  0;
        for(auto &x: worker) ans += Max[x];
        return ans;
    }
};
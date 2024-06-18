class Solution {
public:
    int maxProfitAssignment(vector<int>& dif, vector<int>& pro, vector<int>& worker) {
        unordered_map<int, int> mp;
        int MAX = worker[0];
        for(auto &x: worker) MAX = max(MAX, x);
        for(int i = 0; i < dif.size(); i++)
        {
            mp[dif[i]] = max(mp[dif[i]], pro[i]);
        }
        vector<int> Max(MAX + 1);
        for(int i = 1; i <= MAX; i++)
        {
            Max[i]  = max(Max[i - 1], mp[i]);
        }
        int ans =  0;
        for(auto &x: worker) ans += Max[x];
        return ans;
    }
};
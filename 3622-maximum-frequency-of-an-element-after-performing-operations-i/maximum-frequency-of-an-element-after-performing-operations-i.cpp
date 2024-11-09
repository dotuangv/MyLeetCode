class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        vector<int> mp(300001), pre(300001);
        for(auto x: nums) mp[x + 100000]++;
        for(int i = 1; i <= 300000; i++){
            pre[i] = pre[i - 1] + mp[i];
        }
        int ans = 0;
        for(int i = 100000; i <= 200000; i++){
            int res = pre[i + k];
            if(i != k) res -= pre[i - k - 1];
            ans = max(ans, mp[i] + min(numOperations, res - mp[i]));
        }
        return ans;
    }
};
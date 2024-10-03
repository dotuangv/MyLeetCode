class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> pre(n + 1);
        for(int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + nums[i];
            pre[i + 1] %= p;
        }

        int ans = n;
        for(int i = 1; i <= n; i++)
        {
            if(pre[i] % p == 0) ans = min(ans, n - i);
            if((pre[n] - pre[i] + p) % p == 0) ans = min(ans, i);
            int x = (pre[n] - pre[i] + p) % p;
            int y = mp[p - x];
            if(y != 0) ans = min(ans, i - y);
            mp[pre[i]] = i;

        }
        return ans == n ? -1 : ans;
        // 3 3 1 4
    }
};
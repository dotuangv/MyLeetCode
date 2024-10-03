auto speedUp = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int S = 0;
        for(int i = 0; i < n; i++)
        {
            S += nums[i];
            S %= p;
        }

        int ans = n, s = 0;
        for(int i = 1; i <= n; i++)
        {
            s += nums[i - 1];
            s %= p;
            int x = (S - s + p) % p;
            int y = mp[p - x];
            if(s % p == 0) ans = min(ans, n - i);
            if(x == 0) ans = min(ans, i);
            if(y != 0) ans = min(ans, i - y);
            mp[s] = i;

        }
        return ans == n ? -1 : ans;
        // 3 3 1 4
    }
};
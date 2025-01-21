class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> pre(n + 2), suf(n + 2);
        for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + grid[1][i - 1];
        for(int i = n; i >= 1; i--) suf[i] = suf[i + 1] + grid[0][i - 1];
        long long ans = 1e18;
        for(int i = 1; i <= n; i++) ans = min(ans, max(pre[i - 1], suf[i + 1]));
        return ans;
    }
};
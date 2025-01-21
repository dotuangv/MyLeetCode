class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long top_sum = 0, bot_sum = 0;
        long long ans = 1e18;
        for(int i = 0; i < n; i++) top_sum += grid[0][i];
        for(int i = 0; i < n; i++) {
            top_sum -= grid[0][i];
            if(i - 1 >= 0) bot_sum += grid[1][i - 1];
            ans = min(ans, max(top_sum, bot_sum));
        }
        return ans;
    }
};
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size()));
        for(int j = 1; j < grid[0].size(); j++)
        {
            int res = 0;
            for(int i = 0; i < grid.size(); i++)
            {
                if(i > 0 && grid[i][j] > grid[i - 1][j - 1]) dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
                if(grid[i][j] > grid[i][j - 1]) dp[i][j] = max(dp[i][j], 1 + dp[i][j - 1]);
                if(i < grid.size() - 1 && grid[i][j] > grid[i + 1][j - 1]) dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j - 1]);
                res = max(dp[i][j], res);
                // cout << dp[i][j] << " ";
            }
            // cout << "\n";
            if(res != j) break;
        }
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++) ans = max(ans, dp[i][j]);
        }
        return ans;
    }
};
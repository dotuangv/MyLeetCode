class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size()));
        for(int i = 0; i < grid[0].size(); i++) dp[0][i] = grid[0][i];
        for(int i = 1; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                int Min = 1e9;
                for(int l = 0; l < grid[i].size(); l++)
                {
                    if(l != j) Min = min(Min, dp[i - 1][l]);
                }
                dp[i][j] = grid[i][j] + Min;
            }
        }
        int ans = 1e9;
        for(int i = 0; i < grid[0].size(); i++) ans = min(ans, dp[grid.size() - 1][i]);
        return ans;
    }
};
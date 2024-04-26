class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> Min(grid.size(), vector<int> (grid[0].size()));
        if(grid.size() == 1) return grid[0][0];
        int Min1, Min2;
        if(grid[0][0] < grid[0][1])
        {
            Min1 = 0;
            Min2 = 1;
        }else
        {
            Min1 = 1;
            Min2 = 0;
        }
        for(int j = 2; j < grid[0].size(); j++)
        {
            if(grid[0][j] < grid[0][Min1])
            {
                if(Min1 != j) Min2 = Min1;
                Min1 = j;
            }else if(grid[0][j] < grid[0][Min2] && j != Min1) Min2 = j;
        }
        for(int j = 0; j < grid[0].size(); j++)
        {
            if(j != Min1) Min[0][j] = grid[0][Min1];
            else Min[0][j] = grid[0][Min2];
        }
        for(int i = 1; i < grid.size(); i++)
        {
            vector<int> dp(grid.size());
            for(int j = 0; j < grid[i].size(); j++)
            {
                dp[j] = grid[i][j] + Min[i - 1][j];
            }
            int Min1, Min2;
            if(dp[0] < dp[1])
            {
                Min1 = 0;
                Min2 = 1;
            }else
            {
                Min1 = 1;
                Min2 = 0;
            }
            for(int j = 0; j < grid.size(); j++)
            {
                if(dp[j] < dp[Min1])
                {
                    if(Min1 != j) Min2 = Min1;
                    Min1 = j;
                }else if(dp[j] < dp[Min2] && j != Min1) Min2 = j;
                for(int j = 0; j < grid.size(); j++)
                {
                    if(j != Min1) Min[i][j] = dp[Min1];
                    else Min[i][j] = dp[Min2];
                }
            }
        }
        int ans = 1e9;
        for(int i = 0; i < grid.size(); i++) ans = min(ans, Min[grid.size() - 1][i]);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> ans;
        vector<vector<pair<int, int>>> dp(land.size(), vector<pair<int, int>> (land[0].size()));
        for(int i = 0; i < land.size(); i++)
        {
            for(int j = 0; j < land[i].size(); j++)
            {
                if(land[i][j] == 1)
                {
                    dp[i][j] = {i, j};
                    if(j != 0)
                    {
                        if(land[i][j - 1] == 1)
                        {
                            dp[i][j] = dp[i][j - 1];
                            dp[i][j - 1] = {-1, -1};
                        }
                    }
                    if(i != 0)
                    {
                        if(land[i - 1][j] == 1)
                        {
                            dp[i][j] = dp[i - 1][j];
                            dp[i - 1][j] = {-1, -1};
                        }
                    }
                }
            }
        }
        for(int i = 0; i < land.size(); i++)
        {
            for(int j = 0; j < land[0].size(); j++)
            {
                if(land[i][j] == 1)
                {
                    if(dp[i][j].first != -1)
                    {
                        ans.push_back({dp[i][j].first, dp[i][j].second, i, j});
                    }
                }
            }
        }
        return ans;
    }
};
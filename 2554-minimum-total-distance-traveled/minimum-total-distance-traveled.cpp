class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int n = factory.size(), m = robot.size();
        vector<vector<long long>> dp(n + 1, vector<long long> (m + 1, 1e12));
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                dp[i][j] = dp[i - 1][j];
                long long l = 1, res = 0, y = factory[i - 1][0];
                while(j - l >= 0 && l <= factory[i - 1][1])
                {
                    res += abs(y - robot[j - l]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - l] + res);
                    l++;
                }
            }
        }
        return dp[n][m];
    }
};
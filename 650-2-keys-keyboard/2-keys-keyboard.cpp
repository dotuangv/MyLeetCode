class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        for(int i = 2; i <= n; i++)
        {
            dp[i] = i;
            for(int j = 2; j <= sqrt(i); j++)
            {
                if(i % j == 0)
                {
                    int l = i/j;
                    dp[i] = min(dp[i], dp[j] + l);
                    dp[i] = min(dp[i], dp[l] + j);
                }
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        vector<int> dp(n + 1);
        dp[1] = 0;
        dp[2] = 2;
        for(int i = 3; i <= n; i++)
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

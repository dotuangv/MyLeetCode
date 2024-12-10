class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int> (2));
        dp[0][0] = -1e9;
        dp[1][0] = -1e9;
        for(int i = 2; i <= n + 1; i++){
            // buy
            dp[i][0] = max(dp[i - 2][1] - prices[i - 2], dp[i - 1][0]);
            // sell
            dp[i][1] = max(dp[i - 1][0] + prices[i - 2], dp[i - 1][1]);
        }
        return dp[n + 1][1];
    }
};
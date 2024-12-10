class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 3, vector<int> (n + 3));
        for(int i = 2; i <= n + 1; i++){
            dp[i][i] = max(0, dp[i - 1][i]);
            for(int j = i + 1; j <= n + 1; j++){
                dp[i][j] = max({dp[i][j], dp[i][j - 1], dp[i - 2][i - 2] + prices[j - 2] - prices[i - 2], dp[i - 1][j]});
            }
        }
        return dp[n + 1][n + 1];
    }
};
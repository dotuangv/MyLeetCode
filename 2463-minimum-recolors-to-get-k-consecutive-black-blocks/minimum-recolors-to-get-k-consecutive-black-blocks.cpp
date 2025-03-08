class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 1e9));
        blocks = " " + blocks;
        for(int i = 1; i <= n; i++){
            dp[i][0] = 0;
            if(blocks[i] == 'B') dp[i][1] = 0;
        }
        dp[0][0] = 0;
        int ans = 1e9;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= min(i, k); j++){
                if(blocks[i] == 'B') dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                else dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                if(j >= k) ans = min(ans, dp[i][k]);
            }
        }
        return ans;
    }
};
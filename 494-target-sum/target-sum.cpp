class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (2001));
        dp[0][-nums[0] + 1000]++;
        dp[0][nums[0] + 1000]++;
        for(int i = 1; i < n; i++){
            int x = nums[i];
            for(int j = 0; j <= 2000; j++){
                if(j - x >= 0) dp[i][j] += dp[i - 1][j - x];
                if(j + x <= 2000) dp[i][j] += dp[i - 1][j + x];
            }
        }
        return dp[n - 1][target + 1000];
    }
};
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto x: nums) sum += x;
        if(sum < abs(target)) return 0;
        vector<vector<int>> dp(n, vector<int> (2*sum + 1));
        dp[0][-nums[0] + sum]++;
        dp[0][nums[0] + sum]++;
        for(int i = 1; i < n; i++){
            int x = nums[i];
            for(int j = 0; j <= 2*sum; j++){
                if(j - x >= 0) dp[i][j] += dp[i - 1][j - x];
                if(j + x <= 2*sum) dp[i][j] += dp[i - 1][j + x];
            }
        }
        return dp[n - 1][target + sum];
    }
};
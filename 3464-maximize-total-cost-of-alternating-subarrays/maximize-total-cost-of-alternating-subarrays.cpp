class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        vector<long long> dp(nums.size() + 2, 0);
        dp[nums.size() - 1] = nums.back();
        for(int i = nums.size() - 2; i >= 0 ; i--)
        {
            dp[i] = max(nums[i] + dp[i  + 1], nums[i] - nums[i + 1] + dp[i + 2]);
        }
        return dp[0];
    }
};
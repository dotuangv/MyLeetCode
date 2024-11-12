class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (1001, 1));
        int ans = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = i - 1; j >= 0; j--){
                int x = nums[i] - nums[j] + 500;
                dp[i][x] = max(dp[i][x], dp[j][x] + 1);
                ans = max(ans, dp[i][x]);
            }
        }
        return ans;
    }
};
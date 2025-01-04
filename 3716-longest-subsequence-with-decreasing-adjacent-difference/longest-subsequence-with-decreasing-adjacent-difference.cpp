class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<vector<int>> dp(301, vector<int> (301));
        vector<bool> check(301);
        check[nums.back()] = true;
        int ans = 0;
        for(int i = nums.size() - 2; i >= 0; i--){
            int Max = 0;
            vector<int> vt(301);
            for(int k = 0; k <= 300; k++){
                if(nums[i] + k <= 300 && check[nums[i] + k]){
                    vt[k] = max(vt[k], dp[nums[i] + k][k] + 1);
                }
                if(nums[i] - k >= 0 && check[nums[i] - k]){
                    vt[k] = max(vt[k], dp[nums[i] - k][k] + 1);
                }
                if(k - 1 >= 0) vt[k] = max(vt[k], vt[k - 1]);
            }
            for(int k = 0; k <= 300; k++){
                dp[nums[i]][k] = max(dp[nums[i]][k], vt[k]);
                ans = max(ans, dp[nums[i]][k]);
            }
            check[nums[i]] = true;
        }
        return ans + 1;
    }
};
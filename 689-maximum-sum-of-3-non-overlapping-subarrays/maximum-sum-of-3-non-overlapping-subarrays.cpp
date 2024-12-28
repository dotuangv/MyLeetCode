class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1);
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        vector<vector<pair<long long, int>>> dp(n + 1, vector<pair<long long, int>> (3, {0, -1}));
        for(int i = 0; i < 3; i++){
            dp[(i + 1)*k][i] = {pre[(i + 1)*k], i*k + 1};
            for(int j = (i + 1)*k + 1; j <= n; j++){
                if(i == 0){
                    if(pre[j] - pre[j - k] > dp[j - 1][i].first){
                        dp[j][i] = {pre[j] - pre[j - k], j - k + 1};
                    }else {
                        dp[j][i] = dp[j - 1][i];
                    }
                }else{
                    if(pre[j] - pre[j - k] + dp[j - k][i - 1].first > dp[j - 1][i].first){
                        dp[j][i] = {pre[j] - pre[j - k] + dp[j - k][i - 1].first, j - k + 1};
                    }else{
                        dp[j][i] = dp[j - 1][i];
                    }
                }
            }
        }
        int c = dp[n][2].second, b = dp[c - 1][1].second, a = dp[b - 1][0].second;
        return {a - 1, b - 1, c - 1};
    }
};
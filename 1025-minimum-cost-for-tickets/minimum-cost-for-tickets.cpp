class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366);
        for(auto x: days) dp[x] = costs[0];
        for(int i = days[0]; i <= 365; i++){
            if(dp[i]) dp[i] = costs[0] + dp[i - 1];
            else dp[i] = dp[i - 1];
            if(i - 7 >= 0 && dp[i - 7] + costs[1] <= dp[i]){
                dp[i] = dp[i - 7] + costs[1];
                for(int j = i - 1; j > i - 7; j--) dp[j] = min(dp[j], dp[i]);
            }
            if(i - 30 >= 0 && dp[i - 30] + costs[2] <= dp[i]){
                dp[i] = dp[i - 30] + costs[2];
                for(int j = i - 1; j > i - 30; j--) dp[j] = min(dp[j], dp[i]);
            }
        }
        return dp.back();
    }
};
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        vector<int> dp(customers.size());
        dp[0] = customers[0][0] + customers[0][1];
        double sum = customers[0][1];
        for(int i = 1; i < customers.size(); i++)
        {
            if(customers[i][0] >= dp[i - 1]) dp[i] = customers[i][0] + customers[i][1];
            else dp[i] = dp[i - 1] + customers[i][1];
            sum += dp[i] - customers[i][0];
        }
        return sum/customers.size();
    }
};
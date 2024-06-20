class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int> (s.size(), 1));
        int ans = 1;
        for(int i = 0; i < s.size(); i++)
        {
            int Max = 1;
            for(int j = i - 1; j >= 0; j--)
            {
                if(s[i] == s[j])
                {
                    if(i > j + 1) dp[j][i] = max(dp[j][i], dp[j + 1][i - 1] + 2);
                    else dp[j][i] = max(dp[j][i], 2);
                }else dp[j][i] = max({dp[j][i], Max, dp[j][i - 1]});
                Max = max(Max, dp[j][i]);
                // cout << j << " " << i << " " << dp[j][i] << "\n";
                ans = max(ans, dp[j][i]);
            }
        }
        return ans;
    }
};
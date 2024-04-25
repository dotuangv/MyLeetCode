class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(s.size(), 1), mp(26, -1);
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 0; j < 26; j++)
            {
                if(abs(s[i] - 'a' - j) <= k)
                {
                    if(mp[j] != -1) dp[i] = max(dp[i], dp[mp[j]] + 1);
                }
            }
            mp[s[i] -'a'] = i;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
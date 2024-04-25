static auto _ = []() { std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26);
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int Max = 0;
            for(int j = 0; j < 26; j++)
            {
                if(abs(s[i] - 'a' - j) <= k)
                {
                    Max = max(Max, dp[j] + 1);
                }
            }
            dp[s[i] - 'a'] = max(Max, dp[s[i] - 'a']);
            ans = max(ans, dp[s[i] - 'a']);
        }
        return ans;
    }
};
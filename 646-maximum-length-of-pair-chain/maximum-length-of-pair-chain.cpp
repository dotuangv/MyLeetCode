class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> dp(pairs.size(), 1);
        int ans = 1;
        for(int i = 1; i < pairs.size(); i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(pairs[i][0] > pairs[j][1]) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
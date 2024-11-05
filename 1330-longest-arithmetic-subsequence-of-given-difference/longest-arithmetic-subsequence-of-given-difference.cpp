class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int ans = 1;
        dp[arr[0]] = 1;
        for(int i = 1; i < arr.size(); i++)
        {
            // dp[arr[i]] = max(dp[arr[i]], 1);
            dp[arr[i]] = max(dp[arr[i]], 1 + dp[arr[i] - difference]);
            ans = max(ans, dp[arr[i]]);
        }
        return ans; 
    }
};
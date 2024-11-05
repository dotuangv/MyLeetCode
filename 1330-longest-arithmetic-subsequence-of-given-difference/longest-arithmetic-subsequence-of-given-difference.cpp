class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        vector<int> dp(20002);
        int ans = 1;
        dp[arr[0] + 10000] = 1;
        for(int i = 1; i < arr.size(); i++)
        {
            // dp[arr[i]] = max(dp[arr[i]], 1);
            if(arr[i] - difference + 10000 >= 0 && arr[i] - difference + 10000 <= 20001)
                dp[arr[i] + 10000] = max(dp[arr[i] + 10000], 1 + dp[arr[i] - difference + 10000]);
            else dp[arr[i] + 10000] = 1;
            ans = max(ans, dp[arr[i] + 10000]);
        }
        return ans; 
    }
};
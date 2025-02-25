class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7, ans = 0;
        vector<vector<int>> dp(arr.size() + 1, vector<int> (2));
        for(int i = 1; i <= arr.size(); i++){
            if(arr[i - 1]%2){
                dp[i][0] = dp[i - 1][1]%mod;
                dp[i][1] = (dp[i - 1][0] + 1)%mod;
            }else{
                dp[i][0] = (dp[i - 1][0] + 1)%mod;
                dp[i][1] = dp[i - 1][1]%mod;
            }
            ans = (ans + dp[i][1])%mod;
        }
        return ans;
    }
};
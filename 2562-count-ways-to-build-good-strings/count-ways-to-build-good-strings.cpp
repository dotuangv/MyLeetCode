class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        dp[0] = 1;
        int mod = 1e9 + 7;
        for(int i = min(zero, one); i <= high; i++){
            if(i - zero >= 0) dp[i] = (dp[i - zero] + dp[i])%mod;
            if(i - one >= 0) dp[i] = (dp[i - one] + dp[i])%mod;
            dp[i] %= mod;
        }
        int sum = 0;
        for(int i = low; i <= high; i++) sum = (sum + dp[i])%mod;
        return sum;
    }
};
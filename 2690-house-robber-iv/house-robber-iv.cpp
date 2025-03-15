class Solution {
public:
    bool isGood(int x, vector<int> &nums, int k){
        vector<int> dp(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= x){
                dp[i] = 1;
                if(i - 2 >= 0) dp[i] = max(dp[i - 1], 1 + dp[i - 2]);
                else if(i - 1 >= 0) dp[i] = max(dp[i], dp[i - 1]);
            }else if(i - 1 >= 0) dp[i] = dp[i - 1];
        }
        return dp.back() >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = 1, r = 1e9;
        while(r > l + 1){
            int mid = (l + r)/2;
            if(isGood(mid, nums, k)) r = mid;
            else l = mid;
        }
        if(isGood(l, nums, k)) return l;
        return r; 
    }
};
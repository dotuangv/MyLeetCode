class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<long long> Max(nums.size());
        long long ans = 0;
        Max.back() = nums.back();
        for(int i = nums.size() - 2; i >= 0; i--){
            Max[i] = max(Max[i + 1], (long long)nums[i]);
        }
        long long Max2 = nums[0];
        for(int i = 1; i < nums.size() - 1; i++){
            ans = max(ans, (Max2 - nums[i]) * Max[i + 1]);
            Max2 = max(Max2, (long long)nums[i]);
        }
        return ans;
    }
};
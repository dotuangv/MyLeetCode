class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<long long> Max(nums.size());
        long long ans = 0;
        Max.back() = nums.back();
        for(int i = nums.size() - 2; i >= 0; i--){
            Max[i] = max(Max[i + 1], (long long)nums[i]);
        }
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size() - 1; j++){
                ans = max(ans, (nums[i] - nums[j]) * Max[j + 1]);
            }
        }
        return ans;
    }
};
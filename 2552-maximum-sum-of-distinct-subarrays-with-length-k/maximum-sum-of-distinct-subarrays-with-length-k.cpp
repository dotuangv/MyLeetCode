class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, sum = 0;
        int l = 0, r = 0;
        int x = *max_element(nums.begin(), nums.end());
        vector<int> mp(x + 1);
        while(r < nums.size()){
            sum += nums[r];
            mp[nums[r]]++;
            if(mp[nums[r]] == 2){
                while(mp[nums[r]] == 2){
                    sum -= nums[l];
                    mp[nums[l++]]--;
                }
                if(r - l + 1 == k) ans = max(ans, sum);
            }else
            {
                if(r - l + 1 == k) ans = max(ans, sum);
                else if (r - l + 1 > k){
                    mp[nums[l]]--;
                    sum -= nums[l++];
                    ans = max(ans, sum);
                }
            }
            r++;
        }
        return ans;
    }
};
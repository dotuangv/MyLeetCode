class Solution {
public:

    long long countGood(vector<int>& nums, int k) {
        long long ans = 0, l = 0, r = l + 1, n = nums.size(), cnt = 0;
        unordered_map<int, long long> mp;
        mp[nums[l]]++;
        while(r < n){
            cnt += mp[nums[r]];
            mp[nums[r]]++;
            if(cnt < k) r++;
            else{
                while(cnt >= k){
                    ans += n - r;
                    cnt += 1 - mp[nums[l]];
                    mp[nums[l]]--;
                    l++;
                }
                r++;
            }
        }
        return ans;

    }
};
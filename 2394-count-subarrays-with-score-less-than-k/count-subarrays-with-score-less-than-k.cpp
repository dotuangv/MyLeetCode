class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long l = 0, r = 0, sum = 0, res = 0, n = nums.size();
        while(r < n){
            sum += nums[r];
            while(sum * (r - l + 1) >= k){
                res += n - r;
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return n * (n + 1)/2 - res;
    }
};
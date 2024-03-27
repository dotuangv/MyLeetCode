class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int l = 0, r = 0, mul = 1;
        while(r < nums.size())
        {
            
            if(mul * nums[r] < k)
            {
                ans += (r - l + 1);
                mul *= nums[r];
                r++;
            }else
            {
                mul /= nums[l];
                if(mul == 0) mul = 1;
                l++;
            }
            if(l > r) r = l;
        }
        return ans;

    }
};
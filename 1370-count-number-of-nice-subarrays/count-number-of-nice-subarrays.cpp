class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0, r = 0, res = 0, ans = 0;
        while(r < nums.size())
        {
            if(nums[r] % 2) 
            {
                res++;
                r++;
            }else r++;
            if(res == k)
            {
                int cnt1 = 0, cnt2 = 0;
                while(nums[l] % 2 == 0)
                {
                    l++;
                    cnt1++;
                }
                while(r < nums.size() && nums[r] % 2 == 0)
                {
                    r++;
                    cnt2++;
                }
                ans += (cnt1 + 1)*(cnt2 + 1);
                l++;
                res--;
            }
        }
        return ans;
    }
};
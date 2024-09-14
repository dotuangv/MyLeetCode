class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int Max = *max_element(nums.begin(), nums.end());
        int ans = 1, l = 0, r = 0;
        while(r < nums.size())
        {
            if(nums[r] == Max) r++;
            else
            {
                r++;
                l = r;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};
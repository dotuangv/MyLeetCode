class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        unordered_map<int, int> mp;
        int ans = 0;
        int l = 0, r = 0;
        while(r < nums.size())
        {
            if(mp[nums[r]] < k)
            {
                mp[nums[r]]++;
                r++;
            }
            else
            {
                mp[nums[l]]--;
                l++;
            }
            ans = max(r - l, ans);
        }
        return ans;
    }
};
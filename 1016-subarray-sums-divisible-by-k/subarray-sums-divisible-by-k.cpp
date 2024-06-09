class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        unordered_map<int, int> mp;
        vector<int> pre(nums.size() + 1);
        for(int i = 0; i < nums.size(); i++)
        {
            pre[i + 1] = (pre[i] + nums[i]%k + k)%k;
            mp[pre[i + 1]]++;
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ans += mp[pre[i]];
            mp[pre[i + 1]]--;
        }
        return ans;
    }
};
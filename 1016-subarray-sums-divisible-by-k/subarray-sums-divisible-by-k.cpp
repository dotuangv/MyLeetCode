class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            nums[i] = (nums[i]%k + k)%k;
            // cout << nums[i] << " ";
        }
        // cout<<"\n";
        vector<int> pre(nums.size() + 1);
        for(int i = 0; i < nums.size(); i++)
        {
            pre[i + 1] = (pre[i] + nums[i])%k;
            mp[pre[i + 1]]++;
            // cout << pre[i + 1] << " ";
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
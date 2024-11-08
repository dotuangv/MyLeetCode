class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> pre(nums.size());
        pre[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) pre[i] = pre[i - 1] ^ nums[i];
        int res = pow(2, maximumBit) - 1;
        vector<int> ans;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            ans.push_back((pre[i] | res)^pre[i]);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> pre(nums.size());
        pre[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) pre[i] = pre[i - 1] ^ nums[i];
        bitset<21> y(pow(2, maximumBit) - 1);
        vector<int> ans;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            bitset<21> x(pre[i]);
            bool ok = false;
            bitset<21> tmp(0);
            for(int j = 20; j >= 0; j--)
            {
                if(x[j] == 0)
                {
                    if(y[j] == 1) tmp[j] = 1;
                    else
                    {
                        if(ok) tmp[j] = 1;
                    }
                }else
                {
                    if(y[j] == 1) ok = true;
                }
            }
            ans.push_back(tmp.to_ulong());
        }
        return ans;
    }
};
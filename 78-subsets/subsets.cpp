class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = pow(2, nums.size());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)
        {
            vector<int> vt;
            bitset<10> b(i);
            for(int j = 0; j < nums.size(); j++)
            {
                if(b[j]) vt.push_back(nums[j]);
            }
            ans.push_back(vt);
        }
        return ans;
    }
};
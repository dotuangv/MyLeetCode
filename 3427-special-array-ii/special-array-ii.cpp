class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> ans(queries.size());
        vector<int> pre(n);
        pre[0] = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] % 2 != nums[i - 1]%2) pre[i] = pre[i - 1];
            else pre[i] = i;
        }
        for(int i = 0; i < queries.size(); i++){
            if(queries[i][0] >= pre[queries[i][1]]) ans[i] = true;
        }
        return ans;
    }
};
class Solution {
public:

    int ans = 0;
    void backtrack(int i, int l, int k, vector<bool> &visit, vector<int> &nums, int XOR)
    {
        if(i == k)
        {
            ans += XOR;
            return;
        }
        for(int j = l; j < nums.size(); j++)
        {
            if(!visit[j])
            {
                visit[j] = true;
                backtrack(i + 1, j, k, visit, nums, XOR ^ nums[j]);
                visit[j] = false;
            }
        }
    }
    int subsetXORSum(vector<int>& nums) {
        vector<bool> visit(nums.size());
        for(int i = 1; i <= nums.size(); i++)
        {
            backtrack(0, 0, i, visit, nums, 0);
        }
        return ans;
    }
};
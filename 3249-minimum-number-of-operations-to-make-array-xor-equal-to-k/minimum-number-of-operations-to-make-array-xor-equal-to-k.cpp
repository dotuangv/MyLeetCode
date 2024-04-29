class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<int>> bit(nums.size(), vector<int> (20));
        for(int i = 0; i < nums.size(); i++)
        {
            int j = 0;
            while(nums[i])
            {
                bit[i][j++] = nums[i] % 2;
                nums[i] /= 2;
            }
        }
        vector<int> bitk(20);
        int j = 0;
        while(k)
        {
            bitk[j++] = k % 2;
            k /= 2;
        }
        int ans = 0;
        for(int i = 0; i < 20; i++)
        {
            int t = 0;
            for(int j = 0; j < nums.size(); j++) t ^= bit[j][i];
            if(t != bitk[i])
            {
                ans++;
            }
        }
        return ans;
    }
};
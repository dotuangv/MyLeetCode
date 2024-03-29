class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);  
        cin.tie(nullptr);            
        cout.tie(nullptr); 
        int Max = *max_element(nums.begin(), nums.end());
        int l = 0, r = 0, sum = 0;
        long long ans = 0;
        while(r < nums.size())
        {
            if(nums[r] == Max) sum++;
            if(sum == k)
            {
                long long x = 0;
                while(l < r && nums[l] != Max)
                {
                    l++;
                    x++;
                }
                sum--;
                l++;
                ans += (x + 1)*(nums.size() - r);
            }
            r++;
        }
        return ans;
    }
};
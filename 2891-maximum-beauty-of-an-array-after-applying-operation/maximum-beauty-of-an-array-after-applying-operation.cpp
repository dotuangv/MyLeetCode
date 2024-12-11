class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int l = i, r = nums.size() - 1;
            while(r > l + 1){
                int mid = (l + r)/2;
                if(nums[mid] <= nums[i] + 2*k) l = mid;
                else r = mid;
            }
            if(nums[r] <= nums[i] + 2*k) ans = max(ans, r - i + 1);
            else ans = max(ans, l - i + 1);
        }
        return ans;
    }
};
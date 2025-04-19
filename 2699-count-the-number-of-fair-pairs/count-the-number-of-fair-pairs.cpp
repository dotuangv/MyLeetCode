class Solution {
public:
    int upperb(int i, int x, vector<int> &nums){
        int l = i, r = nums.size() - 1;
        while(r > l + 1){
            int mid = (l + r)/2;
            if(nums[mid] <= x) l = mid;
            else r = mid;
        }
        if(nums[r] <= x) return r;
        if(nums[l] <= x) return l;
        return -1;
    }

    int lowerb(int i, int x, vector<int> &nums){
        int l = i, r = nums.size() - 1;
        while(r > l + 1){
            int mid = (l + r)/2;
            if(nums[mid] >= x) r = mid;
            else l = mid;
        }
        if(nums[l] >= x) return l;
        if(nums[r] >= x) return r;
        return nums.size() + 1;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int l = lowerb(i, lower - nums[i], nums);
            int r = upperb(i, upper - nums[i], nums);
            if(l <= r){
                ans += r - l + 1;
                if(l == i || r == i) ans--;
            }
        }
        return ans;
    }
};
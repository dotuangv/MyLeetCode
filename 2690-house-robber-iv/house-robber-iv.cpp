class Solution {
public:
    bool isGood(int x, vector<int> &nums, int k){
        int i = 0;
        while(i < nums.size()){
            if(nums[i] <= x){
                k--;
                i += 2;
            }else i++;
            if(k == 0) return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        while(r > l + 1){
            int mid = (l + r)/2;
            if(isGood(mid, nums, k)) r = mid;
            else l = mid;
        }
        if(isGood(l, nums, k)) return l;
        return r; 
    }
};
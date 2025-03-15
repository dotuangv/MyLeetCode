class Solution {
public:
    bool isGood(int x, vector<int> &nums, int k){
        int i = 0;
        while(i < nums.size()){
            if(nums[i] <= x){
                k--;
                i += 2;
            }else i++;
        }
        return k <= 0;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = 1, r = 1e9;
        while(r > l + 1){
            int mid = (l + r)/2;
            if(isGood(mid, nums, k)) r = mid;
            else l = mid;
        }
        if(isGood(l, nums, k)) return l;
        return r; 
    }
};
class Solution {
public:
    bool isGood(int x, vector<int> &nums, int maxOperations){
        int res = 0;
        for(auto &y: nums) res += (y - 1)/x;
        return res <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = 1e9;
        while(r > l + 1){
            int mid = (l + r)/2;
            if(isGood(mid, nums, maxOperations)) r = mid;
            else l = mid;
        }
        if(isGood(l, nums, maxOperations)) return l;
        return r;
    }
};
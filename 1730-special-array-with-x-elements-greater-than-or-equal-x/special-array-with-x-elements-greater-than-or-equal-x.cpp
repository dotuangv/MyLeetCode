class Solution {
public:
    int isGood(vector<int> &nums, int x)
    {
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] >= x) res++;
        }
        if(res == x) return 1;
        else if(res > x) return 2;
        else return 0;
    }
    int specialArray(vector<int>& nums) {
        int l = 1, r = nums.size();
        while(r > l + 1)
        {
            int mid = (l + r)/2;
            if(isGood(nums,mid)) l = mid;
            else r = mid;
        }
        if(isGood(nums,l) == 1) return l;
        if(isGood(nums,r) == 1) return r;
        return -1;
    }
};
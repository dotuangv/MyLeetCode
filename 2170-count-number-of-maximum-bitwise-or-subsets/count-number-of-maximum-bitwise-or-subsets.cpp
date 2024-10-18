class Solution {
public:
    int max,count;
    int countMaxOrSubsets(vector<int>& nums) {
        max = 0,count = 0;

        int target = 0;
        for(auto &s:nums){
            target |= s;
        }

        solve(nums,0,0,target);
        return count;
    }
    void solve(vector<int>&nums,int pos,int result,int target){
        if(result == target){
            count += 1 << (nums.size()-pos);
            return;
        }

        if(pos == nums.size()) return;

        solve(nums,pos+1,result | nums[pos],target);

        solve(nums,pos+1,result,target);
    }
};
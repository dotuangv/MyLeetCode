class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
     int count =0;
     sort(nums.begin(),nums.end());
     for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]){
            int diff=1;
            count+=diff;
            nums[i]=nums[i]+diff;
        }
        if(nums[i]<nums[i-1]){
            int diff=nums[i-1]-nums[i]+1;
            count+=diff;
            nums[i]=nums[i]+diff;
        }
     }
     return count;
    }
};
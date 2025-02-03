class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, s1 = 1, s2 = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]){
                s1++;
                s2 = 1;
            }else if(nums[i] < nums[i - 1]){
                s2++;
                s1 = 1;
            }else{
                s1 = 1;
                s2 = 1;
            }
            ans = max({ans, s1, s2});
        }
        return ans;
    }
};
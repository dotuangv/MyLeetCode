class Solution {
public:
    int minOperations(vector<int>& nums) {
        int j = 0, n = nums.size(), ans = 0;
        while(j < n){
            if(nums[j] == 0){
                if(j + 2 >= n) return -1;
                nums[j + 1] = !nums[j + 1];
                nums[j + 2] = !nums[j + 2];
                ans ++;
            }
            j++;
        }
        return ans;
    }
};
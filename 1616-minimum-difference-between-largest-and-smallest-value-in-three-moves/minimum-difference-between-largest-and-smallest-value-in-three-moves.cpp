static int _ = [](){ std::ios_base::sync_with_stdio(false); 
        std::cin.tie(nullptr); return 0;}();
class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) return 0;
        sort(nums.begin(), nums.end());
        return min({nums.back() - nums[3], nums[nums.size() - 4] - nums[0], nums[nums.size() - 2] - nums[2], nums[nums.size() - 3] - nums[1]});
    }
};
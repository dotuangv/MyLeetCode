class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        int n = nums.size();
        int i = 0;
        while(i < n)
        {
            if(nums[i] > 0 && nums[i] <= n)
            {
                if(nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
                else i++;
            }else i++;
        }
        for(i = 0; i < n; i++) if(nums[i] != i + 1) return i + 1;
        return n + 1;
    }
};
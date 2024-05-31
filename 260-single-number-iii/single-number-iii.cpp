class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = 0;
        for(auto &x: nums) XOR ^= x;
        int index = 0;
        while(((XOR >> index) & 1) != 1) index++;
        int x = 0, y = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(((nums[i] >> index) & 1) != 1) x ^= nums[i];
            else y ^= nums[i];
        }
        return {x, y};
    }
};
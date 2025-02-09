class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[i - nums[i]]++;
        }
        long long sum = 0;
        for(auto [x, y]: mp){
            if(y >= 2) sum += y * (y - 1)/2;
        }
        return nums.size() * (nums.size() - 1)/2 - sum;
    }
};
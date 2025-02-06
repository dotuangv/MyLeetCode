class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, set<int>> mp;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] != nums[j]){
                    mp[nums[i] * nums[j]].insert(nums[i]);
                    mp[nums[i] * nums[j]].insert(nums[j]);
                }
            }
        }
        int ans = 0;
        for(auto &[_, x]: mp){
            if(x.size() < 4) continue;
            int y = x.size()/2;
            ans += y * (y - 1) * 2 * 2;
        }
        return ans;
    }
};
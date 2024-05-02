class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(auto x: nums) mp[x] = true;
        int ans = 0;
        for(auto x: nums) 
            if(mp[-x])
            {
                if(abs(x) > ans) ans = abs(x);
            }
        if(ans == 0) return -1;
        return ans;
    }
};
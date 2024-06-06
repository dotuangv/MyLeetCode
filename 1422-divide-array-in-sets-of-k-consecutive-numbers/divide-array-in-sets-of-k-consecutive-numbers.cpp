class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        if(nums.size() % k) return false;
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        for(auto x: nums) mp[x]++;
        for(auto &x: mp)
        {
            if(x.second > 0)
            {
                for(int i = x.first + 1; i < x.first + k; i++)
                {
                    if(mp[i] < x.second) return false;
                    mp[i] -= x.second;
                }
            }else if(x.second < 0) return false;
        }
        return true;
    }
};
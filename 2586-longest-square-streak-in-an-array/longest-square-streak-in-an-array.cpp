class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(auto x: nums) mp[x] = true;
        int ans = 0;
        for(auto x: nums)
        {
            int res = 0, y = x;
            while(mp[y])
            {
                res++;
                if(y > 1e9/y) break;
                y *= y;
            }
            ans = max(ans, res);
        }
        return (ans != 1)? ans : -1;
    }
};
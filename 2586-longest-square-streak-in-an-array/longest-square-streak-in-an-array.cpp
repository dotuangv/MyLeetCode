#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("O3", "unroll-loops")
#pragma GCC optimize ("-ffloat-store")

auto init = []() { 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
} ();
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
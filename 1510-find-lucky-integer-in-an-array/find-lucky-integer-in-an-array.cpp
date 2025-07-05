class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto x: arr) mp[x]++;
        int ans = -1 ;
        for(auto [x, y] : mp) {
            if(x == y) ans = max(ans, x);
        }
        return ans;
    }
};
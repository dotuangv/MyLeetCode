class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        unordered_set<int> se;
        for(int i = 0; i < arr.size(); i++) {mp[arr[i] % k]++; se.insert(arr[i] % k);}
        for(auto x: se)
        {
            int t = 1;
            if(x < 0) t = -1;
            int y = min(mp[x], mp[-x]);
            if(x == 0)
            {
                mp[x] -= y/2;
                mp[-x] -= y/2;
            }else
            {
                mp[x] -= y;
                mp[-x] -= y;
            }
            int z = min(mp[x], mp[t*k - x]);
            if(x == t*k - x)
            {
                mp[x] -= z/2;
                mp[t*k - x] -= z/2;
            } else
            {
                mp[x] -= z;
                mp[t*k - x] -= z;
            }
            if(mp[x]) return false;
        }
        return true;
        
    }
};
static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
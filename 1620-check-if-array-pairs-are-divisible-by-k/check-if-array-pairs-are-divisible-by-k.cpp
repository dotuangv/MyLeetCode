class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int> mp;
        for(int i = 0; i < arr.size(); i++) mp[arr[i] % k]++;
        // for(auto x: mp) cout << x.first << " " << x.second << "\n";
        for(auto x: mp)
        {
            int t = 1;
            if(x.first < 0) t = -1;
            // cout << x.first << " " << mp[x.first] << " " << mp[t*k - x.first] << " " << mp[-x.first] << "\n";
            int y = min(mp[x.first], mp[-x.first]);
            if(x.first == 0)
            {
                mp[x.first] -= y/2;
                mp[-x.first] -= y/2;
            }else
            {
                mp[x.first] -= y;
                mp[-x.first] -= y;
            }
            int z = min(mp[x.first], mp[t*k - x.first]);
            // cout << x.first << " " << mp[x.first] << " " << mp[t*k - x.first] << " " << mp[-x.first] << "\n";
            if(x.first == t*k - x.first)
            {
                mp[x.first] -= z/2;
                mp[t*k - x.first] -= z/2;
            } else
            {
                mp[x.first] -= z;
                mp[t*k - x.first] -= z;
            }
            // cout << x.first << " " << mp[x.first] << " " << mp[t*k - x.first] << " " << mp[-x.first] << "\n";
            if(mp[x.first]) return false;
        }
        return true;
        
    }
};
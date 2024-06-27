class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        for(auto x: edges)
        {
            mp[x[0]]++;
            mp[x[1]]++;
            if(mp[x[0]] > 1) return x[0];
            if(mp[x[1]] > 1) return x[1];
        }
        return 0;
    }
};
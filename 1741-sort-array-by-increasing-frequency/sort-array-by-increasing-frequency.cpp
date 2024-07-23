class Solution {
public:
    static bool compare(pair<int, int> a, pair<int, int> b)
    {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int>> pa;
        unordered_map<int, int> mp;
         for(auto &x: nums) mp[x]++;
         for(auto &x: mp)
         {
            pa.push_back({x.second, x.first});
         }
         vector<int> ans;
         sort(pa.begin(), pa.end(), compare);
         for(auto &x: pa)
         {
            while(x.first--)
            {
                ans.push_back(x.second);
            }
         }
         return ans;
    }
};
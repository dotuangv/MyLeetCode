class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(auto &x: nums1) mp[x]++;
        vector<int> ans;
        for(auto &y: nums2)
        {
            if(mp[y])
            {
                ans.push_back(y);
                mp[y]--;
            }
        }
        return ans;
    }
};
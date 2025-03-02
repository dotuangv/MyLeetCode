class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mp;
        vector<vector<int>> vt;
        for(int i = 0; i < nums1.size(); i++){
            mp[nums1[i][0]]+= nums1[i][1];
        }
        for(int i = 0; i < nums2.size(); i++){
            mp[nums2[i][0]]+= nums2[i][1];
        }
        for(auto x: mp){
            vt.push_back({x.first,x.second});
        }
        return vt;
    }
};
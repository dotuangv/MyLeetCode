class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp1, mp2;
        set<int> s;
        vector<int> vt;
        for(auto x: nums1) mp1[x]++;
        for(auto x: nums2) mp2[x]++;
        if(nums1.size() < nums2.size()){
            for(int i = 0; i < nums1.size(); i++){
                if(mp1[nums1[i]] > 0 && mp2[nums1[i]] > 0 && s.find(nums1[i]) == s.end()){
                    s.insert(nums1[i]);
                    for(int j = 0; j < min(mp1[nums1[i]],mp2[nums1[i]]); j++){
                        vt.push_back(nums1[i]);
                    }
                }
            }
        }else{
            for(int i = 0; i < nums2.size(); i++){
                if(mp1[nums2[i]] > 0 && mp2[nums2[i]] > 0 && s.find(nums2[i]) == s.end()){
                    s.insert(nums2[i]);
                    for(int j = 0; j < min(mp1[nums2[i]],mp2[nums2[i]]); j++){
                        vt.push_back(nums2[i]);
                    }
                }
            }
        }
        return vt;
    }
};
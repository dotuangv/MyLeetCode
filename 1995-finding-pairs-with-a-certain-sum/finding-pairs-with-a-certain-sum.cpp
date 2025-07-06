class FindSumPairs {
public:
    unordered_map<int, int> mp;
    vector<int> vt1, vt2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vt1 = nums1;
        vt2 = nums2;
        for(int i = 0; i < nums2.size(); i++) mp[nums2[i]]++;
    }
    
    void add(int index, int val) {
        mp[vt2[index]]--;
        vt2[index] += val;
        mp[vt2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int i = 0; i < vt1.size(); i++) {
            ans += mp[tot  - vt1[i]];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
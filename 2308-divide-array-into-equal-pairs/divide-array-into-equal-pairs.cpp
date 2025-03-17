class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> vt(501);
        for(auto &x : nums) vt[x]++;
        for(auto &x: vt) if(x % 2) return false;
        return true;
    }
};
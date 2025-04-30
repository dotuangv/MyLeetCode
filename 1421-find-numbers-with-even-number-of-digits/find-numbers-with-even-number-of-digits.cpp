class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto &x: nums){
            if((int)log10(x) % 2) ans++;
        }
        return ans;
    }
};
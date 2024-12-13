class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int ,int>> vt;
        vector<bool> check(nums.size());
        for(int i = 0; i < nums.size(); i++) vt.push_back({nums[i], i});
        long long ans = 0;
        sort(vt.begin(), vt.end());
        for(int i = 0; i < nums.size(); i++){
            if(!check[vt[i].second]){
                ans += vt[i].first;
                check[vt[i].second] = true;
                if(vt[i].second - 1 >= 0) check[vt[i].second - 1] = true;
                if(vt[i].second + 1 < nums.size()) check[vt[i].second + 1] = true;
            }
        }
        return ans;

    }
};
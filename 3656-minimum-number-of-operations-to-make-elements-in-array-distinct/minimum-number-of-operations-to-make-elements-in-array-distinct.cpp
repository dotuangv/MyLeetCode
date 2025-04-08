class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i+=3){
            map<int, int> mp;
            bool ok = true;
            for(int j = i; j < nums.size(); j++){
                mp[nums[j]]++;
                if(mp[nums[j]] >= 2) ok = false;
            }
            if(ok) return ans;
            else ans++;
        }
        return ans;
    }
};
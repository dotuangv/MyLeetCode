class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto x: arr) mp[x]++;
        for(auto x: arr){
            mp[x]--;
            if(mp[x*2] > 0 || (x % 2 == 0 && mp[x/2] > 0)) return true;
            mp[x]++;
        }
        return false;
    }
};
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for(auto &x: arr) mp[x]++;
        int res = 1;
        for(auto &x: arr)
        {
            if(mp[x] == 1)
            {
                if(res == k) return x;
                else res++;
            }
        }
        return "";
    }
};
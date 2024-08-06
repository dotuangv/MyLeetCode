class Solution {
public:
    int minimumPushes(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<char,int> mp;
        for(auto x: word) mp[x]++;
        vector<int> vt;
        for(auto x: mp) vt.push_back(x.second);
        sort(vt.begin(), vt.end(), greater<int> ());
        int ans = 0;
        for(int i = 0; i <= 3; i++)
        {
            for(int j = i*8; j < min(int(vt.size()), (i + 1)*8); j++)
            {
                ans += (i + 1)*vt[j];
            }
        }
        return ans;
    }
};
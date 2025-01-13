class Solution {
public:
    int minimumLength(string s) {
        int ans = 0;
        vector<int> v(26);
        for(auto &c: s) v[c - 'a']++;
        for(int i = 0; i < 26; i++){
            if(v[i] == 0) continue;
            if(v[i] % 2) ans ++;
            else ans += 2;
        }
        return ans;
    }
};
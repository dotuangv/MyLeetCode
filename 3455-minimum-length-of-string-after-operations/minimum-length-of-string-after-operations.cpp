class Solution {
public:
    int minimumLength(string s) {
        int ans = 0;
        vector<int> v(26);
        for(auto &c: s) v[c - 'a']++;
        for(int i = 0; i < 26; i++){
            while(v[i] >= 3) v[i] -= 2;
            ans += v[i];
        }
        return ans;
    }
};
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0, res = 0;
        unordered_map<string, int> mp;
        for(auto &s: words) mp[s]++;
        for(auto &s: words) {
            if(s[0] == s[1]){
                if(mp[s] >= 2){
                    ans += 4;
                    mp[s] -= 2;
                }else if(mp[s] == 1){
                    mp[s]--;
                    res = 2;
                }
            }
            else {
                string s2 = s;
                swap(s[0], s[1]);
                if(mp[s] && mp[s2]){
                    ans += 4;
                    mp[s]--;
                    mp[s2]--;
                }
            }
        }
        return ans + res;
    }
};
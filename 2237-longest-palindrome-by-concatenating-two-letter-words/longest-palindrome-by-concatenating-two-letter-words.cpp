class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0, res = 0;
        vector<vector<int>> mp(26, vector<int> (26));
        for(auto &s: words) mp[s[0] - 'a'][s[1] - 'a']++;
        for(auto &s: words) {
            if(s[0] == s[1]){
                if(mp[s[0] - 'a'][s[1] - 'a'] >= 2){
                    ans += 4;
                    mp[s[0] - 'a'][s[1] - 'a'] -= 2;
                }else if(mp[s[0] - 'a'][s[1] - 'a'] == 1){
                    mp[s[0] - 'a'][s[1] - 'a']--;
                    res = 2;
                }
            }
            else {
                if(mp[s[0] - 'a'][s[1] - 'a'] && mp[s[1] - 'a'][s[0] - 'a']){
                    ans += 4;
                    mp[s[0] - 'a'][s[1] - 'a']--;
                    mp[s[1] - 'a'][s[0] - 'a']--;
                }
            }
        }
        return ans + res;
    }
};
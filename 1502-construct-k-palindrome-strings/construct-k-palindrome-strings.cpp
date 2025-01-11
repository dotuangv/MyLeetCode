class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        vector<int> vt(26);
        for(int i = 0; i < s.size(); i++){
            vt[s[i] - 'a']++;
        }
        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(vt[i] % 2) cnt++;
        }
        return cnt <= k;

    }
};
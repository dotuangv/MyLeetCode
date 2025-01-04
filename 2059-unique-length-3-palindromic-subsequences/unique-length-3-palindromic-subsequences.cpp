class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>> pre(s.size(), vector<int> (26));
        vector<int> Min(26, 1e6), Max(26, -1);
        pre[0][s[0] - 'a'] = 1;
        Min[s[0] - 'a'] = 0;
        for(int i = 1; i < s.size(); i++){
            for(int j = 0; j < 26; j++){
                pre[i][j] = pre[i - 1][j];
            }
            pre[i][s[i] - 'a']++;
            Max[s[i] - 'a'] = max(Max[s[i] - 'a'], i);
            Min[s[i] - 'a'] = min(Min[s[i] - 'a'], i);
        }
        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(Min[i] < Max[i] && Max[i] != -1){
                for(int j = 0; j < 26; j++){
                    if(pre[Max[i] - 1][j] - pre[Min[i]][j] > 0) ans++;
                }
            }
        }
        return ans;

    }
};
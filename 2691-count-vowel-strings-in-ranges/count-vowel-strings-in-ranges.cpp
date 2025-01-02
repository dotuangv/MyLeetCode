class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c== 'i' || c == 'o' || c == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans(queries.size()), pre(words.size() + 1);
        for(int i = 1; i <= words.size(); i++){
            pre[i] = pre[i - 1];
            if(isVowel(words[i - 1][0]) && isVowel(words[i - 1].back())) pre[i]++;
        }
        for(int i = 0; i < queries.size(); i++){
            ans[i] = pre[queries[i][1] + 1] - pre[queries[i][0]];
        }
        return ans;
    }
};
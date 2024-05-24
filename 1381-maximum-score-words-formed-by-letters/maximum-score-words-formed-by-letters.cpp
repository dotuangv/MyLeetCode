class Solution {
public:
    void solve(int i, int& n, vector<int>& mp, vector<int>& score, int& ans, int sum, vector<string>& words){
        ans = max(ans, sum);

        if(i >= n) return ;

        vector<int> tempMap = mp;

        int j = 0;
        int sum2 = 0;

        for(j = 0; j < words[i].length(); j++){
            tempMap[words[i][j] - 'a']--;
            sum2+= score[words[i][j] - 'a'];
            if(tempMap[words[i][j]-'a'] < 0) break;
        }

        if( j == words[i].length()){
            solve(i+1, n, tempMap, score, ans, sum + sum2, words);
        }
        solve(i+1, n, mp, score, ans, sum, words);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> mp(26, 0);
        for(char i : letters){
            mp[i - 'a']++;
        }
        int ans = 0;
        int n = words.size();
        solve(0, n, mp, score, ans, 0, words);
        return ans;
    }
};
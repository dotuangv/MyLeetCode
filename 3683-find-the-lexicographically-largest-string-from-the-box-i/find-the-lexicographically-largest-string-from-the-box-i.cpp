class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        vector<string> vt;
        char c = 'a';
        for(auto &x: word) c = max(c, x);
        for(int i = 0; i < word.size(); i++){
            if(word[i] == c){
                string s = ""; s.push_back(c);
                int k = max(0, numFriends - i - 1);
                for(int j = i + 1; j < word.size() - k; j++) s.push_back(word[j]);
                vt.push_back(s);
            }
        }
        sort(vt.begin(), vt.end());
        return vt.back();
    }
};
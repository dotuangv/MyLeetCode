class Solution {
public:
    bool isCircularSentence(string s) {
        for(int i = 2; i < s.size(); i++)
        {
            if(s[i - 1] == ' '){
                if(s[i] != s[i - 2]) return false;
            }
        }
        return s.back() == s[0];
    }
};
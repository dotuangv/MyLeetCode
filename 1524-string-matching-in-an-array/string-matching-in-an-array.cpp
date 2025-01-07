class Solution {
public:
    bool check(string &s1, string &s2){
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] == s2[0]){
                int k = 1;
                for(int j = i + 1; j < s1.size() && k < s2.size(); j++){
                    if(s1[j] == s2[k]) k++;
                    else break;
                }
                if(k == s2.size()) return true;
            }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words.size(); j++){
                if(i == j) continue;
                if(check(words[j], words[i])){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
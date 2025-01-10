class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> Max(26);
        for(int i = 0; i < words2.size(); i++){
            vector<int> v(26);
            for(int j = 0; j < words2[i].size(); j++){
                v[words2[i][j] - 'a']++;
            }
            for(int j = 0; j < 26; j++){
                Max[j] = max(Max[j], v[j]);
            }
        }
        for(int i = 0; i < words1.size(); i++){
            vector<int> v(26);
            for(int j = 0; j < words1[i].size(); j++){
                v[words1[i][j] - 'a']++;
            }
            bool ok = true;
            for(int j = 0; j < 26; j++){
                if(v[j] < Max[j]){
                    ok = false;
                    break;
                }
            }
            if(ok) ans.push_back(words1[i]);
        }
        return ans;
    }
};
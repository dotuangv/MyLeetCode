class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int index = groups[0];
        vector<string> ans;
        for(int i = 0; i < words.size(); i++){
            if(groups[i] == index) {
                ans.push_back(words[i]);
                index = !index;
            }
        }
        return ans;
    }
};
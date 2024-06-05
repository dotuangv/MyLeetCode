class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<vector<int>> vt(words.size(), vector<int> (26));
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                vt[i][words[i][j] - 'a']++;
            }
        }
        for(int i = 0; i < 26; i++)
        {
            int t = 1e9;
            for(int j = 0; j < words.size(); j++)
            {
                t = min(t, vt[j][i]);;
            }

                while(t--)
                {
                    string res = "";
                    res += char(i + 'a');
                    ans.push_back(res);
                }
        }
        return ans;
    }
};
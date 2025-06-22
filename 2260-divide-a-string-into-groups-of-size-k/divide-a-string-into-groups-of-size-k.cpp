class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int i = 0, n = s.size();
        vector<string> ans;
        while(i < n) {
            string str = "";
            for(int j = i; j < min(i + k, n); j++) {
                str.push_back(s[j]);
            }
            if(str.size() != k) {
                for(int j = str.size(); j < k; j++) {
                    str.push_back(fill);
                }
            }
            i += k;
            ans.push_back(str);
        }
        return ans;
    }
};
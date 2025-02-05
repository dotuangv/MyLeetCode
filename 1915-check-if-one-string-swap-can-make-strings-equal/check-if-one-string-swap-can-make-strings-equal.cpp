class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> vt;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]) vt.push_back(i);
            if(vt.size() > 2) return false; 
        }
        if(vt.size() == 1) return false;
        else if(vt.empty()) return true;
        return (s1[vt[0]] == s2[vt[1]]) && (s1[vt[1]] == s2[vt[0]]);

    }
};
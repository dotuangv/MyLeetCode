class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(26), v2(26);
        for(auto x: s1) v1[x - 'a']++;
        int l = 0, r = 0;
        while(r < s2.size())
        {
            if(v1[s2[r] - 'a'] > v2[s2[r] - 'a'])
            {
                v2[s2[r] - 'a']++;
                if(v2[s2[r] - 'a'] == v1[s2[r] - 'a'])
                {
                    bool ok = true;
                    for(int i = 0; i < 26; i++) if(v1[i] != v2[i]){ok = false; break;}
                    if(ok) return true;
                }
                r++;
            }else
            {
                if(v1[s2[r] - 'a'] == 0)
                {
                    r++;
                    l = r;
                    for(int i = 0; i < 26; i++) v2[i] = 0;
                }else
                {
                    while(l < r && v1[s2[r] - 'a'] == v2[s2[r] - 'a'])
                    {
                        v2[s2[l] - 'a']--;
                        l++;
                    }
                    v2[s2[r] - 'a']++;
                    r++;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    int maximumLength(string s) {
        int Max = -1;
        map<char, vector<int>> mp;
        int tmp = 1;
            for(int j = 1; j < s.size(); j++)
            {
                if(s[j] == s[j - 1]) tmp++;
                else
                {
                    mp[s[j - 1]].push_back(tmp);
                    tmp = 1;
                }
            }
            mp[s.back()].push_back(tmp);
            for(auto ans: mp)
            {
                sort(ans.second.begin(), ans.second.end());
                if(ans.second.size() != 0)
                {
                    if(ans.second.back() != 1)
                    {
                        for(int l = ans.second.back(); l >= ans.second.back() - 1; l--)
                        {
                            int res = 0;
                            for(int j = 0; j < ans.second.size(); j++)
                            {
                                if(ans.second[j] >= l) res+= ans.second[j] - l + 1;
                            }
                            if(res >= 3) Max = max(Max, l);
                        }
                        if(ans.second.back() >= 3) Max = max(ans.second.back() - 2, Max);
                    }else
                    {
                        if(ans.second.size() >= 3) Max = max(Max, 1);
                    }
                }
            }
            
        return Max;
    }
};
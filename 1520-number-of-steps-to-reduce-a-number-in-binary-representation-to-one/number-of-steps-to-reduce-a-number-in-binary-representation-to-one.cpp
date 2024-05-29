class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        reverse(s.begin(), s.end());
        while(1)
        {
            if(s.size() == 1) return ans;
            if(s[0] == '1')
            {
                int tmp = 1;
                s[0] = '0';
                for(int i = 1; i < s.size(); i++)
                {
                    if(s[i] == '1') s[i] = '0';
                    else
                    {
                        s[i] = '1';
                        tmp = 0;
                        break;
                    }
                }
                if(tmp) s.push_back('1');
            }else
            {
                for(int i = 0; i < s.size() - 1; i++)
                {
                    if(s[i] == '0' && s[i + 1] == '1')
                    {
                        s[i] = '1';
                        s[i + 1] = '0';
                    }
                }
                s.pop_back();
            }
            ans++;
        }
        return ans;
    }
};
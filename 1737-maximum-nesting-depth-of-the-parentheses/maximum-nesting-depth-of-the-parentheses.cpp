class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, cnt = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                cnt++;
                ans = max(ans, cnt);
            }else if(s[i] == ')')
            {
                cnt--;
            }
        }
        return ans;
    }
};
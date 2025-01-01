class Solution {
public:
    int maxScore(string s) {
        int one = 0;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '1') one++;
        int ans = 0, tmp1 = 0, tmp0 = 0;
        if(s[0] == '1') tmp1++;
        else tmp0++;
        ans = tmp0 + one - tmp1;
        for(int i = 1; i < s.size() - 1; i++)
        {
            if(s[i] == '0') tmp0++;
            else tmp1++;
            ans = max(tmp0 + one - tmp1, ans);
        }
        return ans;
    }
};
class Solution {
public:
    int lengthOfLastWord(string s) {
        int Max = 0, cnt = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] != ' ')
            {
                cnt++;
                Max = max(Max, cnt);
            }else
            {
                if(Max) break;
                else cnt = 0;
            }
        }
        return Max;
    }
};
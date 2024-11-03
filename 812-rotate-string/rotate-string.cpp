class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            int l = i;
            bool ok = true;
            for(int j = 0; j < n; j++)
            {
                if(goal[j] != s[l])
                {
                    ok = false;
                    break;
                }
                l = (l + 1)%n;
            }
            if(ok) return true;
        }
        return false;
    }
};
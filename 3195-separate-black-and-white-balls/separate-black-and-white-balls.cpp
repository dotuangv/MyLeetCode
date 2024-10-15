class Solution {
public:
    long long minimumSteps(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        long long ans = 0, cnt = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '1') cnt++;
            else ans += cnt;
        }
        return ans;
    }
};
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size());
        stack<int> st;
        int ans = 0;
        if(s[0] == '(') st.push(0);
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == '(')
                st.push(i);
            else
            {
                if(st.empty())
                    dp[i] = 0;
                else
                {
                    int j = st.top();
                    st.pop();
                    if(j != i - 1)
                    {
                        dp[i] = dp[i - 1] + 1;
                        if(j != 0) dp[i] += dp[j - 1];
                    }
                    else
                    {
                        if(j == 0) dp[i] = 1;
                        else dp[i] = dp[j - 1] + 1;
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans * 2;

    }
};
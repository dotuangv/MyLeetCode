class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        stack<char> st;
        for(int i = 0; i < s.size(); i++)
        {
            if(!st.empty())
            {
                if(st.top() + 32 == s[i] || st.top() == s[i] + 32)
                {
                    st.pop();
                }else
                {
                    st.push(s[i]);
                }
            }else st.push(s[i]);
        }
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
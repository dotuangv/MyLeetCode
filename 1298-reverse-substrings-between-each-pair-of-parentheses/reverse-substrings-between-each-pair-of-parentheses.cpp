class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string str;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ')') st.push(s[i]);
            else
            {
                str = "";
                while(st.top() != '(')
                {
                    str.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(int i = 0; i < str.size(); i++) st.push(str[i]);
            }
        }
        str = "";
        while(!st.empty())
        {
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
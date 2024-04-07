class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st, star;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else if(s[i] == ')')
            {
                if(st.empty())
                {
                    if(!star.empty()) star.pop();
                    else return false;
                }else
                {
                    st.pop();
                }
            }else star.push(i);
        }
        cout << st.size() << " " << star.size() << "\n";
        while(!st.empty() && !star.empty())
        {
            if(star.top() < st.top()) return false;
            else
            {
                st.pop();
                star.pop();
            }
        }
        return st.empty();
    }
};
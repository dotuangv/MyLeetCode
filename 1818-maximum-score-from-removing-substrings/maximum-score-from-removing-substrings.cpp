class Solution {
public:

    int Solve(string &s, stack<char> &st, int x, int y, bool opt)
    {
        int i = 0, ans = 0;
        while(i < s.size())
        {
            st.push(s[i]);
            i++;
            if(y >= x) // xóa ba
            {
                while(!st.empty() && st.top() == 'b')
                {
                    st.pop();
                    if(i < s.size() && s[i] == 'a')
                    {
                        if(opt) ans += y;
                        else ans += x;
                        i++;
                    }else
                    {
                        st.push('b');
                        break;
                    }
                }
            }else // xóa ab
            {
                while(!st.empty() && st.top() == 'a')
                {
                    st.pop();
                    if(i < s.size() && s[i] == 'b')
                    {
                        if(opt) ans += x;
                        else ans += y;
                        i++;
                    }else
                    {
                        st.push('a');
                        break;
                    }
                }
            }
        }
        return ans;
    }

    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ans = Solve(s, st, x, y, true);
        string str ="";
        while(!st.empty())
        {
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(), str.end());
        // cout << str << "\n";
        ans += Solve(str, st, y, x, false);
        return ans;
        
    }
    
};
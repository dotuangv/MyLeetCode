class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            st.push(s[i]);
            if(st.top() == part.back()){
                int j = part.size() - 1;
                while(!st.empty() && j >= 0 && st.top() == part[j]){
                    st.pop();
                    j--;
                }
                if(j != -1){
                    for(int l = j + 1; l < part.size(); l++) st.push(part[l]);
                }
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
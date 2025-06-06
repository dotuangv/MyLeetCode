class Solution {
public:
    string robotWithString(string s) {
        vector<int> ind(26), cnt(26);
        for(int i = 0; i < s.size(); i++) {
            ind[s[i] - 'a'] = i;
            cnt[s[i] - 'a']++;
        }
        int j = 0;
        while(j < 26 && cnt[j] == 0) j++;
        stack<char> st;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            while(j < 26 && (ind[j] < i || cnt[j] == 0)) j++; 
            while(!st.empty() && st.top() - 'a' <= j) {
                ans.push_back(st.top());
                cnt[st.top() - 'a']--;
                st.pop();
                while(j < 26 && (ind[j] < i || cnt[j] == 0)) j++; 
            }
            if(s[i] - 'a' == j){
                ans.push_back(j + 'a');
                cnt[j]--;
            }else st.push(s[i]);
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
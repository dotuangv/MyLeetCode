class Solution {
public:
    string clearDigits(string s) {
        stack<int> c;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                c.pop();
            }else c.push(i);
        }
        string ans;
        while(!c.empty()){
            ans.push_back(s[c.top()]);
            c.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
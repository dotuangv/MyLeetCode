class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string t = countAndSay(n - 1);
        string ans = "";
        int i = 1, res = 1;
        while(i < t.size())
        {
            if(t[i] == t[i - 1]) res++;
            else
            {
                string x = to_string(res);
                for(int j = 0; j < x.size(); j++) ans.push_back(x[j]);
                ans.push_back(t[i - 1]);
                res = 1;
            }
            i++;
        }
        string x = to_string(res);
        for(int j = 0; j < x.size(); j++) ans.push_back(x[j]);
        ans.push_back(t[i - 1]);
        return ans;
    }
};
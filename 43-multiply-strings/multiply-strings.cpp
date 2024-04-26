class Solution {
public:
    string multiply(string num1, string num2) {
        string ans = "";
        for(int i = 0; i < num1.size() + num2.size(); i++) ans += '0';
        int tmp = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i = 0; i < num1.size(); i++)
        {
            int a = num1[i] - 48;
            for(int j = 0; j < num2.size(); j++)
            {
                int b = num2[j] - 48;
                int c = ans[i + j] - 48;
                int s = a*b + c + tmp;
                ans[i + j] = char(s % 10 + 48);
                tmp = s / 10; 
            }
            if(tmp)
            {
                ans[num2.size() + i] = char(tmp + 48);
                tmp = 0;
            }
        }
        while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    string numberToWords(int num) {
        unordered_map<char, string> mp1, mp2, mp3;
            // Số có một chữ số từ 1 đến 9
    mp1['1'] = "One ";
    mp1['2'] = "Two ";
    mp1['3'] = "Three ";
    mp1['4'] = "Four ";
    mp1['5'] = "Five ";
    mp1['6'] = "Six ";
    mp1['7'] = "Seven ";
    mp1['8'] = "Eight ";
    mp1['9'] = "Nine ";

    // Số có hai chữ số từ 10 đến 19
    mp2['0'] = "Ten ";
    mp2['1'] = "Eleven ";
    mp2['2'] = "Twelve ";
    mp2['3'] = "Thirteen ";
    mp2['4'] = "Fourteen ";
    mp2['5'] = "Fifteen ";
    mp2['6'] = "Sixteen ";
    mp2['7'] = "Seventeen ";
    mp2['8'] = "Eighteen ";
    mp2['9'] = "Nineteen ";

        // Số chẵn chục từ 20 đến 90
    mp3['2'] = "Twenty ";
    mp3['3'] = "Thirty ";
    mp3['4'] = "Forty ";
    mp3['5'] = "Fifty ";
    mp3['6'] = "Sixty ";
    mp3['7'] = "Seventy ";
    mp3['8'] = "Eighty ";
    mp3['9'] = "Ninety ";
        string s = "";
        while(num)
        {
            s.push_back(char(num%10 + 48));
            num/=10;
        }
        if(s.empty()) return "Zero";
        vector<string> v(4);
        v[0] = "Hundred ";
        v[1] = "Thousand ";
        v[2] = "Million ";
        v[3] = "Billion ";
        int j = (s.size() - 1)/3, cnt = (s.size()%3 - 1 + 3)%3;
        bool ok = false, ok2 = false;
        string ans = "";
        // cout << s << "  " << cnt << "\n";
        for(int i = s.size() - 1; i >= 0; i--)
        {
            cnt %= 3;
            cout << cnt << " ";
            if(cnt != 0)
            {
                if(s[i] != '0')
                {
                    ok = true;
                    if(cnt == 2)
                    {
                        ans += (mp1[s[i]]);
                        ans += v[0];
                    }else
                    {
                        if(s[i] == '1')
                        {
                            ans += (mp2[s[i - 1]]);
                            ok2 = true;
                        }else
                        {
                            ans += (mp3[s[i]]);
                            ok2 = false;
                        }
                    }
                }else
                {
                    ok2 = false;
                }
            }else
            {
                if(s[i] != '0')
                {
                    ok = true;
                    if(!ok2) ans += (mp1[s[i]]);
                    ok2 = false;
                }
                if(ok && j >= 1)
                {
                    ans += (v[j]);
                }
                ok = false;
                j--;
            }
            cnt = (cnt + 3 - 1);
        }
        ans.pop_back();
        return ans;
    }
};
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        char d = '!';
        while(1){
            if(a >= b && a >= c)
            {
                if(d != 'a' && a > 0)
                {
                    for(int i = 0; i < min(2, a); i++) ans.push_back('a');
                    a -= min(2, a);
                    d = 'a';
                }else
                {
                    if(b >= c && d != 'b' && b > 0) 
                    {
                        ans.push_back('b');
                        d = 'b';
                        b --;
                    }else if(d != 'c' && c > 0)
                    {
                        ans.push_back('c');
                        d = 'c';
                        c --;
                    }else break;
                }
            }else if(b >= a && b >= c)
            {
                if(d != 'b' && b > 0)
                {
                    for(int i = 0; i < min(2, b); i++) ans.push_back('b');
                    b -= min(2, b);
                    d = 'b';
                }else
                {
                    if(a >= c && d != 'a' && a > 0) 
                    {
                        ans.push_back('a');
                        d = 'a';
                        a --;
                    }else if(d != 'c' && c > 0)
                    {
                        ans.push_back('c');
                        d = 'c';
                        c --;
                    }else break;
                }
            }else if(c >= b && c >= a)
            {
                if(d != 'c' && c > 0)
                {
                    for(int i = 0; i < min(2, c); i++) ans.push_back('c');
                    c -= min(2, c);
                    d = 'c';
                }else
                {
                    if(b >= a && d != 'b' && b > 0) 
                    {
                        ans.push_back('b');
                        d = 'b';
                        b --;
                    }else if(d != 'a' && a > 0)
                    {
                        ans.push_back('a');
                        d = 'a';
                        a --;
                    }else break;
                }
            }
        }
        return ans;
    }
};
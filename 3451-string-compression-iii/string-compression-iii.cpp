class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int res = 0;
        for(int i = 0; i < word.size() - 1; i++)
        {
            if(word[i] == word[i + 1])
            {
                res++;
            }else
            {
                res++;
                while(res > 9)
                {
                    comp.push_back('9');
                    comp.push_back(word[i]);
                    res -= 9;
                }
                comp.push_back(char(res + 48));
                comp.push_back(word[i]);
                res = 0;
            }
        }
        if(res)
        {
            res++;
            while(res > 9)
            {
                comp.push_back('9');
                comp.push_back(word.back());
                res -= 9;
            }
            comp.push_back(char(res + 48));
            comp.push_back(word.back());
        }else
        {
            comp.push_back('1');
            comp.push_back(word.back());
        }
        return comp;
    }
};
class Solution {
public:
    string removeKdigits(string num, int k) {
        string s="";
        for(char c:num){
            while(s.size() && s.back()>c && k)
            {
                k--;
                s.pop_back();
            }
            if(s.size()||c!='0') s.push_back(c);
        }
        while(s.size() && k--)
            s.pop_back();
        return (s.size()==0)?"0":s;
    }
};
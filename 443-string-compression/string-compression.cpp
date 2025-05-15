class Solution {
public:
    int cal(int &sum, vector<char> &chars, char c, int i){
        if(sum == 1) {
            chars[i] = c;
            return 1;
        };
        vector<char> cs;
        while(sum){
            cs.push_back(sum % 10 + '0');
            sum /= 10;
        }
        chars[i] = c;
        int j = 1;
        while(j <= cs.size()){
            chars[i + j] = cs[cs.size() - j];
            j++;
        }
        sum = 1;
        return cs.size() + 1;
    }
    int compress(vector<char>& chars) {
        int ans = 0, sum = 1;
        for(int i = 1; i < chars.size(); i++){
            if(chars[i] != chars[i - 1]){
                ans += cal(sum, chars, chars[i - 1], ans);
            }else sum++;
        }
        ans += cal(sum, chars, chars.back(), ans);
        return ans;
    }
};
class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2){
        if(str1.size() > str2.size()) return false;
        int res = 0, j = 0;
        for(int i = 0; i < str1.size(); i++){
            if(str1[i] == str2[j]) j++;
            else break;
        }
        if(j == str1.size()) res++;
        j = str2.size() - 1;
        for(int i = str1.size() - 1; i >= 0; i--){
            if(str1[i] == str2[j]) j--;
            else break;
        }
        if(str2.size() - j - 1 == str1.size()) res++;
        return res == 2; 
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            for(int j = i + 1; j < words.size(); j++){
                if(isPrefixAndSuffix(words[i], words[j])) ans++;
            }
        }
        return ans;
    }
};
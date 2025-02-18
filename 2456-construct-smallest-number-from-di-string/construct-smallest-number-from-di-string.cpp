class Solution {
public:
    string ans;
    void backtrack(int i, int n, string pattern, bool increasing, vector<bool> &check){
        if(i == n) return;
        for(char j = '1'; j <= '9'; j++){
            if(check[j - '1']) continue;
            if(i == 0){
                ans.push_back(j);
                check[j - '1'] = true;
                backtrack(i + 1, n, pattern, pattern[i] == 'I', check);
                if(ans.size() == n) return;
                check[j - '1'] = false;
                ans.pop_back();
            }else{
                if(increasing && j > ans[i - 1]){
                    ans.push_back(j);
                    check[j - '1'] = true;
                    backtrack(i + 1, n, pattern, pattern[i] == 'I', check);
                    if(ans.size() == n) return;
                    check[j - '1'] = false;
                    ans.pop_back();
                }
                if(!increasing && j < ans[i - 1]){
                    ans.push_back(j);
                    check[j - '1'] = true;
                    backtrack(i + 1, n, pattern, pattern[i] == 'I', check);
                    if(ans.size() == n) return;
                    check[j - '1'] = false;
                    ans.pop_back();
                }
            }
        }
    }
    string smallestNumber(string pattern) {
        vector<bool> check(9);
        backtrack(0, pattern.size() + 1, pattern, false, check);
        return ans;
    }
};
class Solution {
public:
    string ans;
    void backtrack(int i, int n, int k, int &res){
        if(i == n){
            res++;
            return;
        }
        for(char c = 'a'; c <= 'c'; c++){
            if(ans.empty() || c != ans.back()){
                ans.push_back(c);
                backtrack(i + 1, n, k, res);
                if(res == k) return;
                ans.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        int res = 0;
        backtrack(0, n, k, res);
        return ans;
    }
};
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<bool> check(10001);
        vector<int> vt;
        for(auto x: banned) check[x] = true;
        int res = 0, sum = 0;
        for(int i = 1; i <= n; i++){
            if(!check[i] && sum + i <= maxSum){
                res++;
                sum += i;
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> minOperations(string s) {
        int n = s.size();
        vector<int> dp1(n + 2), dp2(n + 2), pre(n + 1), ans(n);
        vector<int> ;
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i - 1] + s[i - 1] - '0';
            dp1[i] = dp1[i - 1] + pre[i - 1];
        }

        for(int i = n; i >= 1; i--){
            dp2[i] = dp2[i + 1] + pre[n] - pre[i];
        }

        for(int i = 1; i <= n; i++){
            ans[i - 1] = dp1[i] + dp2[i];
        }

        return ans;
    }
};
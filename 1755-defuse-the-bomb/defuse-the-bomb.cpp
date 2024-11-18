class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> pre(n + 1);
        for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + code[i - 1];
        if(k == 0){
            for(int i = 0; i < n; i++) code[i] = 0;
        }else if(k > 0)
        {
            for(int i = 0; i < n; i++){
                if(i + k + 1 <= n){
                    code[i] = pre[i + k + 1] - pre[i + 1];
                }else
                {
                    code[i] = pre[n] - pre[i + 1] + pre[((i + k + 1)%n)];
                }
            }
        }else{
            for(int i = 0; i < n; i++){
                if(i + k >= 0){
                    code[i] = pre[i] - pre[i + k];
                }else{
                    code[i] = pre[i] + pre[n] - pre[n - abs(i + k)];
                }
            }
        }
        return code;
    }
};
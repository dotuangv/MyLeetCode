class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(right + 1);
        for(long long i = 2; i <= right; i++){
            if(!prime[i]){
                for(long long j = i * i; j <= right; j += i) prime[j] = true;
            }
        }
        vector<int> vt, ans;
        for(int i = 2; i <= right; i++) if(!prime[i]) vt.push_back(i);
        int n = vt.size();
        for(int i = 0; i < n - 1; i++){
            if(vt[i] >= left && vt[i + 1] <= right){
                if(ans.empty()){
                    ans.push_back(vt[i]);
                    ans.push_back(vt[i + 1]);
                }else if(vt[i + 1] - vt[i] < ans.back() - ans[0]){
                    ans[0] = vt[i];
                    ans[1] = vt[i + 1];
                }
            }
        }
        if(ans.empty()) return {-1, -1};
        return ans;
    }
};
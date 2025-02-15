class Solution {
public:
    int S(int k, int i, vector<int> &vt){
        int sum = 0, res = 1;
        for(int j = k; j < k + i; j++){
            sum += vt[j] * res;
            res *= 10;
        }
        return sum;
    }
    bool backtrack(int k, int x, vector<int> &vt, int sum){
        if(k == vt.size()){
            return sum == x;
        }
        bool ans = false;
        for(int i = 1; i <= vt.size() - k; i++){
            ans |= backtrack(k + i, x, vt, sum + S(k, i, vt));
        }
        return ans;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int x = i * i;
            vector<int> vt;
            while(x){
                vt.push_back(x % 10);
                x /= 10;
            }
            if(backtrack(0, i, vt, 0)) ans += i * i;
        }
        return ans;
    }
};
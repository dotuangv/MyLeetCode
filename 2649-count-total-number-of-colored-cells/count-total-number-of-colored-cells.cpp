class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 0, res = 1;
        for(int i = 1; i < n; i++){
            ans += res * 2;
            res += 2;
        }
        return ans + res;
    }
};
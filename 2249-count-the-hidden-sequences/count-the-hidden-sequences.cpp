class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        vector<long long> Lower(n + 1), Upper(n + 1);
        Lower[0] = lower; Upper[0] = upper;
        for(int i = 1; i <= n; i++){
            Lower[i] = max((long long)lower, Lower[i - 1] + differences[i - 1]);
            Upper[i] = min((long long)upper, Upper[i - 1] + differences[i - 1]);
        }
        return max(0LL, Upper[n] - Lower[n] + 1);
    }
};
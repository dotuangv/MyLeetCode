class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long long Lower = lower, Upper = upper;
        for(int i = 1; i <= n; i++){
            Lower = max((long long)lower, Lower + differences[i - 1]);
            Upper = min((long long)upper, Upper + differences[i - 1]);
        }
        return max(0LL, Upper - Lower + 1);
    }
};
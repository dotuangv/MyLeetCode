class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = n * (n + 1)/2;
        if(m > n) return sum;
        int num2 = (m + n/m * m) * (n/m) / 2;
        return sum - 2 * num2;
    }
};
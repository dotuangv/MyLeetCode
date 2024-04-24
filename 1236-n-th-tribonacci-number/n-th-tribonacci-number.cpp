class Solution {
public:
    int tribonacci(int n) {
        if(n <= 2) return n!=0;
        int x0 = 0, x1 = 1, x2 = 1;
        for(int i = 3; i <= n; i++)
        {
            int tmp = x2;
            x2 = x0 + x1 + x2;
            x0 = x1;
            x1 = tmp;
        }
        return x2;
    }
};
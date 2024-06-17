class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i = 0;
        while(i * i <= c)
        {
            int t = sqrt(c - i*i);
            if(t*t == (c - i*i)) return true;
            i++;
        }
        return false;
    }
};
class Solution {
public:
    int arrangeCoins(int n) {
        long long l = 1, r = n;
        while(r > l + 1)
        {
            long long mid = (l + r)/2;
            long long res = mid*(mid + 1)/2;
            if(res == n) return mid;
            else if(res > n) r = mid;
            else l = mid;
        }
        return l;
    }
};
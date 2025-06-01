class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for(int i = 0; i <= min(n, limit); i++){
            if(n - i <= limit) ans += (n - i + 1);
            else if(n - i <= 2 * limit){
                ans += 2 * limit - n + i + 1;
            }
        }
        return ans;
    }
};
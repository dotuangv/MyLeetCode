class Solution {
public:
    bool canDivide(int x, long long k, vector<int> &candies){
        long long res = 0;
        for(auto &c: candies){
            res += c/x;
        }
        return res >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1, r = 1e7;
        while(r > l + 1){
            int mid = (l + r)/2;
            if(canDivide(mid, k, candies)) l = mid;
            else r = mid;
        }
        if(canDivide(r, k, candies)) return r;
        else if(canDivide(l, k, candies)) return l;
        return 0; 
    }
};
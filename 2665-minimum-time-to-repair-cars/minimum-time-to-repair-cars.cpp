class Solution {
public:
    bool isGood(long long mid, vector<int> &ranks, int cars){
        long long cnt = 0;
        for(int i = 0; i < ranks.size(); i++){
            cnt += sqrt(mid/ranks[i]);
        }
        return cnt >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0, r = 1e18;
        while(r > l + 1){
            long long mid = (l + r)/2;
            if(isGood(mid, ranks, cars)) r = mid;
            else l = mid;
        }
        return r;
    }
};
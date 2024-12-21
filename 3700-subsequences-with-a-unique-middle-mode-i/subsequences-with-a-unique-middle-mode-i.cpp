class Solution {
public:
    long long mod = 1e9 + 7;
    long long mul(long long x, long long y){
        return ((x % mod) * (y % mod))%mod;
    }
    long long C2(long long n){
        return (n * (n - 1)/2) % mod;
    }
    void update(int &ans, int x){
        ans = (ans%mod + x%mod + mod) % mod;
    }

    int subsequencesWithMiddleMode(vector<int>& nums) {
        int ans = 0;
        vector<pair<int, int>> vt;
        for(int i = 0; i < nums.size(); i++){
            vt.push_back({nums[i], i});
        }
        sort(vt.begin(), vt.end());
        int k = 1;
        nums[vt[0].second] = 0;
        for(int i = 1; i < vt.size(); i++){
            if(vt[i].first == vt[i - 1].first) nums[vt[i].second] = nums[vt[i - 1].second];
            else nums[vt[i].second] = k++;
        }
        for(int i = 2; i < nums.size() - 2; i++){
            vector<int> mp1(k), mp2(k);
            long long n = 0, m = 0;
            for(int j = i - 1; j >= 0; j--) {
                mp1[nums[j]]++;
                n++;
            }
            for(int j = i + 1; j < nums.size(); j++) {
                mp2[nums[j]]++;
                m++;
            }
            long long l0 = C2(n - mp1[nums[i]]), l1 = mul(mp1[nums[i]], n - mp1[nums[i]]), l2 = C2(mp1[nums[i]]);
            long long r0 = C2(m - mp2[nums[i]]), r1 = mul(mp2[nums[i]], m - mp2[nums[i]]), r2 = C2(mp2[nums[i]]);
            // mode mid = 2
            // 1 1 0
            update(ans, mul(l1, r0));
            for(int x = 0; x < k; x++){
                if(x != nums[i]){
                    update(ans, -mul(mul(n - mp1[x] - mp1[nums[i]], mp1[nums[i]]), C2(mp2[x])));
                    update(ans, - mul(mul(mp1[x], mp1[nums[i]]), mul(mp2[x], m - mp2[x] - mp2[nums[i]])) - mul(mul(mp1[x], mp1[nums[i]]), C2(mp2[x])));
                }
            }
            // 0 1 1
            update(ans, mul(l0, r1));
            for(int x = 0; x < k; x++){
                if(x != nums[i]){
                    update(ans, - mul(mul(m - mp2[x] - mp2[nums[i]], mp2[nums[i]]), C2(mp1[x])));
                    update(ans, - mul(mul(mp2[x], mp2[nums[i]]), mul(mp1[x], n - mp1[x] - mp1[nums[i]])) - mul(mul(mp2[x], mp2[nums[i]]), C2(mp1[x])));
                }
            }
            // mode mid = 3
            // 2 1 0
            update(ans, mul(l2, r0));
            // 0 1 2
            update(ans, mul(l0, r2));
            // 1 1 1
            update(ans, mul(l1, r1));
            // mode mid = 4
            // 2 1 1
            update(ans, mul(l2, r1));
            // 1 1 2
            update(ans, mul(l1, r2));
            // mode mid = 5
            // 2 1 2
            update(ans, mul(l2, r2));
        }
        return ans;
    }
};
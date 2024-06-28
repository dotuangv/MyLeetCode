class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> v(n) ;
        for(auto &x: roads)
        {
            v[x[0]]++;
            v[x[1]]++;
        }
        sort(v.begin(), v.end(), greater<long long>());
        long long ans = 0;
        for(auto &x: v)
        {
            ans += n*x;
            n--;
        }
        return ans;

    }
};
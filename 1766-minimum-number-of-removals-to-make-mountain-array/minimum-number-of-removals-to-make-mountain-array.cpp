class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        int n = a.size();
        vector<int> dp1(n, 1), dp2(n, 1);
        for(int i = 1; i < n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(a[i] > a[j]) dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
        for(int i = n - 2; i >= 0; i--)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(a[i] > a[j]) dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
        int ans = n;
        for(int i = 1; i < n - 1; i++)
        {
            int res = dp1[i] + dp2[i] - 1;
            // cout << i << " " << dp1[i] << " " << dp2[i] << "\n";
            if(dp1[i] == 1 || dp2[i] == 1) continue;
            ans = min(ans, n - res);
        }
        return ans;
    }
};
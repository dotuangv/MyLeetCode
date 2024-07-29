class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> dp1(n), dp2(n);
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(rating[j] > rating[i]) dp1[i]++;
                else if(rating[j] < rating[i]) dp2[i]++;
            }
        }
        // for(auto &x: dp1) cout << x << " ";
        // cout << "\n";
        // for(auto &x: dp2) cout << x << " ";
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n - 1; j++)
            {
                if(rating[i] < rating[j]) ans += dp1[j];
                else if(rating[i] > rating[j]) ans += dp2[j];
            }
        }
        return ans;

    }
};
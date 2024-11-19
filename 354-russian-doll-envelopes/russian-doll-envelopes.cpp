class Solution {
public:

    int upper(int x, vector<int> &dp){
        int l = 0, r = dp.size() - 1;
        while(r > l + 1){
            int mid = (l + r)/2;
            if(dp[mid] >= x) r = mid;
            else l = mid;
        }
        if(dp[l] >= x) return l;
        return r;
    }

    int maxEnvelopes(vector<vector<int>>& ev) {
        sort(ev.begin(), ev.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        vector<int> dp;
        dp.push_back(ev[0][1]);
        for(int i = 1; i < ev.size(); i++){
            if(ev[i][1] > dp.back()){
                dp.push_back(ev[i][1]);
            }else
            {
                int j = upper(ev[i][1], dp);
                dp[j] = ev[i][1];
            }
        }
        return dp.size();
    }
};
class Solution {
public:

    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size() * grid[0].size();
        vector<int> pre(n), suf(n), vt, mp(10001);
        for(auto &x: grid){
            for(auto &y: x) mp[y]++;
        }
        for(int i = 1; i <= 10000; i++){
            while(mp[i]){
                vt.push_back(i);
                mp[i]--;
            }
        }
        for(int i = 1; i < n; i++){
            if((vt[i] - vt[i - 1])%x) return -1;
            pre[i] = pre[i - 1] + (vt[i] - vt[i - 1])/x * i;
        }
        for(int i = n - 2; i >= 0; i--){
            suf[i] = suf[i + 1] + (vt[i + 1] - vt[i])/x * (n - i - 1);
        }

        int ans = 1e9;
        for(int i = 0; i < n; i++){
            ans = min(ans, pre[i] + suf[i]);
        }
        return ans;

    }
};
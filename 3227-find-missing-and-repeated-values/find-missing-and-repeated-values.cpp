class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> mp(n*n + 1), ans(2);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mp[grid[i][j]]++;
            }
        }
        for(int i = 1; i <= n*n; i++){
            if(mp[i] == 2) ans[0] = i;
            else if(mp[i] == 0) ans[1] = i;
        }
        return ans;
    }
};
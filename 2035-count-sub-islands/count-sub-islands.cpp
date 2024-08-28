class Solution {
public:
    int n, m;
    void solve(int i, int j, vector<vector<int>> &grid1, vector<vector<int>>&grid2, bool &check)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0) return;
        if(grid1[i][j] == 0) check = false;
        grid2[i][j] = 0;
        solve(i, j + 1, grid1, grid2, check);
        solve(i, j - 1, grid1, grid2, check);
        solve(i + 1, j, grid1, grid2, check);
        solve(i - 1, j, grid1, grid2, check);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        m = grid1.size();
        n = grid1[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid2[i][j] == 1)
                {
                    bool check = true;
                    solve(i, j, grid1, grid2, check);
                    if(check) ans++;
                }
            }
        }
        return ans;
    }
};
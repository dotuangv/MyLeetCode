class Solution {
public:

    int ans = 0;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    void backtrack(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visit, int sum)
    {
        visit[i][j] = true;
        ans = max(ans, sum);
        for(int l = 0; l < 4; l++)
        {
            int ii = i + dx[l];
            int jj = j + dy[l];
            if(ii >= 0 && ii < grid.size() && jj >= 0 && jj < grid[i].size() &&
             !visit[ii][jj] && grid[ii][jj])
            {
                backtrack(ii, jj, grid, visit, sum + grid[ii][jj]);
            }
        }
        visit[i][j] = false;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<bool>> visit(grid.size(), vector<bool> (grid[0].size()));
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j]) backtrack(i, j, grid, visit, grid[i][j]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<bool>> visit;
    int x[4] = {-1, 0, 0, 1};
    int y[4] = {0, -1, 1, 0};
    void solve(int i, int j, vector<vector<char>> &grid)
    {
        visit[i][j] = true;
        for(int l = 0; l < 4; l++)
        {
            int ii = i + x[l];
            int jj = j + y[l];
            if(ii >= 0 && ii < grid.size() && jj >= 0 && jj < grid[i].size() && grid[ii][jj] == '1' && !visit[ii][jj])
            {
                solve(ii, jj, grid);
            }
        }  
    }
    int numIslands(vector<vector<char>>& grid) {
        visit.resize(grid.size(), vector<bool> (grid[0].size(), false));
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(!visit[i][j] && grid[i][j] == '1')
                {
                    ans++;
                    solve(i, j, grid);
                }
            }
        }
        return ans;
    }
};
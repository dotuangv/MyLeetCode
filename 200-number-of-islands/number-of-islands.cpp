auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();
class Solution {
public:
    int x[4] = {-1, 0, 0, 1};
    int y[4] = {0, -1, 1, 0};
    void solve(int i, int j, vector<vector<char>> &grid)
    {
        grid[i][j] = '0';
        for(int l = 0; l < 4; l++)
        {
            int ii = i + x[l];
            int jj = j + y[l];
            if(ii >= 0 && ii < grid.size() && jj >= 0 && jj < grid[i].size() && grid[ii][jj] == '1')
            {
                solve(ii, jj, grid);
            }
        }  
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    solve(i, j, grid);
                }
            }
        }
        return ans;
    }
};
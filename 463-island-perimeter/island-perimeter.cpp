class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    if(i != 0) ans += !grid[i - 1][j];
                    else ans++;
                    if(i != grid.size() - 1) ans += !grid[i + 1][j];
                    else ans++;
                    if(j != 0) ans += !grid[i][j - 1];
                    else ans++;
                    if(j != grid[i].size() - 1) ans += !grid[i][j + 1];
                    else ans++;
                }
            }
        }
        return ans;
    }
};
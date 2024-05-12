class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size() - 2, vector<int> (grid[0].size() - 2));
        for(int i = 0; i < grid.size() - 2; i++)
        {
            for(int j = 0; j < grid[i].size() - 2; j++)
            {
                for(int l = i; l < i + 3; l++)
                {
                    for(int k = j; k < j + 3; k++)
                    {
                        ans[i][j] = max(ans[i][j], grid[l][k]);
                    }
                }
            }
        }
        return ans;
    }
};
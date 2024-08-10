class Solution {
public:
    void floodfill(int i, int j, vector<vector<int>> &expandgrid)
    {
        if(i < 0 || i >= expandgrid.size() || j < 0 || j>= expandgrid.size() || expandgrid[i][j] == 1) return;
        expandgrid[i][j] = 1;
        floodfill(i, j + 1, expandgrid);
        floodfill(i, j - 1, expandgrid);
        floodfill(i + 1, j, expandgrid);
        floodfill(i - 1, j, expandgrid);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> expandgrid(3*n, vector<int> (3*n));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < grid.size(); j++)
            {
                if(grid[i][j] == '/')
                {
                    expandgrid[3*i][3*j + 2] = 1;
                    expandgrid[3*i + 1][3*j + 1] = 1;
                    expandgrid[3*i + 2][3*j] = 1;
                }else if(grid[i][j] == '\\')
                {
                    expandgrid[3*i][3*j] = 1;
                    expandgrid[3*i + 1][3*j + 1] = 1;
                    expandgrid[3*i + 2][3*j + 2] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < expandgrid.size(); i++)
        {
            for(int j = 0; j < expandgrid.size(); j++)
            {
                if(expandgrid[i][j] == 0)
                {
                    ans++;
                    floodfill(i, j, expandgrid);
                }
            }
        }
        return ans;

    }
};
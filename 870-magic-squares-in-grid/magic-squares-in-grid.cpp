class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> cc(n + 2, vector<int> (m + 2)), cp(n + 2, vector<int> (m + 2)), row(n + 2, vector<int> (m + 2)), col(n + 2, vector<int> (m + 2));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                row[i][j] = grid[i - 1][j - 1] + row[i][j - 1];
                col[i][j] = grid[i - 1][j - 1] + col[i - 1][j];
                cc[i][j] = grid[i - 1][j - 1] + cc[i - 1][j - 1];
                cp[i][j] = grid[i - 1][j - 1] + cp[i - 1][j + 1];
            }
        } 
        int result = 0;
        for(int i = 1; i <= n - 2; i++)
        {
            for(int j = 1; j <= m - 2; j++)
            {
                int r = row[i][j + 2] - row[i][j - 1];
                int c = col[i + 2][j] - col[i - 1][j];
                int x = cc[i + 2][j + 2] - cc[i - 1][j - 1];
                int y = cp[i + 2][j] - cp[i - 1][j + 3];
                unordered_map<int, bool> mp;
                bool check = true;
                for(int l = i; l <= i + 2; l++)
                {
                    for(int k = j; k <= j + 2; k++)
                    {
                        if(!mp[grid[l - 1][k - 1]] && grid[l - 1][k - 1] >= 1 && grid[l - 1][k - 1] <= 9) mp[grid[l - 1][k - 1]] = true;
                        else check = false;
                    }
                }
                if(r == c && c == x && x == y && check) result++;
            }
        }
        return result;
    }
};
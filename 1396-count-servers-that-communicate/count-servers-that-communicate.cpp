class Solution {
public:
    int dfs(int r, int c, vector<vector<int>> &row, vector<vector<int>> &col, vector<vector<bool>> &check){
        int ans = 1;
        check[r][c] = true;
        for(auto &x: row[r]){
            if(!check[r][x]){
                ans += dfs(r, x, row, col, check);
            }
        }
        for(auto &x: col[c]){
            if(!check[x][c]){
                ans += dfs(x, c, row, col, check);
            }
        }
        return ans;
    }
    int countServers(vector<vector<int>>& grid) {
        vector<vector<int>> row(grid.size()), col(grid[0].size());
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]) {
                    row[i].push_back(j);
                    col[j].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<vector<bool>> check(grid.size(), vector<bool> (grid[0].size()));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] && !check[i][j]){
                    int res = dfs(i, j, row, col, check);
                    if(res != 1) ans += res;
                }
            }
        }
        return ans;
    }
};
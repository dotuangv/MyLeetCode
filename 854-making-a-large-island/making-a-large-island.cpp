class Solution {
public:
    int parent[250001], sz[250001];
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1; // Ban đầu tập hợp chứa v có kích cỡ là 1
    }

    int find_set(int v) {
        return v == parent[v] ? v : parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b); // Đặt biến a là gốc của cây có kích cỡ lớn hơn
            parent[b] = a;
            sz[a] += sz[b]; // Cập nhật kích cỡ của cây mới gộp lại
        }
    }
    bool check(int i, int j, int n){
        if(i < 0 || i >= n || j < 0 || j >= n) return false;
        return true;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]) make_set(n * i + j);
            }
        }
        int ans = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    for(int k = 0; k < 4; k++){
                        int ii = i + dx[k], jj = j + dy[k];
                        if(check(ii, jj, n) && grid[ii][jj]) 
                            union_sets(i * n + j, ii * n + jj);
                    }
                    ans = max(ans, sz[find_set(i * n + j)]);
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!grid[i][j]){
                    vector<int> v;
                    int res = 1;
                    for(int k = 0; k < 4; k++){
                        int ii = i + dx[k], jj = j + dy[k];
                        if(check(ii, jj, n) && grid[ii][jj]){
                            bool ok = true;
                            for(int l = 0; l < v.size(); l++){
                                if(v[l] == find_set(ii * n + jj)) ok = false;
                            }
                            if(ok){
                                res += sz[find_set(ii * n + jj)];
                                v.push_back(find_set(ii * n + jj));
                            }
                        }
                    }
                    ans = max(ans, res);
                }
            }
        }
        return ans;
    }
};
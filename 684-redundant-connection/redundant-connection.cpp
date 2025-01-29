class Solution {
public:
    int parent[1001], sz[1001];
    int n = 0;
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1; // Ban đầu tập hợp chứa v có kích cỡ là 1
    }

    int find_set(int v) {
        return v == parent[v] ? v : parent[v] = find_set(parent[v]);
    }

    bool union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b); // Đặt biến a là gốc của cây có kích cỡ lớn hơn
            parent[b] = a;
            sz[a] += sz[b]; // Cập nhật kích cỡ của cây mới gộp lại
            return false;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); i++){
            make_set(edges[i][0]);
            make_set(edges[i][1]);
            n = max({n, edges[i][0], edges[i][1]});
        }
        int ans = -1;
        for(int i = 0; i < edges.size(); i++){
            if(union_sets(edges[i][0], edges[i][1])) ans = i;
        }
        return edges[ans];
    }
};
class Solution {
public:

    struct DSU {
         unordered_map<int, int> parent;
         unordered_map<int, int> sz;
         void make_set(int x) {
            parent[x] = x;
            sz[x] = 1;
         }

         int find(int x){
            return (x == parent[x]) ? x : parent[x] = find(parent[x]);
         }

         int unite(int u, int v) {
            u = find(u);
            v = find(v);
            if (u == v) return sz[u];
            if (sz[u] < sz[v]) swap(u, v);
            parent[v] = u;
            sz[u] += sz[v];
            return sz[u];
         }
    };

    int longestConsecutive(vector<int>& nums) {
        int ans = nums.size() > 0;
        DSU dsu;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i] + 1e9 + 1;
            if (dsu.parent[x] == 0) dsu.make_set(x);
            if (dsu.parent[x - 1] != 0) {
                ans = max(ans, dsu.unite(x, x - 1));
            }
            if (dsu.parent[x + 1] != 0) {
                ans = max(ans, dsu.unite(x, x + 1));
            }
        }
        return ans;
    }
};
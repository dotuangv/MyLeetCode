class DSU {
private:
    vector<int> parent, rank, cost;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        cost.resize(n, -1);
        for (int i = 0; i < n; i++) parent[i] = i;  // Ban đầu mỗi nút là cha của chính nó
    }

    int find(int u) {  // Tìm gốc của tập chứa u
        if (parent[u] != u) 
            parent[u] = find(parent[u]);  // Path Compression
        return parent[u];
    }

    void unionSet(int u, int v, int x) {  // Hợp nhất hai tập
        int rootU = find(u), rootV = find(v);
        if (rootU == rootV){
            if(cost[rootU] != -1) cost[rootU] &= x;
            else cost[rootU] = x;
            return;
        }
        if (rank[rootU] < rank[rootV])
            swap(rootU, rootV);
        parent[rootV] = rootU;
        if(cost[rootU] != -1) cost[rootU] &= x;
        else cost[rootU] = x;
        cost[rootU] &= cost[rootV];
        if (rank[rootU] == rank[rootV])
            rank[rootU]++;
        }


    bool sameSet(int u, int v) {
        return find(u) == find(v);
    }

    int getCost(int x){
        return cost[find(x)];
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        for(auto &x: edges){
            dsu.unionSet(x[0], x[1], x[2]);
        }
        vector<int> ans(query.size());
        for(int i = 0; i < query.size(); i++){
            if(dsu.sameSet(query[i][0], query[i][1])) ans[i] = dsu.getCost(query[i][0]);
            else ans[i] = -1;
        }
        return ans;
    }
};
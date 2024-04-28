class Solution {
    int head[30010], end[60010], next[60010], idx;
    int siz[30010], n;
    vector<int> ans;
    void add (int a, int b) {
        end[idx] = b, next[idx] = head[a], head[a] = idx++;
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        memset(head, -1, 4 * n + 4);
        for (auto &edge : edges) {
            int a = edge[0], b = edge[1];
            add(a, b), add(b, a);
        }
        this -> n = n;
        this -> ans = vector<int> (n);
        dfs(0, -1, 0);
        dfs(0, -1);
        return ans;
    }
    void dfs(int u, int pre, int level) {
        ans[0] += level;
        siz[u] = 1;
        for (int e = head[u]; ~e; e = next[e]) {
            int v = end[e];
            if ((e ^ 1) != pre) {
                dfs(v, e, level + 1);
                siz[u] += siz[v];
            }
        }
    }
    void dfs(int u, int pre) {
        for (int e = head[u]; ~e; e = next[e]) {
            if ((e ^ 1) == pre) continue;
            int v = end[e];
            ans[v] = ans[u] + n - 2 * siz[v];
            dfs(v, e);
        }
    }
};
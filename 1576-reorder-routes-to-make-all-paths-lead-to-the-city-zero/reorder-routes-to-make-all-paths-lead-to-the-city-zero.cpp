class Solution {
public:

    int ans = 0;
    void dfs(int i, vector<vector<pair<int, bool>>> &graph, vector<bool> &check)
    {
        check[i] = true;
        for(auto x: graph[i])
        {
            if(!check[x.first])
            {
                if(!x.second) ans++;
                dfs(x.first, graph, check);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> graph(n);
        for(auto x: connections)
        {
            graph[x[0]].push_back({x[1], false});
            graph[x[1]].push_back({x[0], true});
        }
        vector<bool> check(n);
        dfs(0, graph, check);
        return ans;

    }
};
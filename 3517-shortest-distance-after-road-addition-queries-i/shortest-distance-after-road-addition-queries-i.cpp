class Solution {
public:

    int bfs(int n, vector<set<int>> &graph, int k){
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<bool> check(n);
        while(!q.empty()){
            auto [x, y] = q.front();
            if(x == n - 1) return y;
            if(y > k) return k;
            check[x] = true;
            q.pop();
            for(auto p: graph[x]){
                if(!check[p]) q.push({p, y + 1});
            }
        }
        return n - 1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<set<int>> graph(n, set<int> ());
        for(int i = 1; i < n; i++) graph[i - 1].insert(i);

        vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); i++){
            graph[queries[i][0]].insert(queries[i][1]);
            if(i == 0) ans[i] = bfs(n, graph, n - 1);
            else ans[i] = bfs(n, graph, ans[i - 1]);
        }
        return ans;
    }
};
class Solution {
public:
    int ans = 0;
    long long dfs(int i, vector<vector<int>>& path, vector<int>& values, vector<bool> &visited, int k){
        if(visited[i]) return 0;
        visited[i] = true;
        long long sum = values[i];
        for(int j = 0; j < path[i].size(); j++){
            sum += dfs(path[i][j], path, values, visited, k);
        }
        if(sum % k == 0){
            ans++;
            return 0;
        }
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> path(n);
        for(int i = 0; i < edges.size(); i++){
            path[edges[i][0]].push_back(edges[i][1]);
            path[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n);
        dfs(0, path, values, visited, k);
        return ans;
    }
};
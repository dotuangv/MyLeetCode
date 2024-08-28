class Solution {
public:

    int ans = 0;
    void dfs(int i, vector<vector<int>> &graph, vector<int> &informTime, vector<bool> &visited, int res)
    {
        ans = max(ans, res);
        visited[i] = true;
        for(auto x: graph[i])
        {
            if(!visited[x])
            {
                dfs(x, graph, informTime, visited, res + informTime[i]);
            }
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n);
        for(int i = 0; i < n; i++)
        {
            if(manager[i] != -1) graph[manager[i]].push_back(i);
        }
        dfs(headID, graph, informTime, visited, 0);
        return ans;

    }
};
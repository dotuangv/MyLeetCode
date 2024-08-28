class Solution {
public:

    vector<vector<int>> ans;
    vector<int> res;
    void backtrack(int i, int n, vector<vector<int>> &graph, vector<bool> &visited)
    {
        if(i == n)
        {
            ans.push_back(res);
            return;
        }
        visited[i] = true;
        for(auto x: graph[i])
        {
            if(!visited[x])
            {
                res.push_back(x);
                backtrack(x, n, graph, visited);
                visited[x] = false;
                res.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n);
        res.push_back(0);
        backtrack(0, n - 1, graph, visited);
        return ans;
    }
};
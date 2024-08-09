class Solution {
public:
    void dfs(int i, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &safe)
    {
        visited[i] = true;
        bool ans = true;
        for(int j = 0; j < graph[i].size(); j++)
        {
            if(!visited[graph[i][j]])
                dfs(graph[i][j], graph, visited, safe);
            if(!safe[graph[i][j]]) ans = false;
        }
        safe[i] = ans;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size());
        vector<bool> safe(graph.size());
        vector<int> ans;
        for(int i = 0; i < graph.size(); i++)
        {
            if(graph[i].empty())
            {
                safe[i] = true;
                visited[i] = true;
            }
        }
        
        for(int i = 0; i < graph.size(); i++)
        {
            if(!visited[i])
            {
                dfs(i, graph, visited, safe);
            }
            if(safe[i]) ans.push_back(i);
        }
        
        return ans;

    }
};
class Solution {
public:
    bool dfs(string x, unordered_map<string, bool> &mp, unordered_map<string, bool> &check, unordered_map<string, vector<string>> &graph){
        bool ok = true;
        check[x] = true;
        for(auto &y: graph[x]){
            if(!check[y]) dfs(y, mp, check, graph);
            ok &= mp[y];
        }
        if(graph[x].empty()) ok = false;
        return mp[x] = ok;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, bool> mp, check;
        unordered_map<string, vector<string>> graph;
        for(int i = 0; i < recipes.size(); i++){
            for(auto &x: ingredients[i]){
                graph[recipes[i]].push_back(x);
            }
        }
        for(auto &x: supplies){
            mp[x] = true;
            check[x] = true;
        }
        vector<string> ans;
        for(auto &x: recipes){
            if(!check[x]) dfs(x, mp, check, graph);
            if(mp[x]) ans.push_back(x);
        }
        return ans;

    }
};
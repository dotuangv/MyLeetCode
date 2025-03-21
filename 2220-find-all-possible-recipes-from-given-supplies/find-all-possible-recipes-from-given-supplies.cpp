class Solution {
public:
    bool dfs(int x, vector<bool> &res, vector<bool> &check, vector<vector<int>> &graph){
        bool ok = true;
        check[x] = true;
        for(auto &y: graph[x]){
            if(!check[y]) dfs(y, res, check, graph);
            ok &= res[y];
        }
        if(graph[x].empty()) ok = false;
        return res[x] = ok;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> mp;
        int cnt = 1;
        for(int i = 0; i < recipes.size(); i++){
            if(!mp[recipes[i]]) mp[recipes[i]] = cnt++;
            for(auto &x: ingredients[i]){
                if(!mp[x]) mp[x] = cnt++;
            }
        }
        for(auto &x: supplies){
            if(!mp[x]) mp[x] = cnt++;
        }
        vector<vector<int>> graph(cnt);
        vector<bool> check(cnt), res(cnt);
        for(auto &x: supplies){
            check[mp[x]] = true;
            res[mp[x]] = true;
        }

        for(int i = 0; i < recipes.size(); i++){
            for(auto &x: ingredients[i]){
                graph[mp[recipes[i]]].push_back(mp[x]);
            }
        }

        vector<string> ans;
        for(auto &x: recipes){
            if(!check[mp[x]]) dfs(mp[x], res, check, graph);
            if(res[mp[x]]) ans.push_back(x);
        }
        return ans;

    }
};
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> ans(n);
        for(int i = 0; i < edges.size(); i++){
            ans[edges[i][1]] = true;
        }
        int result = -1;
        for(int i = 0; i < n; i++){
            if(!ans[i]){
                if(result == -1) result = i;
                else return -1;
            }
        }
        return result;

    }
};
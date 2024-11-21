class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m, vector<int> (n));
        for(auto x: guards){
            matrix[x[0]][x[1]] = 1;
        }
        for(auto x: walls){
            matrix[x[0]][x[1]] = 2;
        }
        for(int i = 0; i < m; i++){
            int l = 0;
            bool ok = false;
            for(int j = 0; j < n; j++){
                if(ok && !matrix[i][j]){
                    matrix[i][j] = 3;
                    l++;
                    continue;
                }
                if(matrix[i][j] == 1){
                    for(int k = l; k < j; k++){
                        if(!matrix[i][k]) matrix[i][k] = 3;
                    }
                    ok = true;
                    l = j + 1;
                }else if(matrix[i][j] == 2){
                    l = j + 1;
                    ok = false;
                }
            }
        }
        for(int j = 0; j < n; j++){
            int l = 0;
            bool ok = false;
            for(int i = 0; i < m; i++){
                if(ok && !matrix[i][j]){
                    matrix[i][j] = 3;
                    l++;
                    continue;
                }
                if(matrix[i][j] == 1){
                    for(int k = l; k < i; k++){
                        if(!matrix[k][j]) matrix[k][j] = 3;
                    }
                    l = i + 1;
                    ok = true;
                }else if(matrix[i][j] == 2){
                    l = i + 1;
                    ok = false;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!matrix[i][j]) ans++;
            }
        }
        return ans;

    }
};
class Solution {
public:

    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!matrix[i][j]) {
                    for(int l = 0; l < m; l++){
                        matrix[l][j] = !matrix[l][j];
                    }
                }
            }
            int res = 0;
            for(int j = 0; j < m; j++){
                bool ok = true;
                for(int l = 0; l < n; l++){
                    if(matrix[j][l] != matrix[j][0]){
                        ok = false;
                        break;
                    }
                }
                if(ok) res++;
            }
            
            ans = max(ans, res);
        }
        return ans;
    }
};
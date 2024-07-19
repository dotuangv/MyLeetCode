class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> maxCol(matrix[0].size());
        vector<int> minRow(matrix.size(), 1e9);
        vector<int> ans;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                minRow[i] = min(minRow[i], matrix[i][j]);
                maxCol[j] = max(maxCol[j], matrix[i][j]);
            }
        }
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                if(matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j]) ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};
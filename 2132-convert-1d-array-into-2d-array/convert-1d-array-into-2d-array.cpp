class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(n * m != original.size()) return {};
        vector<vector<int>> result(m, vector<int> (n));
        int row = 0;
        for(int i = 0; i < original.size(); i++)
        {
            row = i/n;
            result[row][i % n] = original[i];
        }
        return result;
    }
};
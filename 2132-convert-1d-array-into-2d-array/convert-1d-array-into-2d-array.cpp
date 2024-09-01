class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
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
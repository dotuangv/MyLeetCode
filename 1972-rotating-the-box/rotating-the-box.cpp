class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        for(int i = 0; i < box.size(); i++){
            for(int j = n - 1; j >= 0; j--){
                if(box[i][j] == '#'){
                    for(int k = j; k < n - 1; k++){
                        if(box[i][k + 1] == '.') swap(box[i][k], box[i][k + 1]);
                        else break;
                    }
                }
            }
        }
        vector<vector<char>> ans(n, vector<char> (m));
        for(int i = 0; i < n; i++){
            for(int j = m - 1; j >= 0; j--) ans[i][m - j - 1] = box[j][i];
        }
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
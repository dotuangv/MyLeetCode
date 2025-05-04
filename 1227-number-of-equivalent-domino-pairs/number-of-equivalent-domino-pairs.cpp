class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        for(int i = 1; i <= 9; i++){
            for(int j = i; j <= 9; j++){
                int res = 0;
                for(auto &x: dominoes){
                    if((x[0] == i && x[1] == j) || (x[0] == j && x[1] == i)) res++;
                }
                ans += (res - 1) * res / 2;
            }
        }
        return ans;
    }
};
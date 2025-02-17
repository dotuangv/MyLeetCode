class Solution {
public:
    int backtrack(int i, int n, vector<int> &vt){
        if(i == n){
            return 1;
        }
        int sum = 0;
        for(int j = 0; j < 26; j++){
            if(vt[j]){
                vt[j]--;
                sum += backtrack(i + 1, n, vt);
                vt[j]++;
            }
        }
        return sum;
    }
    int numTilePossibilities(string tiles) {
        vector<int> vt(26);
        for(auto x: tiles) vt[x - 'A']++;
        int ans = 0;
        for(int i = 1; i <= tiles.size(); i++){
            ans += backtrack(0, i, vt);
        }
        return ans;
    }
};
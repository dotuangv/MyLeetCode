class Solution {
public:
    vector<int> ans;
    void backtrack(int i, int n, bool &ok, vector<bool> &selected){
        while(i < 2 * n - 1 && ans[i] != -1) i++;
        if(i == 2 * n - 1){
            ok = true;
            return;
        }
        for(int j = n; j >= 1; j--){
            if(!selected[j]){
                if(j == 1){
                    ans[i] = 1;
                    selected[1] = true;
                    backtrack(i + 1, n, ok, selected);
                    if(ok) return;
                    selected[1] = false;
                    ans[i] = -1;
                }else if(i + j < 2*n - 1 && ans[i + j] == -1){
                    ans[i] = j;
                    ans[i + j] = j;
                    selected[j] = true;
                    backtrack(i + 1, n, ok, selected);
                    if(ok) return;
                    selected[j] = false;
                    ans[i] = -1;
                    ans[i + j] = -1;
                }
            }
        }
    }
    vector<int> constructDistancedSequence(int n) {
        vector<bool> selected(n + 1);
        ans.resize(2*n - 1, -1);
        bool ok = false;
        backtrack(0, n, ok, selected);
        return ans;
    }
};
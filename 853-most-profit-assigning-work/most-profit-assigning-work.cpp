class Solution {
public:
    int maxProfitAssignment(vector<int>& dif, vector<int>& pro, vector<int>& worker) {
        int MAX = worker[0];
        for(auto &x: worker) MAX = max(MAX, x);
        vector<int> Max(MAX + 1);
        for(int i = 0; i < dif.size(); i++)
        {
            if(dif[i] > MAX) continue;
            Max[dif[i]] = max(Max[dif[i]], pro[i]);
        }
        
        for(int i = 1; i <= MAX; i++)
        {
            Max[i]  = max(Max[i - 1], Max[i]);
        }
        int ans =  0;
        for(auto &x: worker) ans += Max[x];
        return ans;
    }
};
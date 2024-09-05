class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        mean = mean * (rolls.size() + n);
        int sum = 0;
        for(auto x: rolls) sum += x;
        double x = (mean - sum)*1.0/n;
        if(x > 6 || x < 1) return {};
        vector<int> ans(n);
        for(int i = 0; i < ans.size(); i++)
        {
            if((mean - sum) % n != 0)
            {
                ans[i] = x;
                mean -= ans[i];
                n--;
            }else
            {
                for(int j = i; j < ans.size(); j++) ans[j] = (mean - sum)/n;
                break;
            }
        }
        if((mean - sum) % n != 0) return {};
        return ans;
    }
};
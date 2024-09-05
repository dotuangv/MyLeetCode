class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        mean = mean * (rolls.size() + n);
        vector<int> ans(n);
        int sum = 0;
        for(auto x: rolls) sum += x;
        double x = (mean - sum)*1.0/n;
        // cout << x << "\n";
        if(x > 6 || x < 1) return {};
        for(int i = 0; i < ans.size(); i++)
        {
            if((mean - sum) % n != 0)
            {
                ans[i] = x;
                mean -= ans[i];
                n--;
            }else
            {
                // cout << mean << " " << sum << " " << n << "\n";
                for(int j = i; j < ans.size(); j++) ans[j] = (mean - sum)/n;
                break;
            }
        }
        if((mean - sum) % n != 0) return {};
        return ans;
    }
};
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return {};
        vector<pair<int, int>> pa;
        vector<int> ans(arr.size());
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++) pa.push_back({arr[i], i});
        sort(pa.begin(), pa.end());
        ans[pa[0].second] = ++cnt;
        for(int i = 1; i < ans.size(); i++)
        {
            if(pa[i].first != pa[i - 1].first) ans[pa[i].second] = ++cnt;
            else ans[pa[i].second] = ans[pa[i - 1].second]; 
        }
        return ans;
    }
};
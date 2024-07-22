class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, int>> pa;
        vector<string> ans(names.size());
        for(int i = 0; i < heights.size(); i++) pa.push_back({heights[i], i});
        sort(pa.begin(), pa.end(), greater<pair<int, int>> ());
        for(int i = 0; i < pa.size(); i++) ans[i] = names[pa[i].second];
        return ans;
    }
};
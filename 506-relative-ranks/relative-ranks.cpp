class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> pa;
        for(int i = 0; i < score.size(); i++)
        {
            pa.push_back({score[i], i});
        }
        sort(pa.begin(), pa.end(), greater<pair<int, int>> ());
        vector<string> ans(score.size());
        vector<string> t = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for(int i = 0; i < min(3, (int)score.size()); i++)
        {
            ans[pa[i].second] = t[i];
        }
        for(int i = 3; i < score.size(); i++)
        {
            ans[pa[i].second] = to_string(i + 1);
        }
        return ans;
    }
};
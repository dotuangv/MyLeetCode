class Solution {
public:

    int BinarySearch(int x, vector<pair<pair<int, int>, int>> &pa)
    {
        int l = 0, r = pa.size() - 1;
        while(r > l + 1)
        {
            int mid = (l + r)/2;
            if(pa[mid].first.first >= x) r = mid;
            else l = mid;
        }
        if(pa[l].first.first >= x) return pa[l].second;
        else if(pa[r].first.first >= x) return pa[r].second;
        else return -1;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<pair<int, int>, int>> pa;
        for(int i = 0; i < intervals.size(); i++)
        {
            pa.push_back(make_pair(make_pair(intervals[i][0], intervals[i][1]), i));
        }

        sort(pa.begin(), pa.end());
        vector<int> ans(intervals.size());
        for(auto &x: pa)
        {
            ans[x.second] = BinarySearch(x.first.second, pa);
        }
        return ans;
    }
};
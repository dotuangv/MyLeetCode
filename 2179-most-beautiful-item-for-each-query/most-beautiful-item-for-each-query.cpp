class Solution {
public:
    int Search(int x, vector<vector<int>> &items){
        int l = 0, r = items.size() - 1;
        while(r > l + 1){
            int mid = (l + r)/2;
            if(items[mid][0] <= x) l = mid;
            else r = mid;
        }
        if(items[r][0] <= x) return items[r][1];
        if(items[l][0] <= x) return items[l][1];
        return 0;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        for(int i = 1; i < items.size(); i++){
            items[i][1] = max(items[i - 1][1], items[i][1]);
        }
        vector<int> ans;
        for(auto &x: queries){
            ans.push_back(Search(x, items));
        }
        return ans;
    }
};
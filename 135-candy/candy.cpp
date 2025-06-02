class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        vector<pair<int, int>> p;
        for(int i = 0; i < n; i++){
            p.push_back(make_pair(ratings[i], i));
        }
        sort(p.begin(), p.end());
        int ans = 1;
        for(int i = 1; i < n; i++){
            auto [x, y] = p[i];
            if(y - 1 >= 0 && x > ratings[y - 1]){
                candies[y] = max(candies[y], candies[y - 1] + 1);
            }
            if(y + 1 < n && x > ratings[y + 1]){
                candies[y] = max(candies[y], candies[y + 1] + 1);
            }
            ans += candies[y];
        }
        return ans;
    }
};
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0, n = colors.size();
        for(int i = 0; i < n; i++) colors.push_back(colors[i]);
        int l = 0, r = 1;
        while(r < n + k - 1){
            if(colors[r] == !colors[r - 1]){
                r++;
            }else{
                l = r;
                r++;
            }
            if(r - l == k){
                ans++;
                l++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> resultsArray(vector<int>& a, int k) {
        if(k == 1) return a;
        vector<int> ans(a.size() - k + 1, -1);
        int l = 0, r = 1;
        while(r < a.size()){
            if(a[r] == a[r - 1] + 1) {
                if(r - l + 1 == k){
                    ans[l] = a[r];
                    l++;
                }
                r++;
            }else{
                l = r;
                r++;
            }
        }
        return ans;
    }
};
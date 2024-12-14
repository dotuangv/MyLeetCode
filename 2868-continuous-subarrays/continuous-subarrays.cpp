class Solution {
public:
    int LG = 16, N = 100005;
    int Min[17][100005];
    int Max[17][100005];
    int n;
    void preprocess(vector<int> &a) {
        for (int i = 1; i <= n; ++i) {
            Min[0][i] = a[i - 1];
            Max[0][i] = a[i - 1];
        }
        for (int j = 1; j <= LG; ++j)
            for (int i = 1; i + (1 << j) - 1 <= n; ++i){
                Min[j][i] = min(Min[j - 1][i], Min[j - 1][i + (1 << (j - 1))]);
                Max[j][i] = max(Max[j - 1][i], Max[j - 1][i + (1 << (j - 1))]);
            }
    }
    int queryMin(int l, int r) {
        int k = __lg(r - l + 1);
        return min(Min[k][l], Min[k][r - (1 << k) + 1]);
    }

    int queryMax(int l, int r) {
        int k = __lg(r - l + 1);
        return max(Max[k][l], Max[k][r - (1 << k) + 1]);
    }

    long long continuousSubarrays(vector<int>& nums) {
        n = nums.size();
        preprocess(nums);
        long long l = 0, r = 0;
        long long ans = 0;
        while(r < n){
            if(queryMax(l + 1, r + 1) - queryMin(l + 1, r + 1) > 2){
                while(queryMax(l + 1, r + 1) - queryMin(l + 1, r + 1) > 2){
                    ans += r - l;
                    l++;
                }
            }else r++;
        }
        ans += (r - l) * (r - l + 1)/2;
        return ans;
    }
};
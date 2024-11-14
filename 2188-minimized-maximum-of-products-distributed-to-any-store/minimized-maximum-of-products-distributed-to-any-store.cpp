class Solution {
public:

    bool isGood(int x, int n, vector<int> &q){
        int res = 0;
        for(int i = 0; i < q.size(); i++){
            res += q[i]/x + (q[i]%x != 0);
        }
        return res <= n;
    }

    int minimizedMaximum(int n, vector<int>& q) {
        int l = 1, r = 1;
        for(int i=0;i<q.size();i++) {
            r = max(r, q[i]);
        }
        while(r > l + 1){
            int mid = (l + r)/2;
            if(isGood(mid, n, q)) r = mid;
            else l = mid;
        }
        if(isGood(l, n, q)) return l;
        return r;
    }
};
class Solution {
public:

    bool isGood(int x, int n, vector<int> q){
        int i = 0, j = 0;
        while(j < n){
            if(q[i] == 0) i++;
            if(i == q.size()) return true;
            q[i] = max(0, q[i] - x);
            j++;
        }
        return q.back() == 0;
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
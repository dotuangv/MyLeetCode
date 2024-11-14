class Solution {
public:

    bool isGood(int x, int n, vector<int> quantities){
        int i = 0, j = 0;
        while(j < n){
            if(quantities[i] == 0) i++;
            if(i == quantities.size()) return true;
            quantities[i] = max(0, quantities[i] - x);
            j++;
        }
        return quantities.back() == 0;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 0, r = 100000;
        while(r > l + 1){
            int mid = (l + r)/2;
            if(isGood(mid, n, quantities)) r = mid;
            else l = mid;
        }
        if(isGood(l, n, quantities)) return l;
        return r;
    }
};
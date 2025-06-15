class Solution {
public:
    int cal(vector<int> &vt, int x, bool check = false){
        int ans = 0, res = pow(10, vt.size() - 1);
        int j = vt.size() - 1;
        if(check){
            ans += vt[j] * res;
            res /= 10;
            j--;
        }
        for(int i = j; i >= 0; i--) {
            if(vt[i] != x && (x != 0 || vt[i] != vt.back())) {
                for(int j = i; j >= 0; j--){
                    if(vt[j] == vt[i]) {
                        ans += x * res;
                    }else ans += vt[j] * res;
                    res /= 10;
                }
                break;
            }else {
                ans += vt[i] * res;
                res /= 10;
            }
        }
        return ans;
    }
    int maxDiff(int num) {
        vector<int> vt;
        int x = num;
        while(num){
            vt.push_back(num%10);
            num /= 10;
        }
        if(cal(vt, 0) != 0) return cal(vt, 9) - min(cal(vt, 0, true), cal(vt, 1));
        return cal(vt, 9) - min(cal(vt, 1), x);
    }
};
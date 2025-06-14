class Solution {
public:

    int cal(vector<int> &vt, int x){
        int ans = 0, res = pow(10, vt.size() - 1);
        for(int i = vt.size() - 1; i >= 0; i--) {
            if(vt[i] != x) {
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

    int minMaxDifference(int num) {
        vector<int> vt;
        while(num){
            vt.push_back(num%10);
            num /= 10;
        }
        return cal(vt, 9) - cal(vt, 0);
        
    }
};
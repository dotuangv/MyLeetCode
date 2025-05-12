class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> vt(10), ans;
        for(auto &x: digits) vt[x]++;
        for(int i = 100; i <= 998; i += 2){
            vector<int> v(10);
            int x = i;
            while(x){
                v[x % 10]++;
                x /= 10;
            }
            bool ok = true;
            for(int j = 0; j < 10; j++){
                if(v[j] > vt[j]) ok = false;
            }
            if(ok) ans.push_back(i);
        }
        return ans;
    }
};
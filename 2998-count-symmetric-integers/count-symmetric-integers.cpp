class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; i++){
            if((int)log10(i) % 2){
                vector<int> v;
                int x = i;
                while(x){
                    v.push_back(x % 10);
                    x /= 10;
                }
                int s1 = 0, s2 = 0;
                for(int j = 0; j < v.size(); j++){
                    if(j < v.size() / 2) s1 += v[j];
                    else s2 += v[j];
                }
                if(s1 == s2) ans++;
            }
        }
        return ans;
    }
};
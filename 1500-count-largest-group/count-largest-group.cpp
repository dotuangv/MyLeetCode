class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        for(int i = 1; i <= n; i++){
            int x = i, res = 0;
            while(x){
                res += (x % 10);
                x /= 10;
            }
            mp[res]++;
        }
        int ans = 0, tmp = 1;
        for(auto [x, y]: mp){
            if(y > tmp){
                tmp = y;
                ans = 1;
            }else if(y == tmp)
                ans++;
        }
        return ans;
    }
};
class Solution {
public:
    int findComplement(int num) {
        vector<int> vt;
        while(num)
        {
            vt.push_back(num%2);
            num/=2;
        }
        long long ans = 0, i = 1;
        for(auto x: vt)
        {
            ans += i * ((x + 1) % 2);
            i *= 2;
        }
        return ans;
    }
};
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto &x: details)
            if((x[11] - '0')*10 + x[12] - '0' > 60) ans++;
        return ans;
    }
};
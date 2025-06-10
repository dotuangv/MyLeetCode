class Solution {
public:
    int maxDifference(string s) {
        vector<int> vt(26);
        for(auto &x: s) vt[x - 'a']++;
        int Max = 0, Min = -1;
        for(int i = 0; i < 26; i++){
            if(vt[i] % 2 == 1) Max = max(Max, vt[i]);
            else if(vt[i] != 0){
                if(Min == -1) Min = vt[i];
                else Min = min(Min, vt[i]);
            }
        }
        return Max - Min;
    }
};
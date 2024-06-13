class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        vector<int> vt1(101), vt2(101);
        for(auto &x: seats) vt1[x]++;
        for(auto &x: students) vt2[x]++;
        int i = 1, j = 1, ans = 0;
        while(1)
        {
            while(i <= 100 && vt1[i] == 0) i++;
            while(j <= 100 && vt2[j] == 0) j++;
            if(i > 100 && j > 100) return ans;
            if(vt1[i] >= vt2[j])
            {
                ans += vt2[j]*abs(i - j);
                vt1[i] -= vt2[j];
                vt2[j] = 0;
            }else
            {
                ans += vt1[i]*abs(i - j);
                vt2[j] -= vt1[i];
                vt1[i] = 0;
            }
        }
        return ans;
    }
};
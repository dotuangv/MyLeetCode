class Solution {
public:
    int maximum69Number (int num) {
        vector<int> vt;
        while(num) {
            vt.push_back(num % 10);
            num /= 10;
        }
        for (int i = vt.size() - 1; i >= 0; i--) {
            if(vt[i] == 6){
                vt[i] = 9;
                break;
            }
        }
        int new_num = 0;
        for (int i = vt.size() - 1; i >= 0; i--) {
            new_num = vt[i] + new_num * 10;
        }
        return new_num;
    }
};
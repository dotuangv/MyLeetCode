class Solution {
public:
    vector<int> Calc_D_odd(string S) {
        int N = S.size();
        vector<int> D_odd(N + 2);
        int L = 1;
        int R = 0;
        for(int i = 1 ; i <= N ; i++) {
            if(i > R) D_odd[i] = 0;
            else D_odd[i] = min(R - i, D_odd[L + (R - i)]);
            while(i - D_odd[i] - 1 > 0 && i + D_odd[i] + 1 <= N && S[i - D_odd[i] - 1] == S[i + D_odd[i] + 1]) {
                D_odd[i]++;
            }
    
            if(i + D_odd[i] > R) {
                R = i + D_odd[i];
                L = i - D_odd[i];
            }
        }
        return D_odd;
    }
 
    vector<int> Calc_D_even(string S) {
        int N = S.size();
        vector<int> D_even(N + 2);
        int L = 1;
        int R = 0;
        for(int i = 1 ; i < N ; i++) {
            int j = i + 1;
            if(j > R) D_even[i] = 0;
            else D_even[i] = min(R - j + 1, D_even[L + (R - j)]);
            while(i - D_even[i] > 0 && j + D_even[i] <= N && S[i - D_even[i]] == S[j + D_even[i]]) {
                D_even[i]++;
            }
            if(i + D_even[i] > R) {
                R = i + D_even[i];
                L = j - D_even[i];
            }
        }
        return D_even;
    }

    int countSubstrings(string S) {
        int N = S.size();
        S = ' ' + S;
        vector<int> D_odd = Calc_D_odd(S);
        vector<int> D_even = Calc_D_even(S);
        int ans = 0;
        for(int i = 1; i < N; i++)
        {
            ans += D_odd[i] + 1 + D_even[i];
        }
        return ans + D_odd[N] + 1;

    }
};
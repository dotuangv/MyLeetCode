class Solution {
public:

    void update(int &a, int &b, int &c, char ch, int i, vector<int> &A, vector<int> &B, vector<int> &C){
        if(ch == 'a') {
            a++;
            A[a] = i;
        }else if(ch == 'b') {
            b++;
            B[b] = i;
        }else if(ch == 'c') {
            c++;
            C[c] = i;
        }
    }

    void update2(int &a, int &b, int &c, char ch){
        if(ch == 'a') {
            a++;
        }else if(ch == 'b') {
            b++;
        }else if(ch == 'c') {
            c++;
        }
    }

    int takeCharacters(string s, int k) {
        if(k == 0) return 0;
        int n = s.size();
        vector<int> A(n + 1), B(n + 1), C(n + 1);
        int ans = 1e9;
        int a = 0, b = 0, c = 0;
        for(int i = 0; i < n; i++){
            update(a, b, c, s[i], i + 1, A, B, C);
            if(a >= k && b >= k && c >= k) ans = min(ans, i + 1);
        }
        if(ans == 1e9) return -1;
        a = 0, b = 0, c = 0;
        for(int i = n - 1; i >= 0; i--){
            update2(a, b, c, s[i]);
            int x = max(0, k - a), y = max(0, k - b), z = max(0, k - c);
            int j = max({A[x], B[y], C[z]});
            ans = min(ans, n - i + j);
        }
        return ans;


    }
};
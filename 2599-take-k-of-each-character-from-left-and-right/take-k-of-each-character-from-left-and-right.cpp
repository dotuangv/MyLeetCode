class Solution {
public:

    void update(int &a, int &b, int &c, char ch){
        if(ch == 'a') a++;
        else if(ch == 'b') b++;
        else if(ch == 'c') c++;
    }

    int BS(int x, int j, vector<int> &vt){
        int l = j, r = vt.size() - 1;
        while(r > l + 1){
            int mid = (l + r)/2;
            if(vt[mid] >= x) r = mid;
            else l = mid;
        }
        if(vt[l] >= x) return l;
        return r;
    }

    int takeCharacters(string s, int k) {
        if(k == 0) return 0;
        int n = s.size();
        vector<int> a(n), b(n), c(n);
        int ans = 1e9;
        update(a[0], b[0], c[0], s[0]);
        for(int i = 1; i < n; i++){
            a[i] = a[i - 1];
            b[i] = b[i - 1];
            c[i] = c[i - 1];
            update(a[i], b[i], c[i], s[i]);
            if(a[i] >= k && b[i] >= k && c[i] >= k) ans = min(ans, i + 1);
        }
        if(ans == 1e9) return -1;
        int A = 0, B = 0, C = 0;
        for(int i = n - 1; i >= 0; i--){
            update(A, B, C, s[i]);
            int x = max(0, k - A), y = max(0, k - B), z = max(0, k - C);
            if(x == 0 && y == 0 && z == 0) ans = min(ans, n - i);
            int j = BS(x, 0, a);
            j = BS(y, j, b);
            j = BS(z, j, c);
            ans = min(ans, j + 1 + n - i);
        }
        return ans;


    }
};